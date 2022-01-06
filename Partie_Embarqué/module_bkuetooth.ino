#include <SoftwareSerial.h>

SoftwareSerial hc06(2, 3);

void setup() {
  //Initialize Serial Monitor
  Serial.begin(9600);
  Serial.println("ENTER AT Commands:");
  //Initialize Bluetooth Serial Port
  hc06.begin(9600);
  pinMode(8, OUTPUT);
}

void loop() {
  //Write data from HC06 to Serial Monitor
  if (hc06.available()) {
    Serial.write(hc06.read());
    
 }
  
  //Write from Serial Monitor to HC06
  if (Serial.available()) {
   hc06.write(Serial.read());
   
 }

 if(Serial.available()>0)
   {     
      char data= Serial.read(); // reading the data received from the bluetooth module
      switch(data)
      {
        case 'a': digitalWrite(8, HIGH);break; // when a is pressed on the app on your smart phone
        case 'd': digitalWrite(8, LOW);break; // when d is pressed on the app on your smart phone
        default : break;
      }
      Serial.println(data);
   }
   delay(50);
}
