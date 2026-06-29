from flask import Flask, render_template

app = Flask(__name__)

@app.route('/', methods = ['GET'])
def homepage():
    return render_template("homepage.html")

@app.route('/welcome', methods = ['GET'])
def welcome():
    string = "IoT Application"
    return render_template("welcome.html", message=string)


if __name__ == '__main__':
    app.run(debug=True)