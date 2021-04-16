#include <DHT.h>

#define DHT_PIN 8
#define DHTTYPE DHT11
DHT dht(DHT_PIN, DHTTYPE);

float humidity, temp;

void setup() {
  Serial.begin(9600);
  dht.begin();  
}

void loop() {
  //req nodemcu
  String request = "";
  //read nodemcu
  while(Serial.available()>0){
    request += char(Serial.read());
  }
  request.trim();

  if(request == "Ya"){
    kirimdata();
  }
  request = "";
  delay(1000);
//  Serial.println(ldr);
//  Serial.println(humidity);
//  Serial.printin(temp);
//  delay(1000);
}

void kirimdata(){
  humidity = dht.readHumidity();
  temp = dht.readTemperature();

  String datasend = String(temp) + "#" + String(humidity);

  Serial.println(datasend);
  
}
