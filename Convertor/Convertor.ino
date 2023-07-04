

int Int=10;
String str="1234";
char Char[10]= "Chapi";


void setup() {
 /*
  * this file is going to show you how to convert a data from a type to an other one
  */

  delay(10);
  
  Serial.begin(9600);
  // int to string 
  str = String(Int);
  Serial.println(" that's a string number from int: " + str);
  delay(10);

  // char to String
  str = String(Char);
  Serial.println(" that's a string number from char: " + str);
  delay(10);

  // String to int
  Int = str.toInt();
  Serial.println(" that's a int number from String: " + String(Int) );

  //String to char
  str.toCharArray( Char, 10);
  Serial.println(" that's a Char number from String: " + String(Char[1]));

/* 
 *  to convert int to char or do the opposit, well, we must go toward string, convert an Int to String, then the String to Char, or reciprqly
 */
 
  //x = atof(x_str); // convert string to float
  x = x_str.toFloat();
  z = z_str.toFloat();
}
void setup() {
Serial.begin(9600);
char *str="hello 12 30";
 char d1[4];
 int d2;
 int d3;
sscanf(str, "%s %d %d",d1, &d2, &d3);
Serial.println(d1);

}

void loop() {
  // put your main code here, to run repeatedly:

}
