void setup ()  
{  
  Serial.begin(9600);
  pinMode(A5, INPUT);
  pinMode(8, OUTPUT);
}

void loop ()  
{
  int flame_value = digitalRead(A5);

  if (flame_value == HIGH)
  {
    Serial.println("Flames Detected");
    digitalWrite(8, HIGH);
    delay(500);
    }
  else
  {
    Serial.println("No Flame Detected");
    digitalWrite(8, LOW);
    delay(500);
    }
}
