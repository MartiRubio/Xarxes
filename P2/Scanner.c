#include "ESP8266WiFi.h"

// Codi de configuració
void setup(){
    Serial.begin(9600);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(2000);
    Serial.println("Setup done");
}

// Codi que ens permet mostrar totes les xarxes disponibles amb la seva potència i si tenen seguretat o no
void loop(){
    Serial.println("Scan start");
    int n = WiFi.scanNetworks();
    Serial.println("Scan done");
    if(n == 0){
        Serial.println("No networks found");
    }
    else{
        for(int i=0; i<n; i++){
            Serial.print(i+1);
            Serial.print(WiFi.SSID(i));
            Serial.print("(");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*");
            delay(10);
        }
    }
    Serial.println("***************");
    delay(50000);
}
