#include <ezButton.h>
#include <Stepper.h>

ezButton button(7);
const int LED_PIN = 6;

const int STEPS_PER_REVOLUTION = 32;
const int GEAR_REDUCTION = 64;
const int TURN_FACTOR = 6; // a divider 2 = 1/2 turn per photo 

/**
 * The gear ratio is 1 to 10, so approximately 36 degrees per turn (small motor is prone to a bit of error)
 */



const int SPEED = 60;

const int STEPS = (STEPS_PER_REVOLUTION * GEAR_REDUCTION)/ TURN_FACTOR;

int StepsRequired;
int degrees = 0;

Stepper stepperMotor(STEPS, 8, 10, 9, 11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // button.setDebounceTime(50); // 100 millisecond debounce time
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  button.loop(); // have to call this first
  if(button.isPressed()){
    digitalWrite(LED_PIN, HIGH); 
    stepperMotor.setSpeed(SPEED);
    stepperMotor.step(STEPS); // 1 rev = 10 degress about
    Serial.println("complete, trigger camera");
    digitalWrite(LED_PIN, LOW); 
    degrees +=10;
    Serial.println(degrees);
  }

  if(button.isReleased()){
    // this needs to be here or the button down code loops twice - I don't know why yet
    Serial.println("The button is released");
  }
    
}
