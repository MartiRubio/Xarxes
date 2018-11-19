#include <ESP8266WiFi.h>


// Dades de connexió a la xarxa WiFi
const char* ssid = "wifi_mota";
const char* password = "1234";

// 0 mode servidor, 1 mode client
const int mode = 0;


WiFiServer server(80);
WiFiClient client;

// Codi de configuració
void setup(){
    Serial.begin(9600);
    if(mode == 0){

        // Wifi en mode servidor
        WiFi.mode(WIFI_AP);
        WiFi.softAP(ssid, password);
    }
    else{

        // Wifi en mode client
        WiFi.mode(WIFI_STA);
        WiFi.disconnect();
    }
    delay(2000);
    Serial.println("Setup done");
    if(mode != 0){
        connectToWifi();
    }
}

// Bucle infinit que envia dades o espera a rebre dades
void loop(){
    if(mode == 0){
        WiFiClient client = server.available();
        // wait for a client (web browser) to connect
        if (client){
            JSON_rand_number = "{number: " + String(random(100)) + "}";
            Serial.println("\n[Client connected]");
            while (client.connected()){
                // read line by line what the client (web browser) is requesting
                if (client.available()){
                    client.println(JSON_rand_number);
                    break;
                }
            }
            delay(1); // give the web browser time to receive the data
            // close the connection:
            client.stop();
            Serial.println("[Client disonnected]");
        }
    }
    else{
        // Esperem a rebre dades
}


// En aquesta funció ens connectem a la xarxa amb els paràmetres desitjats.
void connectToWifi(void){
    if(WiFi.status() != WL_CONNECTED){
        WiFi.begin(ssid.c_str(),password.c_str());
        while(WiFi.status() != WL_CONNECTED){
            delay(1000);
            Serial.println("Connecting...");
            contador++;
            if(contador == 10){
                break;
            }
        }
        Serial.println(WiFi.localIP());
    }
}
