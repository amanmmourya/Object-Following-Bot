#include <HCSR04.h>
int trig = 5;
int echo = 3;
int PWM1= 6;
int PWM2= 9;
int SLEEP1=12;
int SLEEP2=13;
int DIR1=7;
int DIR2=8;
void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(PWM1,OUTPUT);
  pinMode(PWM2,OUTPUT);
  pinMode(SLEEP1,OUTPUT);
  pinMode(SLEEP2,OUTPUT);
  pinMode(DIR1,OUTPUT);
  pinMode(DIR2,OUTPUT);
  digitalWrite(SLEEP1,LOW);
  digitalWrite(SLEEP2,LOW);
  Serial.begin(9600)
}

void loop() {
  // put your main code here, to run repeatedly: 
 float distance = calcDistance();
 if(distance<=20){
  stop();
 }else if(distance>=1000){
  fastForward();
 }else{
  //here we will write the code for communication with python
  if(Serial.available()>0){
   String data = Serial.readString();
   dir,speed=data.split()
   speed=int(speed)
   if(dir=="L"){left(speed)}
   if(dir=="R"){right(speed)}
   if(dir=="F"){fastforward(speed)}
   if(dir=="S"){stop()}
  }
 }
}
//distance calculator
float calcDistance(){
  //clear the trig pin
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  long duration = pulseIn(echo,HIGH);
  float distance = (duration*0.0343)/2;
  return distance;

}
//let us assume 1 HIGH while set a DIR such that motor will move in forward direction an LOW will result in backward direction
//1
void slowForward(){
     digitalWrite(DIR1,HIGH);
     digitalWrite(DIR2,HIGH);
     analogWrite(PWM1,100);
     analogWrite(PWM2,100);
}
//2
void fastForward(){
     digitalWrite(DIR1,HIGH);
     digitalWrite(DIR2,HIGH);
     analogWrite(PWM1,200);
     analogWrite(PWM2,200);
}
//3
void slightLeft(){
     digitalWrite(DIR1,HIGH);
     digitalWrite(DIR2,HIGH);
     analogWrite(PWM1,10);
     analogWrite(PWM2,150);
}
//4
void slightRight(){
     digitalWrite(DIR1,HIGH);
     digitalWrite(DIR2,HIGH);
     analogWrite(PWM1,150);
     analogWrite(PWM2,10);
}
//5
void left(int speed){
     digitalWrite(DIR1,LOW);
     digitalWrite(DIR2,HIGH);
     analogWrite(PWM1,50);
     analogWrite(PWM2,speed);
}
//6
void right(int speed){
     digitalWrite(DIR1,HIGH);
     digitalWrite(DIR2,LOW);
     analogWrite(PWM1,speed);
     analogWrite(PWM2,50);
}
//7
void slowBackward(){
     digitalWrite(DIR1,LOW);
     digitalWrite(DIR2,LOW);
     analogWrite(PWM1,100);
     analogWrite(PWM2,100);
}
//8
void fastBackward(){
     digitalWrite(DIR1,LOW);
     digitalWrite(DIR2,LOW);
     analogWrite(PWM1,255);
     analogWrite(PWM2,255);
}
//9
void rotateClockslow(){
     digitalWrite(DIR1,HIGH);
     
     analogWrite(PWM1,150);
     
}
//10
void rotateAntiClockslow(){
     
     digitalWrite(DIR2,HIGH);
     
     analogWrite(PWM2,150);
}
//11
void rotateClockfast(){
     digitalWrite(DIR1,HIGH);
     
     analogWrite(PWM1,255);
     

}
//12
void rotateAntiClockfast(){
     digitalWrite(DIR2,HIGH);
     
     analogWrite(PWM2,255);
     

}
//13
void stop(){
     digitalWrite(DIR1,HIGH);
     digitalWrite(DIR2,HIGH);
     analogWrite(PWM1,0);
     analogWrite(PWM2,0);
}