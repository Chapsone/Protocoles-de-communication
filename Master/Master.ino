/*
 * the best way to code is to learn what organisation is!
 * structure the data so that you can have a good understanding of it!
 * give a variable or constant a relative name
 */
 
int vfr=10,vbr=20, vfl=30, vbl=40;
bool sfr=1,sbr=0, sfl=0, sbl=1;
void setup() 
{
  Serial.begin(9600);
  Serial2.begin(9600);
 
}

void loop()
{
  //Transmission
//  String msg, fiability="00";
//  msg = fiability +  sfr + vfr +  sbr + vbr  + sfl + vfl + sbl + vbl ;
//  Serial.println(msg);
   Serial2.println("hello");
   if (Serial2.available())  Serial.println(Serial2.readString());
  delay(10);
  
}
