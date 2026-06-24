from flask import Flask, request, jsonify, render_template_string
import os

app = Flask(__name__)

# File paths for storage
TEMP_FILE = "temperature_data.txt"
LIGHT_FILE = "light_data.txt"

def append_to_file(file_path, value):
    """Helper function to append data to a file."""
    with open(file_path, "a") as f:
        f.write(f"{value}\n")

def read_last_line(file_path):
    """Helper function to read the last entry from a file."""
    if not os.path.exists(file_path) or os.stat(file_path).st_size == 0:
        return "No data recorded yet"
    with open(file_path, "r") as f:
        lines = f.readlines()
        return lines[-1].strip()

@app.route('/update', methods=['POST'])
def update_readings():
    """Client endpoints to send data via JSON."""
    data = request.get_json()
    if not data:
        return jsonify({"error": "Invalid JSON data"}), 400
    
    temperature = data.get('temperature')
    light = data.get('light')
    
    if temperature is not None:
        append_to_file(TEMP_FILE, temperature)
    if light is not None:
        append_to_file(LIGHT_FILE, light)
        
    return jsonify({"message": "Data recorded successfully"}), 200

@app.route('/view', methods=['GET'])
def view_readings():
    """Web service to view the latest readings in a browser."""
    latest_temp = read_last_line(TEMP_FILE)
    latest_light = read_last_line(LIGHT_FILE)
    
    html_template = """
    <html>
        <head><title>IoT Readings</title></head>
        <body>
            <h1>Latest Sensor Readings</h1>
            <p><strong>Temperature:</strong> {{ temp }}</p>
            <p><strong>Light Intensity:</strong> {{ light }}</p>
        </body>
    </html>
    """
    return render_template_string(html_template, temp=latest_temp, light=latest_light)

if __name__ == '__main__':
    # Run server on port 5000
    app.run(host='0.0.0.0', port=5000, debug=True)
