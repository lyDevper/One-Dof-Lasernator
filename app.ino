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
  Serial.println("\tohole <int> or th <int>");
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
    // Handle the bydeg command with 'para' value
  }
  else if (cmd == "tostep" || cmd == "ts") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    int para = Serial.parseInt();
    // Handle the tostep command with 'para' value
  }
  else if (cmd == "bystep" || cmd == "bs") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    int para = Serial.parseInt();
    // Handle the bystep command with 'para' value
  }
  else if (cmd == "tohole" || cmd == "th") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    int para = Serial.parseInt();
    // Handle the tohole command with 'para' value
  }
  else if (cmd == "byhole" || cmd == "bh") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    int para = Serial.parseInt();
    // Handle the byhole command with 'para' value
  }
  else if (cmd == "setdeg" || cmd == "sd") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    float para = Serial.parseFloat();
    // Handle the setdeg command with 'para' value
  }
  else if (cmd == "setstep" || cmd == "ss") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    int para = Serial.parseInt();
    // Handle the setstep command with 'para' value
  }
  else if (cmd == "homezero" || cmd == "hz") {
    // Handle the homezero command
  }
  else if (cmd == "tolimsw" || cmd == "tl") {
    // Handle the tolimsw command
  }
  else if (cmd == "laseron" || cmd == "ln") {
    // Handle the laseron command
  }
  else if (cmd == "laseroff" || cmd == "lf") {
    // Handle the laseroff command
  }
  else if (cmd == "beam" || cmd == "bm") {
    // Handle the beam command
  }
  else {
    Serial.println("Invalid command");
  }
  Serial.println();  
}