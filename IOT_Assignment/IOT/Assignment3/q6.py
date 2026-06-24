import mysql.connector
from datetime import datetime

# Connect to MySQL Server
conn = mysql.connector.connect(host="localhost", user="root", password="password")
cursor = conn.cursor()

# Create Database and Table
cursor.execute("CREATE DATABASE IF NOT EXISTS iot_data")
cursor.execute("USE iot_data")
cursor.execute("""
    CREATE TABLE IF NOT EXISTS sensor_readings (
        id INT AUTO_INCREMENT PRIMARY KEY,
        temperature FLOAT,
        humidity FLOAT,
        timestamp DATETIME
    )
""")

# Insert Data
insert_query = "INSERT INTO sensor_readings (temperature, humidity, timestamp) VALUES (%s, %s, %s)"
readings = [
    (23.5, 55.0, datetime.now()),
    (19.2, 60.5, datetime.now()),
    (25.1, 48.2, datetime.now())
]
cursor.executemany(insert_query, readings)
conn.commit()

# Retrieve below threshold (Example: Temperature below 20.0)
threshold = 20.0
cursor.execute("SELECT * FROM sensor_readings WHERE temperature < %s", (threshold,))
print(f"Readings where Temperature < {threshold}:")
for row in cursor.fetchall():
    print(row)

conn.close()
