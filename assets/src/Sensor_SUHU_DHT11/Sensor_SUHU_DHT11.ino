#include <DHT.h>
DHT dht(4, DHT11); //Pin, Jenis DHT
 
void setup(){
 Serial.begin(9600);
 dht.begin();
}
 
void loop(){
 float kelembaban = dht.readHumidity();
 float suhu = dht.readTemperature();

 Serial.print("kelembaban: ");
 Serial.print(kelembaban);
 Serial.print(" ");
 Serial.print("suhu: ");
 Serial.println(suhu);
 delay(1000);
}
