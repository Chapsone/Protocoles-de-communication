/*
 * the best way to code is to learn what organisation is!
 * structure the data so that you can have a good understanding of it!
 * give a variable or constant a relative name
 */
 
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX

// global varable of velocity and sens 
int vel[4]; 
int sens[4];
int msg;

void setup() 
  {
    Serial.begin(9600);
    mySerial.begin(9600);
  }

void loop() 
  {
    if (mySerial.available())
      {
       // Serial.println("yes");
//        msg = mySerial.read();
          Serial.println(mySerial.readString());
//        decomposition();
//        Serial.println(vel[3]);
      }

      mySerial.println("hello1");
  }

//void decomposition()
//  { 
//    //declaration of velocity and sens and their relative point as global
//    int *v = &vel[0];
//    int *s = &sens[0];
//    //convertion from string to char
//    char msg_char[msg.length()+1]; // we add the one because of the start value (0);
//    msg.toCharArray( msg_char, msg.length()+1);
//  
//    //fiability verification
//    char* p = &msg_char[0];
//    String fiability = String(*p) + *(p+1);
//    if( fiability=="00") 
//      {
//        //actualisation de la valeur du pointeur
//        p+=2;
//        for(int i=0; i<=9; i+=3)
//          {
//            String str_sens = String(*(p+i));
//            String str_vel = String(*(p+i+1)) + *(p+i+2);
//            *s = str_sens.toInt();
//            *v = str_vel.toInt();
//            s++;
//            v++;
//          }        
//      }
//  }
