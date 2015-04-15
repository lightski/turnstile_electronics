/* FSR testing sketch. 
 
Connect one end of FSR to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground
Connect LED from pin 11 through a resistor to ground 
 
 */
/***Velostat FSR to Analog in***/
int fsrAnalogPin1 = 0;  
int fsrAnalogPin2 = 1;
int fsrAnalogPin3 = 2;
int fsrAnalogPin4 = 3;

/***LEDs (PWM pins)***/
int LEDpin1 = 11;      // connect Blue LED to pin 11 (PWM pin)
int LEDpin2 = 10;
int LEDpin3 = 9;
int LEDpin4 = 6;

int fsrReading1;      // the analog reading from the FSR resistor divider
int fsrReading2;
int fsrReading3;
int fsrReading4;

int LEDbrightness1;
int LEDbrightness2;
int LEDbrightness3;
int LEDbrightness4;
 
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  pinMode(LEDpin1, OUTPUT);
  pinMode(LEDpin2, OUTPUT);
  pinMode(LEDpin3, OUTPUT);
  pinMode(LEDpin4, OUTPUT);
}
 
void loop(void) {
  fsrReading1 = analogRead(fsrAnalogPin1);
  //Serial.print("Analog reading = ");
  Serial.println(fsrReading1);
  
  fsrReading2 = analogRead(fsrAnalogPin2);
  Serial.println(fsrReading2);
  
  fsrReading3 = analogRead(fsrAnalogPin3);
  Serial.println(fsrReading3);
  
  fsrReading4 = analogRead(fsrAnalogPin4);
  Serial.println(fsrReading4);
  
  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map!
  LEDbrightness1 = map(fsrReading1, 0, 1023, 0, 255);
  LEDbrightness2 = map(fsrReading2, 0, 1023, 0, 255);
  LEDbrightness3 = map(fsrReading3, 0, 1023, 0, 255);
  LEDbrightness4 = map(fsrReading4, 0, 1023, 0, 255);
  // LED gets brighter the harder you press
  analogWrite(LEDpin1, LEDbrightness1);
  analogWrite(LEDpin2, LEDbrightness2);
  analogWrite(LEDpin3, LEDbrightness3);
  analogWrite(LEDpin4, LEDbrightness4);
 
  delay(100);
}
