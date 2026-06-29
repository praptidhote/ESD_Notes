
from flask import Flask, render_template, request
import paho.mqtt.client as mqtt

app = Flask(__name__)

publisher = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)

@app.route('/', methods = ['GET'])
def homepage():
    return render_template("homepage.html")                    

@app.route('/welcome', methods = ['GET'])
def welcome():
    string = "Home Automation"
    return  render_template("welcome.html", message=string)

@app.route('/temperatures', methods = ['GET'])
def get_temperatures():
    temps = [(29.0, "Indrayani"), (28.2, "Nira"), (25.8, "Krishna")]
    return render_template("table.html", message=temps)

@app.route('/temperature', methods = ['POST', 'GET'])
def add_temperature():
    if request.method == 'POST':
        temp = request.form.get('temp')
        loc = request.form.get('loc')
        print(f"location = {loc}, temperature = {temp}")

    return render_template("form.html")

@app.route('/led', methods = ['POST', 'GET'])
def led_control():
    if request.method == 'POST':
        action = request.form.get('action')
        print(f"action = {action}")

        publisher.connect(host='localhost')
        publisher.publish(topic="toggle/led", payload=action)
        publisher.disconnect()

        
    return render_template("led.html")

if __name__ == '__main__':
    app.run(debug=True)
