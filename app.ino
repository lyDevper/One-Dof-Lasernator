
void app() {  // To be called in void loop()
  Serial.println("Please enter the command. The existing commands are:");
  Serial.println("todeg <float>");
  Serial.println("bydeg <float>");
  Serial.println("tostep <int>");
  Serial.println("bystep <int>");
  Serial.println("tohole <int>");
  Serial.println("byhole <int>");
  Serial.println("setdeg <float>");
  Serial.println("setstep <int>");
  Serial.println("homezero");
  Serial.println("tolimsw");
  Serial.println("laseron");
  Serial.println("laseroff");
  Serial.println("beam");

  waitForSerialInp();
  String cmd = Serial.readStringUntil('\n');

  if (cmd == "todeg") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    float para = Serial.parseFloat();
    // Handle the todeg command with 'para' value
  }
  else if (cmd == "bydeg") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    float para = Serial.parseFloat();
    // Handle the bydeg command with 'para' value
  }
  else if (cmd == "tostep") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    int para = Serial.parseInt();
    // Handle the tostep command with 'para' value
  }
  else if (cmd == "bystep") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    int para = Serial.parseInt();
    // Handle the bystep command with 'para' value
  }
  else if (cmd == "tohole") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    int para = Serial.parseInt();
    // Handle the tohole command with 'para' value
  }
  else if (cmd == "byhole") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    int para = Serial.parseInt();
    // Handle the byhole command with 'para' value
  }
  else if (cmd == "setdeg") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    float para = Serial.parseFloat();
    // Handle the setdeg command with 'para' value
  }
  else if (cmd == "setstep") {
    Serial.println("Please enter parameter : ");
    waitForSerialInp();
    int para = Serial.parseInt();
    // Handle the setstep command with 'para' value
  }
  else if (cmd == "homezero") {
    // Handle the homezero command
  }
  else if (cmd == "tolimsw") {
    // Handle the tolimsw command
  }
  else if (cmd == "laseron") {
    // Handle the laseron command
  }
  else if (cmd == "laseroff") {
    // Handle the laseroff command
  }
  else if (cmd == "beam") {
    // Handle the beam command
  }
  else {
    Serial.println("Invalid command");
  }
}