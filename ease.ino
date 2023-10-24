void ease_stepBy(int steps, float min_tlr) {
  if (steps > 0)
    digitalWrite(dirPin, 1);
  else
    digitalWrite(dirPin, 0);

  int n = abs(steps);
  float end_tlr = 10000; // tlr at beginning and final
  float ease_times = min(round(0.12 * n), 40); // duration to ease in and ease out

  if(n*stepAng < 15) {
    min_tlr = (min_tlr + end_tlr)/2;
  }
  /*
  if (n < 2*ease_times) {
    stepBy(steps, (min_tlr + end_tlr)/2);
    return;
  }
  */

  for (int i = 0; i < abs(steps); i++) {    
    float tlr;
    if (i < ease_times) {
      tlr = map(i, 0, ease_times, end_tlr, min_tlr); // ease in
    }
    else if (i < n-ease_times) {
      tlr = min_tlr; // constant v
    }
    else {
      tlr = map(i-(n-ease_times), n-ease_times, n, min_tlr, end_tlr); // ease out
    }

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

void ease_rotateByDeg(float deg, int min_tlr) {
  ease_rotateToDeg(getDegNow() + deg, min_tlr);
}