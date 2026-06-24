import paho.mqtt.client as mqtt
import sqlite3
from datetime import datetime

DB_NAME = "mqtt_smart_home.db"
MQTT_BROKER = "://hivemq.com"  # Public test broker
MQTT_PORT = 1883

def init_db():
    """Initializes the SQLite database schema."""
    conn = sqlite3.connect(DB_NAME)
    cursor = conn.cursor()
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS sensor_logs (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            topic TEXT,
            value REAL,
            timestamp TEXT
        )
    ''')
    conn.commit()
    conn.close()

def save_to_db(topic, value):
    """Inserts received MQTT payload into the local database."""
    try:
        conn = sqlite3.connect(DB_NAME)
        cursor = conn.cursor()
        cursor.execute(
            "INSERT INTO sensor_logs (topic, value, timestamp) VALUES (?, ?, ?)",
            (topic, float(value), datetime.now().isoformat())
        )
        conn.commit()
        conn.close()
        print(f"[DB Logged] Saved {value} from {topic}")
    except ValueError:
        print(f"[DB Error] Could not convert payload '{value}' to float")

# MQTT Event Callbacks
def on_connect(client, userdata, flags, rc):
    print(f"Connected to MQTT broker with result code {rc}")
    # Subscribe to both specified topics
    client.subscribe("sensor/ldr")
    client.subscribe("sensor/lm35")
    print("Subscribed to 'sensor/ldr' and 'sensor/lm35'")

def on_message(client, userdata, msg):
    payload = msg.payload.decode('utf-8')
    print(f"[Received] {msg.topic}: {payload}")
    save_to_db(msg.topic, payload)

if __name__ == "__main__":
    init_db()
    
    client = mqtt.Client()
    client.on_connect = on_connect
    client.on_message = on_message
    
    print("Connecting to broker...")
    client.connect(MQTT_BROKER, MQTT_PORT, 60)
    
    # Keeps the script running to block and listen for data
    client.loop_forever()
