#define pirSensor 3
#define flameLED 8
#define pirLED 12
#define gasLED 13
#define flameSensor A5
#define gasSensor A0

void setup() {
  Serial.begin(9600);
  pinMode(pirSensor, INPUT);
  pinMode(flameSensor, INPUT);
  pinMode(gasSensor, INPUT);
  pinMode(flameLED, OUTPUT);
  pinMode(pirLED, OUTPUT);
  pinMode(gasLED, OUTPUT);
}

void loop ()  
{
  int flame_value = digitalRead(flameSensor);
  int pir_value = digitalRead(pirSensor);
  int gas_value = digitalRead(gasSensor);

  if (flame_value == HIGH) {
    Serial.println("FLAMES DETECTED");
    digitalWrite(flameLED, HIGH);
  }
  else {
    Serial.println("No Flame Detected");
    digitalWrite(flameLED, LOW);
  }

  if (pir_value == HIGH) {
    Serial.println("MOTION DETECTED");
    digitalWrite(pirLED, HIGH);
  }
  else {
    Serial.println("No Motion Detected");
    digitalWrite(pirLED, LOW);
  }

  if (gas_value == HIGH) {
    Serial.println("GAS DETECTED");
    digitalWrite(gasLED, HIGH);
  }  
  else {
    Serial.println("No Gas Detected");
    digitalWrite(gasLED, LOW);
  }

  delay(500);
}
