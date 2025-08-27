#include <AccelStepper.h>

/*
 * A camera timelapse rotator 
 * using arduino and 28BYJ-48 stepper motor.
 * 
 * ULN2003A driver setup
 *   + IN1 to D2 (digital pin 2)
 *   + IN2 to D3
 *   + IN3 to D4
 *   + IN4 to D5
 */

#define SPEED_PIN A0
#define STEP_NUM 64
#define MULTIPLIER 5 // change this value to adjust min/max speed

// počet kroků na 120°
const long steps120 = 4096 / 3;  

AccelStepper stepper = AccelStepper(AccelStepper::HALF4WIRE, 2, 4, 3, 5);
// notice that two pins(3, 4) are swapped.

void setup() {
  stepper.setMaxSpeed(1);        // maximum steps after one second
  stepper.setSpeed(0.1896);      // speed is 120° in 2 hour
  stepper.moveTo(steps120);      // move to position of 120°
}

void loop() {
  stepper.runSpeedToPosition();  // go to final position

  if (stepper.distanceToGo() == 0) {
    // change direction
    if (stepper.currentPosition() > 0) {
      stepper.moveTo(0);              // backward to start position
    } else {
      stepper.moveTo(steps120);       // forward again
    }
  }
}