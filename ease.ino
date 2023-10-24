void ease_stepBy(int steps, float min_tlr) {
  if (steps > 0)
    digitalWrite(dirPin, 1);
  else
    digitalWrite(dirPin, 0);

  int end_tlr = 12000;
  int ease_times = 30;
  int n = abs(steps);

  if (n < 2*ease_times) {
    stepBy(steps, min_tlr + end_tlr/2);
    return;
  }

  for (int i = 0; i < abs(steps); i++) {    
    int tlr;
    if (i<ease_times)
      tlr = end_tlr + (i/ease_times) * (min_tlr-end_tlr);
    else if (i < n-ease_times)
      tlr = min_tlr;
    else
      tlr = end_tlr + ((i-(n-ease_times))/ease_times) * (min_tlr-end_tlr);

    digitalWrite(stepPin, 1);
    delayMicroseconds(tlr);
    digitalWrite(stepPin, 0);
    delayMicroseconds(tlr);
  }
  stepNow += steps;
}

void ease_stepTo(int stepPos, int min_tlr) {  // rotate to an absolute position specified in steps
  int steps = stepPos - stepNow;
  ease_stepBy(steps, min_tlr);
}

void ease_rotateToDeg(float degPos, int min_tlr) {  // rotate to an absolute position in deg
  Serial.print("Rotating to deg: ");
  Serial.println(degPos);

  int stepPos = round(degPos / stepAng);
  ease_stepTo(stepPos, min_tlr);

  Serial.print("Rotated to steps: ");
  Serial.print(stepNow);
  Serial.print(" deg: ");
  Serial.println(getDegNow());
  Serial.println();
}