#include<SPI.h>                        
int cs_mega = 10;
int cs_uno = 9;
void setup (void)

{
  Serial.begin(115200);                                
  pinMode(cs_mega,OUTPUT);
  pinMode(cs_uno,OUTPUT);
 
  SPI.begin();                            
  SPI.setClockDivider(SPI_CLOCK_DIV8); 
  digitalWrite(cs_uno,HIGH);     
  digitalWrite(cs_mega,HIGH);    

}

void loop(void)
{
  char m_receive, m_sender; 
  m_sender = 'M';        
 
  // transmission to mega
  digitalWrite(cs_mega,LOW);    
  m_receive = SPI.transfer(m_sender);
  Serial.println(m_receive);   
  digitalWrite(cs_mega,HIGH);    

  // transmission to Uno
  digitalWrite(cs_uno,LOW);    
  m_receive = SPI.transfer(m_sender);
  Serial.println(m_receive);   
  digitalWrite(cs_uno,HIGH); 
    
  delay(1000);
}
