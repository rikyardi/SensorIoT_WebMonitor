#include <SoftwareSerial.h>

SoftwareSerial DataSerial(12, 13);
//millis change delay
unsigned long previousMillis = 0;
const long interval = 3000;
String arryData[3];
void setup() {
  Serial.begin(9600);
  DataSerial.begin(9600);
}

void loop() {
  //konfigurasi millis
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    String data = "";
    while(DataSerial.available()>0){
      data += char(DataSerial.read());
    }//buang spasi
    data.trim();
    //uji data
    if(data != ""){
      int index = 0;
      for(int i=0; i<= data.length(); i++){
        char delimiter = '#';
        if(data[i] != delimiter)
          arryData[index] += data[i];
        else
          index++;
      }
      //pastikan data
      if(index == 1){
        //tampil nilai
        Serial.println("Humidity : " + arryData[0]);
        Serial.println("Temperature : " + arryData[1]);
        
      }
      arryData[0] = "";
      arryData[1] = "";
    }
    //minta data ke uno
    DataSerial.println("Ya");
  }
}
