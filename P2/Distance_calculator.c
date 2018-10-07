#include "ESP8266WiFi.h"

void setup(){
    Serial.begin(9600);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(2000);
    Serial.println("Setup done");
}

void loop(){
    Serial.println("Press any key");
    stringEntered = "";
    while(stringEntered == ""){
        stringEntered = Serial.readString();
    }
    for(int j = 0; j < 20; j++){
        int n = WiFi.scanNetworks();
        for(i=0; i<n; i++){
            if(WiFi.SSID(i) == "wifi_mobile"){
                Serial.print(WiFi.RSSI(i));
            }
            else{
                Serial.print("NaN");
            }
            Serial.print(",");
            delay(1000);
        }
    }
}
