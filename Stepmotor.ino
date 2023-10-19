const int stepPin = 4;
const int dirPin = 3;
const int enPin = 2;

const int limSwPin = 5;  // change for limit switch pin
const int laserPin = 6;

const float stepAng = 0.225;  // angle per step after considering gearing
int stepNow = 0;              // keep tracking current absoute position in steps

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
  int stepPos = round(degPos / stepAng);
  stepTo(stepPos, tlr);

  Serial.print("Rotates to  steps: ");
  Serial.print(stepNow);
  Serial.print(" deg: ");
  Serial.println(getDegNow());
}

void setStepNow(int stepNow_) {
  stepNow = stepNow_;
}
void setDegNow(int degPos) {
  stepNow = round(degPos / stepAng);
}
float getDegNow() {
  return stepNow * stepAng;
}

void homePosition() {
  while (true) {
    stepBy(1, 5000);  // by 1 or -1
    if (digitalRead(limSwPin))
      break;
  }
  setDegNow(0);  // set as a desired number of deg
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

  Serial.println("Hello");
  //testStepper();
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

float inpDeg;
void loop() {
  /*
  // program to interface the user and call rotateToDeg() to rotate according to the desired input
  Serial.println("Please enter deg : ");
  while (!Serial.available() > 0) {
    delay(100);  //Wait for user input
    //Serial.println(Serial.available()); >> 0
    // don't forget to select "No Line Ending" in Serial Monitor!!!
  }
  inpDeg = Serial.parseFloat();  //Read user input and hold it in a variable
  rotateToDeg(inpDeg, delay_tlr);
  beamLaser(1500);
  //still has bouncing error
  */
  app();
}

void waitForSerialInp() {
  while (!Serial.available() > 0) {
    delay(100);  //Wait for user input
    // don't forget to select "No Line Ending" in Serial Monitor!!!
  }
  return;
}
/*
void app() {  // to be called in void loop()
  Serial.println("Please enter the command. The existing commands are :");
  Serial.println("todeg <float>");
  waitForSerialInp();
  String cmd = Serial.readStringUntil('\n');

  if (cmd == "todeg") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    float para = Serial.parseFloat();
    // do something
  }
  else if
}
*/
