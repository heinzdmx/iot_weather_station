int WATERLEVEL_PIN = A0; // level sensor connected to an analog port
int sensorValue = 0; // define a variable data initial value if 0

void setup() {
  Serial.begin(9600); // set the baud rate to 9600  
}

void loop() {
  sensorValue = analogRead(WATERLEVEL_PIN); // read the analog value to the variable val

  Serial.print(sensorValue);
  
  if (sensorValue > 700) {
    Serial.println(" - Dry");
  }
  else {
    Serial.println(" - Wet");
  }

  delay(1000);
}
