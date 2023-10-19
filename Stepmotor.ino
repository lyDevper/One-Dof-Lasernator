const int stepPin = 4;
const int dirPin = 3;
const int enPin = 2;

const int limSwPin = 5;  // change for limit switch pin
const int laserPin = 6;

const float stepAng = 0.225;  // angle per step after considering gearing
const float angPerHole = 5;
float degAtLim = -3; // deg position at limit switch for offsetting to 0 deg, must be calibrated

int stepNow = 0; // keep tracking current absoute position in steps
//float idealDegNow = 0; // tracking expected angle deg

void setStepNow(int stepNow_) {
  stepNow = stepNow_;  
}

void setDegNow(int degPos) {
  stepNow = round(degPos / stepAng);
}

float getDegNow() {
  return stepNow * stepAng;
}

//----------------------------------------------------------------------------------//
void stepBy(int steps, int tlr) {  // rotate by a number of steps
  if (steps > 0)
    digitalWrite(dirPin, 1);
  else
    digitalWrite(dirPin, 0);

  for (int x = 0; x < abs(steps); x++) {
    digitalWrite(stepPin, 1);
    delayMicroseconds(tlr);
    digitalWrite(stepPin, 0);
    delayMicroseconds(tlr);
  }
  stepNow += steps;
}

void stepTo(int stepPos, int tlr) {  // rotate to an absolute position specified in steps
  int steps = stepPos - stepNow;
  stepBy(steps, tlr);
}

void rotateToDeg(float degPos, int tlr) {  // rotate to an absolute position in deg
  Serial.print("Rotating to deg: ");
  Serial.println(degPos);

  int stepPos = round(degPos / stepAng);
  stepTo(stepPos, tlr);

  Serial.print("Rotated to steps: ");
  Serial.print(stepNow);
  Serial.print(" deg: ");
  Serial.println(getDegNow());
}

void rotateByDeg(float deg, int tlr) {
  rotateToDeg(getDegNow() + deg, tlr);
}

void rotateToHole(int hole, int tlr) {
  rotateToDeg(hole*angPerHole, tlr);
}

void rotateByHole(int hole, int tlr) {
  rotateByDeg(hole*angPerHole, tlr);
}

//--------------------------------------------------------------//
void rotateToLimSw() {
  while (true) {
    if (digitalRead(limSwPin))
      break;
    stepBy(-1, 8000);  // by 1 or -1
  }
}

void homeToZero() {
  rotateToLimSw();
  setDegNow(degAtLim);
  rotateToDeg(0, 8000); // to position of 0 deg at 0th hole
  setDegNow(0);
}

void laserOn() {
  digitalWrite(laserPin, 1);
}

void laserOff() {
  digitalWrite(laserPin, 0);
}

void beamLaser(int duration) {
  digitalWrite(laserPin, 1);
  delay(duration);
  digitalWrite(laserPin, 0);
  delay(1000);
}

// ----------------------------------------------------------------------- //
int delay_tlr = 5000;  //delay tolerance to use
void setup() {
  Serial.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  pinMode(limSwPin, INPUT);
  pinMode(laserPin, OUTPUT);

  digitalWrite(enPin, LOW);
  digitalWrite(stepPin, 0);

  Serial.println("setup started beep beep...");
  //testStepper();
}

void loop() {
  app();
}

void testStepper() {
  rotateToDeg(180, delay_tlr);
  delay(1000);  // One second delay
  digitalWrite(laserPin, 1);
  delay(1000);
  digitalWrite(laserPin, 0);
  delay(1000);
  rotateToDeg(0, delay_tlr);
  delay(1000);
}

void app0() { //spare but not used now
  // program to interface the user and call rotateToDeg() to rotate according to the desired input
  Serial.println("Please enter deg : ");
  while (!Serial.available() > 0) {
    delay(100);  //Wait for user input
    //Serial.println(Serial.available()); >> 0
    // don't forget to select "No Line Ending" in Serial Monitor!!!
  }
  float inpDeg = Serial.parseFloat();  //Read user input and hold it in a variable
  rotateToDeg(inpDeg, delay_tlr);
  beamLaser(1500);
}

