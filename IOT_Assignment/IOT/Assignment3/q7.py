import mysql.connector
from datetime import datetime

# Connect to MySQL Server
conn = mysql.connector.connect(host="localhost", user="root", password="password")
cursor = conn.cursor()

# Create Database and Table
cursor.execute("CREATE DATABASE IF NOT EXISTS smart_agri")
cursor.execute("USE smart_agri")
cursor.execute("""
    CREATE TABLE IF NOT EXISTS soil_moisture_data (
        sensor_id VARCHAR(50),
        moisture_level FLOAT,
        date_and_time DATETIME
    )
""")

# Insert Data
insert_query = "INSERT INTO soil_moisture_data (sensor_id, moisture_level, date_and_time) VALUES (%s, %s, %s)"
agri_readings = [
    ("SENSOR_01", 35.5, datetime.now()),
    ("SENSOR_02", 18.2, datetime.now()),
    ("SENSOR_03", 42.0, datetime.now())
]
cursor.executemany(insert_query, agri_readings)
conn.commit()

# Retrieve below threshold (Example: Moisture below 20%)
moisture_threshold = 20.0
cursor.execute("SELECT * FROM soil_moisture_data WHERE moisture_level < %s", (moisture_threshold,))
print(f"Critical Dry Soil Records (Moisture < {moisture_threshold}%):")
for row in cursor.fetchall():
    print(row)

conn.close()
