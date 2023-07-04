#include <SoftwareSerial.h>
SoftwareSerial Serial12(9, 10); // RX, TX
String command = "99100000000000";
String sensor;
void setup() 
{
  Serial.begin(38400);
  Serial12.begin(38400);
  delay(10);

}

void loop()
{
 transmission();
 reception();
}
void transmission()
{
  int s = 00; // s for synchronisation
  while(s != 10)
  {
    
    Serial12.println(command);
    delay(10);
    if (Serial12.available()) {
    s = Serial12.read(); 
    }
  }
  Serial.println("message send");
}

void reception()
{
  int s = 0;
  while(s != 10)
  {
    if (Serial12.available())
    {
      String sensor_str = Serial12.readStringUntil('\n');
      // traitement et separation
      char sensor_char[sensor_str.length()+1];
      sensor_str.toCharArray(sensor_char, sensor_str.length()+1);
      String len;
      len = len + sensor_char[0] + sensor_char[1];
      if (sensor_str.length() == 15)
      {
        s = 10;
        Serial12.write(s);
        sensor = sensor_str;
        delay(10);
      }
    }
  }
  Serial.println("message receved");
}
