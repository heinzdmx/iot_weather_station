int MOISTURE_PIN = A1;
// you can adjust the threshold value
int thresholdValue = 800;

void setup(){
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(MOISTURE_PIN);
  Serial.print(sensorValue);
  if(sensorValue < thresholdValue){
    Serial.println(" - Doesn't need watering");
  }
  else {
    Serial.println(" - Time to water your plant");
  }
  delay(500);
}
