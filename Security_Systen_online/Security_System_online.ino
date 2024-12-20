#define pirSensor 3
#define flameLED 8
#define pirLED 12
#define gasLED 13
#define flameSensor A5
#define gasSensor A0

#include <Ethernet.h>  
#include <MQTT.h>  
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
byte ip[] = {192, 168, 1, 177}; 
EthernetClient net;  
MQTTClient client;  
unsigned long lastMillis = 0; 

void connect() {  
  Serial.print("connecting...");
  while (!client.connect("arduino", "hivemq.webclient.1734729261203", "G6y&l70e%U1Bt:CSj#Os")) {  
    Serial.print(".");  
    delay(1000);  
  }  
  Serial.println("\nconnected!");  
  client.subscribe("sensors/#");   
}
  
void messageReceived(String &topic, String &payload) {  
  Serial.println("incoming: " + topic + " - " + payload);  
}  

void setup() {
  Serial.begin(9600);
  pinMode(pirSensor, INPUT);
  pinMode(flameSensor, INPUT);
  pinMode(gasSensor, INPUT);
  pinMode(flameLED, OUTPUT);
  pinMode(pirLED, OUTPUT);
  pinMode(gasLED, OUTPUT);

  Ethernet.begin(mac);
  client.begin("7d21f04822a54190b282914f7448d707.s1.eu.hivemq.cloud", 8883, net); 
  client.onMessage(messageReceived);  
  connect();  
}


void loop ()
{
  client.loop();
  if (!client.connected()) {     
    connect();  
  }


  int flame_value = digitalRead(flameSensor);
  int pir_value = digitalRead(pirSensor);
  int gas_value = digitalRead(gasSensor);

  if (flame_value == HIGH) {
    Serial.println("FLAMES DETECTED");
    digitalWrite(flameLED, HIGH);
    if (millis() - lastMillis > 1000) {     
      lastMillis = millis();  
      client.publish("sensors/flame", "FLAMES DETECTED");
    } 
  }
  else {
    Serial.println("No Flame Detected");
    digitalWrite(flameLED, LOW);
  }

  if (pir_value == HIGH) {
    Serial.println("MOTION DETECTED");
    digitalWrite(pirLED, HIGH);
    if (millis() - lastMillis > 1000) {     
      lastMillis = millis();  
      client.publish("sensors/motion", "MOTION DETECTED");
    }
  }
  else {
    Serial.println("No Motion Detected");
    digitalWrite(pirLED, LOW);
  }

  if (gas_value == HIGH) {
    Serial.println("GAS DETECTED");
    digitalWrite(gasLED, HIGH);
    if (millis() - lastMillis > 1000) {     
      lastMillis = millis();  
      client.publish("#sensors/gas", "GAS DETECTED");
    }
  }  
  else {
    Serial.println("No Gas Detected");
    digitalWrite(gasLED, LOW);
  }

  delay(500);

  
  
}  


