#include <ezButton.h>
#include <AccelStepper.h>

#define HALF4WIRE 8


#define ledPin 6
#define cameraPin 13

#define REV 4096

/** 
 *  I'm using a 28BYJ-48 stepper motor with a ULN2003 driver
 *  I tested a nema 17 motor and found it to be overkill, microstepping was needed to avoid vibration
 *  and the power requirements were heavier. The smaller 5v motor does the job fine and is simpler to deploy.
 */

#define motorPin1  8         // IN1 on the ULN2003 driver 1
#define motorPin2  9         // IN2 on the ULN2003 driver 1
#define motorPin3  10        // IN3 on the ULN2003 driver 1
#define motorPin4  11        // IN4 on the ULN2003 driver 1

AccelStepper stepper_Motor(HALF4WIRE, motorPin1, motorPin3, motorPin2, motorPin4); 
const int MAXSPEED =  2000;
const int ACCELERATION = 100;
const int STEPS = 200; //(STEPS_PER_REVOLUTION * GEAR_REDUCTION)/ TURN_FACTOR;

ezButton button(7);
const int numRotation = 8;


void setup() {
  stepper_Motor.setMaxSpeed(MAXSPEED);
  stepper_Motor.setAcceleration(ACCELERATION);
  stepper_Motor.setSpeed(1000);
  
  pinMode(ledPin, OUTPUT);
  pinMode(cameraPin, OUTPUT);
  digitalWrite(cameraPin, LOW); 
}

void loop() {
  
  button.loop(); // have to call this first - per ezButton
  
  if(button.isPressed()){
    digitalWrite(ledPin, HIGH); 

    for (int i = 0; i < 80; i++){
      stepper_Motor.setCurrentPosition(0);
      stepper_Motor.moveTo(REV / numRotation);
      // Run to target position with set speed and acceleration/deceleration:
      stepper_Motor.runToPosition();
      delay(200); // can lengthen this if wobble from motor
      // trigger the camera
      digitalWrite(cameraPin, HIGH);
      delay(200);
      digitalWrite(cameraPin, LOW);
      delay(4000); // allows for up to 4 second shutter speed
    }
    digitalWrite(ledPin, LOW); 
  }

  if(button.isReleased()){
    // this needs to be here or the button down code loops twice - I don't know why yet
    Serial.println("The button is released");
  }
    
}
