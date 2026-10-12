#include <Servo.h>

//Pin 2 connects to Left press down button
//Pin 4 connects to Right press down button

// Create Servo objects for the 4 degrees of freedom
Servo servoBase;
Servo servoLeft;
Servo servoRight;
Servo servoGripper;

// Define Joystick Analog Input Pins
const int joyRightX = A3; //A0;
const int joyRightY = A2; //A1;
const int joyLeftX  = A0; //A2;
const int joyLeftY  = A1; //A3;

// Define Servo Output Pins
const int pinBase    = 5;
const int pinLeft    = 10;
const int pinRight   = 9;
const int pinGripper = 11;

// Initial angles
int angleBase = 90;
int angleLeft = 180;
int angleRight = 135;
int angleGripper = 30;

void setup() {
  // Attach servos to corresponding digital pins
  servoBase.attach(pinBase);
  servoLeft.attach(pinLeft);
  servoRight.attach(pinRight);
  servoGripper.attach(pinGripper);

  // Set initial neutral positions
  servoBase.write(angleBase);
  servoLeft.write(angleLeft);
  servoRight.write(angleRight);
  servoGripper.write(angleGripper);
}

void loop() {
  // Read analog values from joysticks (range: 0 to 1023)
  int valRightX = analogRead(joyRightX);
  int valRightY = analogRead(joyRightY);
  int valLeftX  = analogRead(joyLeftX);
  int valLeftY  = analogRead(joyLeftY);

  // Map joystick values (0-1023) to servo angles (0-180 degrees)
  angleBase    = map(valRightX, 0, 1023, 180, 0);
  angleRight    = map(valRightY, 0, 1023, 180, 90);
  angleLeft   = map(valLeftX,  0, 1023, 130, 180);
  angleGripper = map(valLeftY,  0, 1023, 22, 48);

  // Move the servos to the new mapped positions
  servoBase.write(angleBase);
  servoLeft.write(angleLeft);
  servoRight.write(angleRight);
  servoGripper.write(angleGripper);

  // Small delay for smooth operation
  delay(15);
}