/*Example sketch to control a stepper motor with DRV8825 stepper motor driver, AccelStepper library and Arduino: acceleration and deceleration. More info: https://www.makerguides.com */

// Include the AccelStepper library:
#include <AccelStepper.h>

// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin 2
#define stepPin 3
#define motorInterfaceType 1

// Define pins on the Arduino for microstepping control on DRV8825 ( M0, M1, M2) MODE0, MODE1, MODE2 on the IC for you datasheet gurus ;)
#define M_ZERO 11
#define M_ONE 10
#define M_TWO 9
#define sleep_pwr 8

// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

void setup() {


  // Set the maximum speed and acceleration:
  stepper.setMaxSpeed(100);
  stepper.setAcceleration(30);
}

void loop() {



  stepper.setCurrentPosition(0);
  // Set the target position:
  stepper.moveTo(200);
  // Run to target position with set speed and acceleration/deceleration:
  stepper.runToPosition();

  delay(500);

}
