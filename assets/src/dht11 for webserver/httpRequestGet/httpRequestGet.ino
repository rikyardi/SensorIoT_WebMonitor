#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include "DHT.h"

#define DHTPIN 4

#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

// Set your Static IP address
IPAddress local_IP(10, 237, 27, 0);
// Set your Gateway IP address
IPAddress gateway(10, 237, 64, 1);

IPAddress subnet(255, 255, 0, 0);
IPAddress primaryDNS(8, 8, 8, 8); // optional
IPAddress secondaryDNS(8, 8, 4, 4); // optional

/* Set these to your desired credentials. */
const char *ssid = "Arnet_Jaktim";  //ENTER YOUR WIFI SETTINGS
const char *password = "telkom135";

//Web/Server address to read/write from 
const char *host = "http://suhusensor.000webhostapp.com";   //https://circuits4you.com website or IP address of server

//=======================================================================
//                    Power on setup
//=======================================================================

void setup() {
  delay(1000);
  Serial.begin(115200);
  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");

  Serial.print("Connecting");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
}

//=======================================================================
//                    Main Program Loop
//=======================================================================
void loop() {
  HTTPClient http;    //Declare object of class HTTPClient
  
  String suhu, kelembaban, getData, Link, sto;
  float humidityData;
  float temperatureData;

  humidityData = dht.readHumidity();
  temperatureData = dht.readTemperature();
  
  suhu = String(temperatureData);   //String to interger conversion
  kelembaban = String(humidityData);
  sto = "jatinegara";

  //GET Data
  getData = "?suhu=" + suhu+ "&kelembaban=" + kelembaban + "&sto=" + sto;  //Note "?" added at front
  Link = "http://suhusensor.000webhostapp.com/kirimData.php" + getData;
  
  http.begin(Link);     //Specify request destination
  
  int httpCode = http.GET();            //Send the request
  String payload = http.getString();    //Get the response payload

  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload

  http.end();  //Close connection
  
  delay(5000);  //GET Data at every 5 seconds
}
//=======================================================================
