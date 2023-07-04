#include <AFMotor.h>
AF_DCMotor M_FR(4);
AF_DCMotor M_FL(3);
AF_DCMotor M_BR(1);
AF_DCMotor M_BL(2);
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
M_FR.setSpeed(40);
M_FR.run(FORWARD);

M_FL.setSpeed(40);
M_FL.run(FORWARD);

M_BR.setSpeed(40);
M_BR.run(FORWARD);

M_BL.setSpeed(40);
M_BL.run(FORWARD);



}
