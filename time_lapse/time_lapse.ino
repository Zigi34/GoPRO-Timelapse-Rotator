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

#define ALL_STEPS       4096
#define ANGLE           100
#define ANGLE_STEPS     ALL_STEPS / 360 * ANGLE
#define DURATION        (60 * 60 * 3.0)
#define SPEED           ANGLE_STEPS / DURATION

bool forward = true;

void setup() {
    stepper.setMaxSpeed(SPEED);         // max. speed (steps/s)
    stepper.setAcceleration(200);       // acceleration
    stepper.setCurrentPosition(0);

    stepper.moveTo(ANGLE_STEPS);        // move to position
}

void loop() {
    stepper.run();
    if (stepper.distanceToGo() == 0) {
        forward = !forward;
        if(forward) {
            stepper.moveTo(ANGLE_STEPS);
        } else {
            stepper.moveTo(0);
        }
    }
}