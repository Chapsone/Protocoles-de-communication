#include <Wire.h>
byte val = 0;
void setup() {
  Wire.begin(44); // 44 is the adresse of the slave.          
  Wire.onReceive(receiver);
  Wire.onRequest(sender);
  Serial.begin(9600);       
}

void sender(){
  // transmission of string and obviously of a char
  
  String msg = "hello";
  char response[sizeof(msg)];
  msg.toCharArray(response, sizeof(msg) );
  Wire.write(response, sizeof(response));
  Serial.println(msg + val);
  } 
  
void receiver(){
  // reception of int
  while(Wire.available()){
  val = Wire.read();
  }
}
// the void loop is free to compule other activity
void loop() {
  delay(50);
}
