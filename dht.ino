#include "dht.h"
#define dhtpin 1
#define pb 2 
#define led 3
void setup() {
  Serial.begin(9600);
  pinMode(pb,INPUT);
  pinMode(led,OUTPUT);
  dht.begin();
  

}

void loop() {
  delay(1000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  
  if digitalRead(pb)==HIGH){
    Serial.print(hic);
    Serial.println("'F");
    
  }
  if(t<20){
    digitalWrite(led,HIGH);
  }


  
}
