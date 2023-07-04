#include <Wire.h>

byte val = 0;

void setup() {
  Wire.begin(); // Join I2C bus
  Serial.begin(9600);
}

void loop() {   
                   
    send_msg(44, val); // 44 is the adresse of mega
    send_msg(45, val); // 45 is the adresse of UNO 
    val++; 
    if(val == 255) val = 0;
    
    Wire.requestFrom(44, 5);
    String msg = "";
    byte vallue;
    while(Wire.available()){
      char b = Wire.read();
      msg += b;
    }
    
    Serial.println(msg + val);
    delay(500);

    
}

// this function send a message to the bus 
void send_msg(int addr, byte msg){
  Wire.beginTransmission(addr);  
  Wire.write(msg);             
  Wire.endTransmission();      
}
