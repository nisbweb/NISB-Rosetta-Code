#include <Servo.h>

Servo servo_1; // servo controller (multiple can exist)

int trig = 4; // trig pin for HC-SR04
int echo = 5; // echo pin for HC-SR04
int servo_pin = 3; // PWM pin for servo control
int buzz_pin = 2;
int led = 13;
int x;

int pos = 20;    // servo starting position
float duration,distance;

void setup() {
  Serial.begin(115200);
  Serial.println("Radar Start");
  servo_1.attach(servo_pin); // start servo control
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzz_pin,OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  for (pos = 20; pos <= 160; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo_1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30); // delay to allow the servo to reach the desired position
    x=dist_calc(pos);
    if(x<30 && x>0)
    {
      digitalWrite(buzz_pin, HIGH);
      digitalWrite(led, HIGH);
    }
    else
    {
      digitalWrite(buzz_pin, LOW);
      digitalWrite(led, LOW);
    }
    
  }
 
  for (pos = 160; pos >= 20; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo_1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);
    x=dist_calc(pos);
    if(x<30 && x>0)
    {
      digitalWrite(buzz_pin, HIGH);
      digitalWrite(led, HIGH);
    }
    else
    {
      digitalWrite(buzz_pin, LOW);
      digitalWrite(led, LOW);
    }
  }
}

float dist_calc(int pos){
  // trigger 40kHz pulse for ranging
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  // convert from duration for pulse to reach detector (microseconds) to range (in cm)
  duration = pulseIn(echo,HIGH); // duration for pulse to reach detector (in microseconds)
  distance = 100.0*(343.0*(duration/2.0))/1000000.0; // 100.0*(speed of sound*duration/2)/microsec conversion
 
  Serial.print(pos); // position of servo motor
  Serial.print(","); // comma separate variables
  Serial.println(distance); // print distance in cm
}