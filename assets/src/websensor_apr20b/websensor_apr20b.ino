#include <DHT.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

DHT dht(5, DHT11);
//setting jaringan
const char* ssid = "Berkah";
const char* password = "qwerty123";
const char* host = "192.168.43.2";//ip server


void setup() {
Serial.begin(9600);
//konekasi WiFi
WiFi.hostname("NodeMCU");
WiFi.begin(ssid, password);

  while(WiFi.status() !=WL_CONNECTED){//saat tidak terkoneksi !
  Serial.print(".");//mencoba konekasi
  delay(500);    
  }
  //done connect
  Serial.println("WiFi Connected");
  
}

void loop() {
  float suhu = dht.readTemperature();
  float kelembaban = dht.readHumidity();
  Serial.println(suhu);
  Serial.println(kelembaban);
  //cek koneksi ke server
  WiFiClient client;
  if(!client.connect(host,80)){
    Serial.println("Connection Failed");
    return;
  }
  //proses kirim data to server
  String Link;
  HTTPClient http;
  Link = "http://10.237.30.119/ArnoUno_sensor/kirimData.php?suhu=" + String(suhu);
  http.begin(Link);
  http.GET();
  
  delay(1000);
}
