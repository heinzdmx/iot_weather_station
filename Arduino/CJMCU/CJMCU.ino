#define VOLT_LEVEL 5.0

int CJMCU_PIN = A3;

void setup() 
{
  Serial.begin(9600);
}
 
void loop() 
{
  float sensorVoltage; 
  float sensorValue;
 
  sensorValue = analogRead(CJMCU_PIN);
  sensorVoltage = sensorValue/1024*VOLT_LEVEL;
  Serial.print("sensor voltage = ");
  Serial.print(sensorVoltage, 2);
  Serial.println(" V");
  delay(1000);
}

