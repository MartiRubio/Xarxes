#include <ESP8266WiFi.h>

// const char* 
String ssid = "wifi_mobile";
// const char*
String password = "t9rfepxq";

WiFiClient client;

const int channelID = 623430;
String writeAPIKey = "PQRN1CTIY9RDMYVZ";

const char* server = "api.thingspeak.com";
const int postingInterval = 20*1000;

// Codi de configuració
void setup(){
    Serial.begin(9600);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(2000);
    Serial.println("Setup done");
    connectToWifi();
}

void loop(){
    if(client.connect(server, 80)){
        long rssi = WiFi.RSSI();

        String body = "field1=";
               body += String(rssi);

        Serial.print("RSSI: ");
        Serial.println(rssi);

        client.println("POST /update HTTP/1.1");
        client.println("Host: api.thingspeak.com");
        client.println("User-Agent: ESP8266 (nothans)/1.0");
        client.println("Connection: close");
        client.println("X-THINGSPEAKAPIKEY: " + writeAPIKey);
        client.println("Content-Type: application/x-www-form-urlencoded");
        client.println("Content-Length: " + String(body.length()));
        client.println("");
        client.print(body);

    }

    client.stop();
    delay(postingInterval);
}


// En aquesta funció ens connectem a la xarxa amb els paràmetres desitjats.
void connectToWifi(void){
  int contador = 0;
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