String sensor;
String command = "99100000000000";
void setup() 
{
  Serial.begin(38400);
  Serial2.begin(38400);
  delay(10);

}

void loop() {
transmission();
reception();
Serial.println(sensor);
}

void reception()
{
  int s = 0;
  while(s != 10)
  {
    if (Serial2.available())
    {
      String sensor_str = Serial2.readStringUntil('\n');
      // traitement et separation
      char sensor_char[sensor_str.length()+1];
      sensor_str.toCharArray(sensor_char, sensor_str.length()+1);
      String len;
      len = len + sensor_char[0] + sensor_char[1];
      if (sensor_str.length() == len.toInt()+3)
      {
        s = 10;
        Serial2.write(s);
        sensor = sensor_str;
        delay(10);
      }
    }
  }
  Serial.println("message receved");
}

void transmission()
{
 int s = 00; // s for synchronisation
  while(s != 10)
  {
    
    Serial2.println(command);
    delay(10);
    if (Serial2.available()) {
    s = Serial2.read(); 
    }
  }
  Serial.println("message send");
}
