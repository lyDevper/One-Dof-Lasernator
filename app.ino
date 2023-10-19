void waitForSerialInp() {
  while (!Serial.available() > 0) {
    delay(100);  //Wait for user input
    // don't forget to select "No Line Ending" in Serial Monitor!!!
  }
  return;
}

void app() {  // To be called in void loop()
  Serial.println("Please enter the command. The existing commands are:");
  Serial.println("\ttodeg <float> or td <float>");
  Serial.println("\tbydeg <float> or bd <float>");
  Serial.println("\ttostep <int> or ts <int>");
  Serial.println("\tbystep <int> or bs <int>");
  Serial.println("\ttohole <int> or th <int>");
  Serial.println("\tbyhole <int> or bh <int>");
  Serial.println("\tsetdeg <float> or sd <float>");
  Serial.println("\tsetstep <int> or ss <int>");
  Serial.println("\thomezero or hz");
  Serial.println("\ttolimsw or tl");
  Serial.println("\tlaseron or ln");
  Serial.println("\tlaseroff or lf");
  Serial.println("\tbeam or bm");

  waitForSerialInp();
  String cmd = Serial.readStringUntil('\n');

  if (cmd == "todeg" || cmd == "td") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    float para = Serial.parseFloat();
    rotateToDeg(para, delay_tlr);
  }
  else if (cmd == "bydeg" || cmd == "bd") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    float para = Serial.parseFloat();
    rotateByDeg(para, delay_tlr);
  }
  else if (cmd == "tostep" || cmd == "ts") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    int para = Serial.parseInt();
    stepTo(para, delay_tlr);
  }
  else if (cmd == "bystep" || cmd == "bs") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    int para = Serial.parseInt();
    stepBy(para, delay_tlr);
  }
  else if (cmd == "tohole" || cmd == "th") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    int para = Serial.parseInt();
    rotateToHole(para, delay_tlr);
  }
  else if (cmd == "byhole" || cmd == "bh") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    int para = Serial.parseInt();
    rotateByHole(para, delay_tlr);
  }
  else if (cmd == "setdeg" || cmd == "sd") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    float para = Serial.parseFloat();
    setDegNow(para);
  }
  else if (cmd == "setstep" || cmd == "ss") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    int para = Serial.parseInt();
    setStepNow(para);
  }
  else if (cmd == "homezero" || cmd == "hz") {
    homeToZero();
  }
  else if (cmd == "tolimsw" || cmd == "tl") {
    rotateToLimSw();
  }
  else if (cmd == "laseron" || cmd == "ln") {
    laserOn();
  }
  else if (cmd == "laseroff" || cmd == "lf") {
    laserOff();
  }
  else if (cmd == "beam" || cmd == "bm") {
    beamLaser(1500);
  }
  else {
    Serial.println("Invalid command");
  }
  Serial.println();
}
