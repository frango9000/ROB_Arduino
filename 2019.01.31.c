
#include <Servo.h>

#define joyX A0
#define joyY A1

#define btnU 2
#define btnD 3

#define laser 12


Servo myservoX;  // create servo object to control a servo
Servo myservoY;  // create servo object to control a servo

//int potpin = 0;  // analog pin used to connect the potentiometer
int valX;    // variable to read the value from the analog pin
int valY;    // variable to read the value from the analog pin

void setup() {
pinMode(btnU,INPUT);
pinMode(btnD,INPUT);
pinMode(laser,OUTPUT);
  myservoX.attach(7);  // attaches the servo on pin 9 to the servo object
  myservoY.attach(4);  // attaches the servo on pin 9 to the servo object
  
  Serial.begin(9600);
}

void loop() {
  valX = analogRead(joyX);            // reads the value of the potentiometer (value between 0 and 1023)
//Serial.println(valX);
  valX = map(valX, 0, 1020, 179, 0);     // scale it to use it with the servo (value between 0 and 180)

  valY = analogRead(joyY);            // reads the value of the potentiometer (value between 0 and 1023)
//Serial.println(valY);
  valY = map(valY, 0, 1018, 0, 150);     // scale it to use it with the servo (value between 0 and 180)

if(digitalRead(btnU)==1){
  analogWrite(laser,HIGH);
  delay(500);
  
  analogWrite(laser,LOW);
}
  
  myservoX.write(valX);                  // sets the servo position according to the scaled value
  myservoY.write(valY);                  // sets the servo position according to the scaled value

  
  delay(15);                           // waits for the servo to get there
}
