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
AccelStepper stepper(AccelStepper::HALF4WIRE, 2, 4, 3, 5);

const long stepsPerRevolution = 4096;
const int totalRevolutions = 680;
const int stepChunk = 100;  // Po kolika otáčkách postupovat

int currentRevolution = 0;
bool moving = false;

void setup() {
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);
}

void loop() {
  if (!moving && currentRevolution < totalRevolutions) {
    long steps = stepsPerRevolution * stepChunk;
    stepper.move(steps);
    currentRevolution += stepChunk;
    moving = true;
  }

  if (moving) {
    if (stepper.distanceToGo() != 0) {
      stepper.run();
    } else {
      moving = false;  // Hotovo, připraveno na další chunk
    }
  }
}