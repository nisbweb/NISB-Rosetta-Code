#include<Servo.h>
const int trigPin = 7;      // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6;      // Echo Pin of Ultrasonic Sensor
Servo myservo;              // Creating an object for Servo class

void setup() {
   Serial.begin(9600);      // Serial Communication is starting with 9600 of baudrate speed
   myservo.attach(9);       // attach servo to pin 9 
   pinMode(trigPin, OUTPUT);// Sets the trigPin as an OUTPUT
   pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
}

void loop() {               // infinte loop
  
   long duration, cm;
  
   digitalWrite(trigPin, LOW);     // Clears the trigPin condition
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
   delayMicroseconds(10);         
   digitalWrite(trigPin, LOW);
   
   duration = pulseIn(echoPin, HIGH);  // Reads the echoPin, returns the sound wave travel time in microseconds
   
   cm = duration * 0.034 / 2;   // convert duration to cm
   Serial.print(cm);    //Printing distance in the serial monitor
   Serial.print("cm");
   Serial.println();
   if(cm < 10){         // if the distance is below 10cm
     myservo.write(45); // Rotate the servo by 45 degrees
     delay(500);        // delay of 500 milliseconds(for the servo)
     myservo.write(0);  // Rotate the servo back to the original position
     delay(500);}       
   delay(100);          // delay for the sensor (100 milliseconds)
}
