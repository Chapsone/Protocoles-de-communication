#include<SPI.h>
#define inputbutton 2
#define outputLED 4

volatile boolean received;
volatile char Slavereceived,Slavesend;

void setup()
{
  Serial.begin(115200);
  pinMode(MISO,OUTPUT);                  
  
  SPCR |= _BV(SPE);                  
  received = false;

  SPI.attachInterrupt();                  
  
}

ISR (SPI_STC_vect)                        
{
  Slavereceived = SPDR;
  received = true;                        
}

void loop()
{  
 if(received)                           
   {
      //print and sending data to the bus
      Serial.println(Slavereceived);
      Slavesend = 'O';                             
      SPDR = Slavesend;                       
      received = false;
   }
}
