/*
  sensor_basic
  reads from the motion sensor and lights up LED when detects motion
  from http://arduinobasics.blogspot.com/search/label/HC-SR501 
 */
 
// Pin 13 is our LED
// Pin 2 is the motion sensor
int led = 13;
int sensor = 2;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output and motion as input
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);  
}

// the loop routine runs over and over again forever:
// LED on when sensor high, y vice versa
void loop() {
  digitalWrite(led, digitalRead(sensor)); 
  delay(100);
}
