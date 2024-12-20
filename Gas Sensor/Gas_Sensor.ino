void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(12, OUTPUT);

}

void loop() {

  int gas_value = digitalRead(A0);

  if(gas_value==HIGH)
  {
    Serial.println("Gas Detected");
    digitalWrite(12, HIGH);
    delay(500);
    }
  else
  {
    Serial.println("No Gas Detected");
    digitalWrite(12, LOW);
    delay(500);
    }
  

}