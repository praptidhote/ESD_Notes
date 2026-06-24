from flask import Flask, request, jsonify, render_template_string
from flask_sqlalchemy import SQLAlchemy
from datetime import datetime

app = Flask(__name__)
# Configure local SQLite database
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///smart_home.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)

# Database Model
class HomeStatus(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    light_status = db.Column(db.String(10), nullable=False) # "ON" or "OFF"
    fan_status = db.Column(db.String(10), nullable=False)   # "ON" or "OFF"
    temperature = db.Column(db.Float, nullable=False)
    timestamp = db.Column(db.DateTime, default=datetime.utcnow)

# Initialize database tables
with app.app_context():
    db.create_all()

@app.route('/update', methods=['POST'])
def update_status():
    """Accepts JSON data to update smart home state."""
    data = request.get_json()
    if not data:
        return jsonify({"error": "Missing payload"}), 400
    
    try:
        new_entry = HomeStatus(
            light_status=data['light_status'],
            fan_status=data['fan_status'],
            temperature=float(data['temperature'])
        )
        db.session.add(new_entry)
        db.session.commit()
        return jsonify({"message": "Status updated successfully"}), 200
    except KeyError as e:
        return jsonify({"error": f"Missing required field: {str(e)}"}), 400

@app.route('/status', methods=['GET'])
def get_status():
    """Browser route to fetch the latest device statuses and temperature."""
    latest = HomeStatus.query.order_by(HomeStatus.timestamp.desc()).first()
    
    if not latest:
        return "<h3>No status data available yet.</h3>"
    
    html_template = """
    <html>
        <head><title>Home Status</title></head>
        <body>
            <h1>Smart Home Dashboard</h1>
            <p><strong>Light Status:</strong> {{ data.light_status }}</p>
            <p><strong>Fan Status:</strong> {{ data.fan_status }}</p>
            <p><strong>Current Temperature:</strong> {{ data.temperature }} °C</p>
            <p><small>Last Updated: {{ data.timestamp }}</small></p>
        </body>
    </html>
    """
    return render_template_string(html_template, data=latest)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5001, debug=True)
