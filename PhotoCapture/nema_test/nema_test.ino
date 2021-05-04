#include <Stepper.h> 
#define STEPS 200
//#define dirPin 2
//#define stepPin 3
// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
Stepper stepper(STEPS, 2, 3);
#define motorInterfaceType 1


void setup() {
  // Set the maximum speed in steps per second:
  stepper.setSpeed(800);

}
void loop() {
 
  stepper.step(STEPS * 4);
  delay(2000);
  
}
