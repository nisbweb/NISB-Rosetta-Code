import RPi.GPIO as GPIO
from flask import Flask,render_template

# GPIO pins for Lamp LEDs
pinlist = [17,22,23,24,27]
pins = iter(pinlist)

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(pinlist, GPIO.OUT, initial = GPIO.LOW)


app = Flask(__name__)

#Home
@app.route('/', methods=['GET', 'POST'])
def index():
        return render_template("lampOn.html")

#Thank You
@app.route('/on/', methods=['GET', 'POST'])
def on():
    try:
        GPIO.output(next(pins), GPIO.HIGH)
        print('im here')
        return render_template("thankYou.html")
    except StopIteration:
        return render_template("thankYou.html")

#To turn off all LEDs
@app.route('/rootoff/')
def rootoff():
    global pins
    pins = iter(pinlist)
    GPIO.output(pinlist, GPIO.LOW)
    return '<h1>ROOT_OFF</h1>'

if __name__ == "__main__":
    app.run()
