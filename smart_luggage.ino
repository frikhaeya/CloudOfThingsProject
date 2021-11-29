//Activate the Bluetooth Module
#include <SoftwareSerial.h>
#define rxPin 2
#define txPin 3
#define baudrate 38400

String msg;
SoftwareSerial hc05(rxPin ,txPin);

//capteur ultrason
int trig = 2;
int echo = 3;
long lecture_echo;
long cm;

//Moteur
// Constants
const int enableBridge1 = 2;
const int MotorForward1 = 3;
const int MotorReverse1 = 5;
// Variables
int Power = 80; //Motor velocity between 0 and 255

//Distance and Direction Management
// distance d sera déduite à partir du capteur ultrason (d=cm)
bool BT = false;
int m1 = 0, m2 = 0;

void setup() {
  // Bluetooth Module 
  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);
  Serial.begin(9600);
  Serial.println("ENTER AT Commands:");
  hc05.begin(baudrate);
  //capteur ultrason
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  //Moteur
  pinMode(MotorForward1,OUTPUT);
  pinMode(MotorReverse1,OUTPUT);
  pinMode(enableBridge1,OUTPUT);
  
}

void loop() {
  // Bluetooth Module 
  readSerialPort();
    if(msg!="") hc05.println(msg);
    
    if (hc05.available()>0){
      Serial.write(hc05.read());
    }
    
  //Read value detected by the sensor
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  lecture_echo = pulseIn(echo,HIGH);
  cm = lecture_echo /58;
  Serial.print("Distance en cm :");
  Serial.println(cm);
  delay(1500); 

  // Distance Management 
  if ( cm >= 15 && cm <= 70){
    m1 = 255;
    m2 = 255;
  }
  else if ( cm < 15 ){
    m1 = 0;
    m2 = 0;
  }
  else if ( cm > 70 ){
    m1 = 255;
    m2 = 255;
    BT = true;
  }
  

  digitalWrite(enableBridge1,HIGH); // Active pont en H

  // Tourne dans le sens direct pendant 2 secondes
  analogWrite(MotorForward1,Power);
  analogWrite(MotorReverse1,0);
  delay(2000);
  
  // Tourne dans le sens indirect pendant 3 secondes
  analogWrite(MotorForward1,0);
  analogWrite(MotorReverse1,Power);
  delay(3000);
  
  //Arrête le moteur pendant 1 seconde
  analogWrite(MotorForward1,0);
  analogWrite(MotorReverse1,0);
  digitalWrite(enableBridge1,LOW); 
  delay(1000);
}


void readSerialPort(){
  msg="";
 while (Serial.available()) {
   delay(10);  
   if (Serial.available() >0) {
     char c = Serial.read();  //gets one byte from serial buffer
     msg += c; //makes the string readString
   }
 }
}
