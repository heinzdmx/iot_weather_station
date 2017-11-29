#define VOLT_LEVEL 5.0

int MQ135_PIN = A2;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  float sensorVoltage = sensorValue/1024*VOLT_LEVEL; 
  float sensorValue = analogRead(MQ135_PIN);
 
  Serial.print("sensor voltage = ");
  Serial.print(sensorVoltage);
  Serial.println(" V");
  delay(1000);
}
