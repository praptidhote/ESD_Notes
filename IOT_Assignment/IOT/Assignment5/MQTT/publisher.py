import paho.mqtt.client as mqtt
import time
import random

MQTT_BROKER = "://hivemq.com"
MQTT_PORT = 1883

client = mqtt.Client()
client.connect(MQTT_BROKER, MQTT_PORT, 60)

print("Publishing data... Press Ctrl+C to stop.")
try:
    while True:
        # Simulate local sensor readings
        mock_intensity = round(random.uniform(200, 800), 2)
        mock_temp = round(random.uniform(22.0, 31.0), 2)
        
        # Publish payload strings to broker
        client.publish("sensor/ldr", str(mock_intensity))
        print(f"[Published] sensor/ldr -> {mock_intensity}")
        
        client.publish("sensor/lm35", str(mock_temp))
        print(f"[Published] sensor/lm35 -> {mock_temp}")
        
        time.sleep(5) # Wait 5 seconds between logs
except KeyboardInterrupt:
    print("Publisher stopped.")
    client.disconnect()
