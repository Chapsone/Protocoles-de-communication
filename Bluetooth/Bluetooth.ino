
void setup() {
   Serial.begin(9600);
}

char convert_to_char(String msg)
  {
    char hello[13];
    if (msg=="On") hello[13]="On";
    else if (msg=="Off") hello[13]="Off";
    return(hello);
  }

void loop()
{
  String hello = "On";
  char str_msg = convert_to_char(hello);
  Serial.println(str_msg);
  
}
