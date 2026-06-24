from flask import Flask, request, jsonify
import sqlite3
import paho.mqtt.client as mqtt

app = Flask(__name__)
DB_NAME = "fitness_tracker.db"
MQTT_BROKER = "://hivemq.com"
MQTT_TOPIC = "health/status"

# --- HELPER FUNCTIONS ---
def init_db():
    conn = sqlite3.connect(DB_NAME)
    cursor = conn.cursor()
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            age INTEGER,
            city TEXT,
            steps INTEGER,
            pulse INTEGER,
            oxygen INTEGER,
            temperature REAL
        )
    ''')
    conn.commit()
    conn.close()

def log_to_mqtt(method_name, status):
    try:
        client = mqtt.Client()
        client.connect(MQTT_BROKER, 1883, 60)
        message = f"Method: {method_name} | Status: {status}"
        client.publish(MQTT_TOPIC, message)
        client.disconnect()
    except Exception as e:
        print(f"Failed to publish to MQTT: {e}")

# --- ROUTES ---

@app.route('/add', methods=['POST'])
def add_user():
    try:
        data = request.json
        conn = sqlite3.connect(DB_NAME)
        cursor = conn.cursor()
        cursor.execute('''
            INSERT INTO users (name, age, city, steps, pulse, oxygen, temperature)
            VALUES (?, ?, ?, ?, ?, ?, ?)
        ''', (data['name'], data['age'], data['city'], data['steps'], data['pulse'], data['oxygen'], data['temperature']))
        conn.commit()
        conn.close()
        
        log_to_mqtt("/add", "success")
        return jsonify({"status": "success", "message": "User added successfully"}), 201
    except Exception as e:
        log_to_mqtt("/add", "failure")
        return jsonify({"status": "failure", "error": str(e)}), 400

@app.route('/all', methods=['GET'])
def get_all_users():
    try:
        conn = sqlite3.connect(DB_NAME)
        conn.row_factory = sqlite3.Row
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM users")
        rows = cursor.fetchall()
        conn.close()
        
        users = [dict(row) for row in rows]
        log_to_mqtt("/all", "success")
        return jsonify(users), 200
    except Exception as e:
        log_to_mqtt("/all", "failure")
        return jsonify({"status": "failure", "error": str(e)}), 500

@app.route('/info', methods=['GET'])
def get_single_user():
    try:
        user_id = request.args.get('id')
        conn = sqlite3.connect(DB_NAME)
        conn.row_factory = sqlite3.Row
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM users WHERE id = ?", (user_id,))
        row = cursor.fetchone()
        conn.close()
        
        if row:
            log_to_mqtt("/info", "success")
            return jsonify(dict(row)), 200
        else:
            log_to_mqtt("/info", "failure")
            return jsonify({"status": "failure", "message": "User not found"}), 404
    except Exception as e:
        log_to_mqtt("/info", "failure")
        return jsonify({"status": "failure", "error": str(e)}), 500

@app.route('/update', methods=['PUT'])
def update_city():
    try:
        data = request.json
        user_id = data['id']
        new_city = data['city']
        
        conn = sqlite3.connect(DB_NAME)
        cursor = conn.cursor()
        cursor.execute("UPDATE users SET city = ? WHERE id = ?", (new_city, user_id))
        conn.commit()
        updated_rows = cursor.rowcount
        conn.close()
        
        if updated_rows > 0:
            log_to_mqtt("/update", "success")
            return jsonify({"status": "success", "message": "City updated"}), 200
        else:
            log_to_mqtt("/update", "failure")
            return jsonify({"status": "failure", "message": "User not found"}), 404
    except Exception as e:
        log_to_mqtt("/update", "failure")
        return jsonify({"status": "failure", "error": str(e)}), 400

@app.route('/steps', methods=['GET'])
def get_max_steps():
    try:
        conn = sqlite3.connect(DB_NAME)
        conn.row_factory = sqlite3.Row
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM users ORDER BY steps DESC LIMIT 1")
        row = cursor.fetchone()
        conn.close()
        
        if row:
            log_to_mqtt("/steps", "success")
            return jsonify(dict(row)), 200
        else:
            log_to_mqtt("/steps", "failure")
            return jsonify({"status": "failure", "message": "No data found"}), 404
    except Exception as e:
        log_to_mqtt("/steps", "failure")
        return jsonify({"status": "failure", "error": str(e)}), 500

if __name__ == '__main__':
    init_db()
    app.run(debug=True, port=5000)
