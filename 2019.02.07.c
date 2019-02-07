
#include <Servo.h>

#define joyX A0
#define joyY A1

#define btnU 2
#define btnD 3

#define laser 8

Servo myservoPan, myservoTilt;  // create servo object to control a servo

int valX;    // variable to read the value from the analog pin
int valY;    // variable to read the value from the analog pin

int speed = 2;

int lowDeadBand = 300;
int HighDeadBand = 900;

int panValue = 90, tiltValue = 90;



void setup() {
pinMode(btnU,INPUT);
pinMode(btnD,INPUT);
pinMode(laser,OUTPUT);
myservoPan.attach(7);  // attaches the servo on pin 9 to the servo object
myservoTilt.attach(4);  // attaches the servo on pin 9 to the servo object

myservoPan.write(panValue);
myservoTilt.write(tiltValue);
  Serial.begin(9600);
}

void loop() {
  valX = analogRead(joyX);            // reads the value of the potentiometer (value between 0 and 1023)
  valY = analogRead(joyY);            // reads the value of the potentiometer (value between 0 and 1023)

 if(valX < lowDeadBand || valX > highDeadBand){
  valX = map(valX, 0, 1020, speed, -speed);     // scale it to use it with the servo (value between 0 and 180)
  panValue = max(valX,180);
  panValue = min(valX,  0);
  myservoPan.write(panValue);
}
if(valY < lowDeadBand || valY > highDeadBand){
  valY = map(valY, 0, 1020, speed, -speed);     // scale it to use it with the servo (value between 0 and 180)
  panValue = max(valY,180);
  panValue = min(valY,  0);
  myservoTilt.write(tiltValue);
}

//Serial.println(valY);
//Serial.println(valX);

if(digitalRead(btnU)==1){
  analogWrite(laser,HIGH);
  delay(500);
  analogWrite(laser,LOW);
}
 delay(15);                           // waits for the servo to get there
}
