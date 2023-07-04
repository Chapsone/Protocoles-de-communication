#include <ros.h>
#include <std_msgs/Int64.h> // delaration of header
#include <std_msgs/Float32.h>
#include <std_msgs/String.h>

String sensor;
String command;

void messageCb( const std_msgs::Int64 &toggle_msg) // Callback
{
  int m = toggle_msg.data;
  command = String(m);
}

std_msgs::String sensor_str;
ros::NodeHandle  nh;
ros::Publisher pub("/arduino_pub", &sensor_str);
ros::Subscriber<std_msgs::Int64> sub("/arduino_sub", messageCb );

void setup() 
  {
    nh.initNode();
    nh.subscribe(sub); //subscriber 
    nh.advertise(pub); // publisher
    
    Serial2.begin(38400);
    delay(10);
  }

void loop() 
{
 

  //publisher
  char char_sensor[sensor.length()+1];
  sensor.toCharArray(char_sensor, sensor.length()+1);
  sensor_str.data = char_sensor;
  pub.publish(&sensor_str);
  nh.spinOnce();
  delay(1);
  transmission();
  reception();

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
