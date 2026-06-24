const express = require('express');
const mqtt = require('mqtt');
const sqlite3 = require('sqlite3').verbose();
const path = require('path');

const app = express();
app.use(express.json());

const PORT = 3000;
const MQTT_BROKER = 'mqtt://://hivemq.com'; // Public broker for testing

// ==========================================
// 1. DATABASE & TABLES INITIALIZATION
// ==========================================
const db = new sqlite3.Database('./smarthome_fitness.db', (err) => {
    if (err) console.error('Database connection error:', err.message);
    else console.log('Connected to SQLite database.');
});

db.serialize(() => {
    // Smart Home Sensor Table
    db.run(`CREATE TABLE IF NOT EXISTS home_sensors (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        topic TEXT,
        value REAL,
        timestamp DATETIME DEFAULT CURRENT_TIMESTAMP
    )`);

    // Fitness Tracker Users Table
    db.run(`CREATE TABLE IF NOT EXISTS fitness_users (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT UNIQUE,
        age INTEGER,
        city TEXT,
        steps INTEGER,
        pulse INTEGER,
        spo2 REAL,
        temperature REAL
    )`);
});

// ==========================================
// 2. MQTT CLIENT & SUBSCRIBER
// ==========================================
const mqttClient = mqtt.connect(MQTT_BROKER);

mqttClient.on('connect', () => {
    console.log('Connected to MQTT Broker.');
    // Subscribe to Smart Home Sensor topics
    mqttClient.subscribe(['sensor/ldr', 'sensor/lm35'], (err) => {
        if (!err) console.log('Subscribed to smart home sensor topics.');
    });
});

// Handle incoming Smart Home MQTT Data
mqttClient.on('message', (topic, message) => {
    const value = parseFloat(message.toString());
    if (isNaN(value)) return;

    const query = `INSERT INTO home_sensors (topic, value) VALUES (?, ?)`;
    db.run(query, [topic, value], (err) => {
        if (err) console.error('Failed to log sensor data:', err.message);
        else console.log(`[MQTT Save] Topic: ${topic} | Value: ${value}`);
    });
});

// Helper function to publish route status via MQTT
function publishStatus(route, status) {
    const payload = JSON.stringify({ method: route, status: status, timestamp: new Date() });
    mqttClient.publish('health/status', payload, () => {
        console.log(`[MQTT Status Broadcast] Topic: health/status | Data: ${payload}`);
    });
}

// ==========================================
// 3. WEB SERVER ROUTES (Fitness Tracker)
// ==========================================

// i. /add - Add user and health information
app.post('/add', (req, res) => {
    const { name, age, city, steps, pulse, spo2, temperature } = req.body;
    const query = `INSERT INTO fitness_users (name, age, city, steps, pulse, spo2, temperature) VALUES (?, ?, ?, ?, ?, ?, ?)`;
    
    db.run(query, [name, age, city, steps, pulse, spo2, temperature], function(err) {
        if (err) {
            publishStatus('/add', 'failure');
            return res.status(400).json({ error: err.message });
        }
        publishStatus('/add', 'success');
        res.status(201).json({ message: 'User added successfully', userId: this.lastID });
    });
});

// ii. /all - Display health information of all users
app.get('/all', (req, res) => {
    const query = `SELECT * FROM fitness_users`;
    db.all(query, [], (err, rows) => {
        if (err) {
            publishStatus('/all', 'failure');
            return res.status(500).json({ error: err.message });
        }
        publishStatus('/all', 'success');
        res.json(rows);
    });
});

// iii. /info - Display health information of a single user (Query param: ?name=John)
app.get('/info', (req, res) => {
    const userName = req.query.name;
    const query = `SELECT * FROM fitness_users WHERE name = ?`;
    db.get(query, [userName], (err, row) => {
        if (err || !row) {
            publishStatus('/info', 'failure');
            return res.status(404).json({ error: row ? err.message : 'User not found' });
        }
        publishStatus('/info', 'success');
        res.json(row);
    });
});

// iv. /update - Update city of given user
app.put('/update', (req, res) => {
    const { name, city } = req.body;
    const query = `UPDATE fitness_users SET city = ? WHERE name = ?`;
    
    db.run(query, [city, name], function(err) {
        if (err || this.changes === 0) {
            publishStatus('/update', 'failure');
            return res.status(404).json({ error: 'User not found or update failed' });
        }
        publishStatus('/update', 'success');
        res.json({ message: `City updated successfully for user: ${name}` });
    });
});

// v. /steps - Display user information whose steps are maximum
app.get('/steps', (req, res) => {
    const query = `SELECT * FROM fitness_users ORDER BY steps DESC LIMIT 1`;
    db.get(query, [], (err, row) => {
        if (err || !row) {
            publishStatus('/steps', 'failure');
            return res.status(404).json({ error: row ? err.message : 'No users found' });
        }
        publishStatus('/steps', 'success');
        res.json(row);
    });
});

// Start Server
app.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});
