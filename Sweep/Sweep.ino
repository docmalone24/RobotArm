#include <Servo.h>

Servo base;
Servo horizontal;
Servo vertical;
Servo claw;

void setup() {
  Serial.begin(9600);

  base.attach(5);
  // base.write(90);
  horizontal.attach(9);
  // horizontal.write(120);
  vertical.attach(10);
  // vertical.write(120);
  claw.attach(11);
  // claw.write(0);
}

void loop() {
  int i;

  for (i = 60; i > 0; i--) {
    // base.write(i);
    //horizontal.write(i);
     //vertical.write(i);
    if (i > 22 && i < 47) {
      claw.write(i);
    }
    Serial.print("Level: ");
    Serial.println(i);
    delay(1000);
  }

  // for (i = 180; i > 0; i--) {
  // //   base.write(i);
  // //  horizontal.write(i);
  //    vertical.write(i);
  // //   if (i > 30 && i < 150) {
  // //     claw.write(i);
  // //   }
  //   Serial.print("Level: ");
  //   Serial.println(i);

  //   delay(1000);
  // }
}