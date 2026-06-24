import sqlite3
import time
import random
import paho.mqtt.client as mqtt

# --- DATABASE SETUP ---
DB_NAME = "smarthome.db"

def init_db():
    conn = sqlite3.connect(DB_NAME)
    cursor = conn.cursor()
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS sensor_data (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            topic TEXT,
            value REAL,
            timestamp DATETIME DEFAULT CURRENT_TIMESTAMP
        )
    ''')
    conn.commit()
    conn.close()

# --- MQTT SUBSCRIBER CALLBACKS ---
def on_connect(client, userdata, flags, rc):
    print(connected_with_result_code(rc))
    client.subscribe("sensor/ldr")
    client.subscribe("sensor/lm35")

def on_message(client, userdata, msg):
    payload = float(msg.payload.decode())
    print(received(msg.topic, payload))
    
    # Insert into database
    conn = sqlite3.connect(DB_NAME)
    cursor = conn.cursor()
    cursor.execute("INSERT INTO sensor_data (topic, value) VALUES (?, ?)", (msg.topic, payload))
    conn.commit()
    conn.close()

# --- MAIN EXECUTION ---
if __name__ == "__main__":
    init_db()
    
    # Initialize MQTT Client
    client = mqtt.Client()
    client.on_connect = on_connect
    client.on_message = on_message
    
    # Connect to public broker (Change to your local broker IP if needed)
    client.connect("://hivemq.com", 1883, 60)
    
    # Start loop in a non-blocking background thread
    client.loop_start()
    
    print("MQTT Client started. Publishing simulated data every 5 seconds...")
    try:
        while True:
            # Simulate data
            ldr_val = random.randint(200, 800)        # Light intensity
            lm35_val = round(random.uniform(22.0, 35.0), 2) # Temperature
            
            # Publish data
            client.publish("sensor/ldr", ldr_val)
            client.publish("sensor/lm35", lm35_val)
            
            time.sleep(5)
    except KeyboardInterrupt:
        print("Stopping client...")
        client.loop_stop()
        client.disconnect()
