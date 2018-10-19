#include "ESP8266WiFi.h"

// Codi de configuració
void setup(){
    Serial.begin(9600);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(2000);
    Serial.println("Setup done");
}

// En aquesta funció mesurem la potència del wifi en 20 ocasions diferents
void loop(){
    //Quan es pitja una tecla, comença a escanejar
    Serial.println("]\nPress any key\n[");
    stringEntered = "";
    while(stringEntered == ""){
        stringEntered = Serial.readString();
    }
    // Durant 20 cicles, busca tots els wifis i imprimeix la potència del WiFi del meu mòbil (anomenat "wifi_mobile")
    for(int j = 0; j < 20; j++){
        found = false;
        int n = WiFi.scanNetworks();
        for(i=0; i<n; i++){
            if(WiFi.SSID(i) == "wifi_mobile"){
                Serial.print(WiFi.RSSI(i));
                found = true;
            }
        }
        // Si no el troba, retorna un not a number per a numpy per a la posterior anàlisi de les dades en el Jupyter Notebook.
        if(!found){
            Serial.print("np.nan");
        }
        Serial.print(",");
        delay(1000);
    }
}
