/* This arduino code is sending data to mysql server every 30 seconds.

Created By Embedotronics Technologies*/

#include "DHT.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h> 
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SPI.h>

#define DHTPIN 4

#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

//



char* ssid = "Arnet_Jaktim";// 
char* password = "telkom135";
char* host = "10.237.120.146";   //eg: 192.168.0.222

// Set your Static IP address
IPAddress local_IP(10, 237, 27, 0);
// Set your Gateway IP address
IPAddress gateway(10, 237, 64, 1);

IPAddress subnet(255, 255, 0, 0);
IPAddress primaryDNS(8, 8, 8, 8); // optional
IPAddress secondaryDNS(8, 8, 4, 4); // optional

float humidityData;
float temperatureData;

WiFiClient client;    


void setup()
{
 Serial.begin(115200);
  delay(10);
  dht.begin();
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
  Serial.println("Starting WiFi");
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
//  server.begin();
  Serial.println("Server started");
  Serial.print(WiFi.localIP());
  delay(1000);
  Serial.println("connecting...");
 }
void loop(){ 
  humidityData = dht.readHumidity();
  temperatureData = dht.readTemperature();

//  WiFiClient client;    
//  const int httpPort = 80;
//  if(client.connect(host, httpPort)){
//    Serial.println("connection failed");
//    delay(1000);
//    return;
//  }
//  Serial.println("Client Connected!");
//  client.print(String("GET /kirimData.php?") +
//                      ("&suhu=") + temperatureData + 
//                      ("&kelembaban=") + humidityData + 
//                      " HTTP/1.1\r\n" +
//                "Host: " + host + "\r\n" +
//                "Connection: close\r\n\r\n");
//
//   unsigned long timeout = millis();
//   while (client.available() == 0){
//    if (millis() - timeout > 1000){
//      Serial.println(">>> Client Timeout !");
//      client.stop();
//      return;
//    }
//   }
//   Serial.println();
//   Serial.println("Closing Connection");
//   }
  
  Sending_To_phpmyadmindatabase(); 
  delay(1000); // interval
 }

 void Sending_To_phpmyadmindatabase()   //CONNECTING WITH MYSQL
 {
   if (client.connect(host, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    Serial.print("GET /php-arnouno-sensor/kirimData.php?suhu=");
    client.print("GET /php-arnouno-sensor/kirimData.php?suhu=");     //YOUR URL
    Serial.println(temperatureData);
    client.print(temperatureData);
    client.print("&kelembaban=");
    Serial.println("&kelembaban=");
    client.print(humidityData);
    Serial.println(humidityData);
    client.print(" ");      //SPACE BEFORE HTTP/1.1
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: 10.237.35.31");
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
 }
