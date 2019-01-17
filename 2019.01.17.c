
int brillo=15;
int incremento=5;
int ledPinR=9;
int ledPinG=5;
int ledPinB=6;
int joyX=0;
int joyY=1;
int valX=0;
int valY=0;
int valZ=0;
int btnU=2;
int btnD=3;

int ledPinO=12;




void setup() {
  // put your setup code here, to run once:
pinMode(ledPinR,OUTPUT);
pinMode(ledPinG,OUTPUT);
pinMode(ledPinB,OUTPUT);
pinMode(ledPinO,OUTPUT);
pinMode(btnU,INPUT);
pinMode(btnD,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(ledPinR,valX);
  analogWrite(ledPinG,valY);
  analogWrite(ledPinB,valZ);
  
  
  valX=analogRead(joyX);
  valX=map(valX,0,1023,0,255);
  
  valY=analogRead(joyY);
  valY=map(valY,0,1023,0,255);

  if(digitalRead(btnU)==1){
    valZ++;
  }

  if(digitalRead(btnD)==1){
    valZ--;
  }
  if(valZ>255){
    valZ=255;
    dblBlink();
    }
  if(valZ<0){
    valZ=0;
    dblBlink();
    }  
    Serial.println(valZ);


}

  void dblBlink(){
    analogWrite(ledPinO,HIGH);
    delay(500);
    analogWrite(ledPinO,LOW);
    delay(500);
    
    analogWrite(ledPinO,HIGH);
    delay(500);
    analogWrite(ledPinO,LOW);
    delay(500);
    
  }