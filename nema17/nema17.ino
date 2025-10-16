// pin connections
const int dirPin = 2; // direction pin
const int stepPin = 3; // step pin
const int speed = 41250;

const int stepsPerRevolution = 200;
const int rotations = 680;
const long totalSteps = stepsPerRevolution * rotations;

void setup() {
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);

  // otáčení jedním směrem
  digitalWrite(dirPin, LOW);
  doSteps(totalSteps);  // krokování vpřed

  delay(10000); // pauza 10 sekunda

  // změna směru
  digitalWrite(dirPin, HIGH);
  doSteps(totalSteps);  // krokování zpět
}

void doSteps(long steps) {
  for (long i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(speed);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(speed);
  }
}

void loop() { }