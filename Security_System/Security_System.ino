void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT);
  pinMode(13, OUTPUT); 

}

void loop() {
  bool pir = digitalRead(3);

  if (pir==1)
  {
    Serial.println("Motion Detected");
    digitalWrite(13, HIGH);
    delay(500);
  }
  if (pir==0)
  {
    Serial.println("No Motion");
    digitalWrite(13, LOW);
    delay(500);
  }

}