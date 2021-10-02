int led = 9;           // the PWM pin the LED is attached to
int intensity = 0;    
int fade = 5;    


void setup() {
  
  pinMode(led, OUTPUT);
}


void loop() {
  analogWrite(led, intensity);

  intensity = intensity + fade;
  if (intensity <= 0 || intensity >= 255) {
    fade = -fade;
  }
  delay(30);
}