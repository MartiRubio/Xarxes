#include <ESP8266WiFi.h>

const char* ssid = "wifi_mobile";
const char* password = "t9rfepxq";

WiFiClient client;

const int channelID = XXX;
String writeAPIKey = "F519ZAH6GDRI03JL";

const char* server = "api.thingspeak.com";
const int postingInterval = 20*1000;

void loop(){
    if(client.connect(server, 80)){
        long rssi = WiFi.RSSI();

        String body = "field1";
               body += String(rssi);

        Serial.print("RSSI: ");
        Serial.println(rssi);

        client.println("POST /update HTTP/1.1");
        client.println("Host: api.thingspeak.com");
        client.println("User-Agent: ESP8266 (nothrans)/1.0");
        client.println("Connection: close");
        client.println("X-THINGSAPIKEY: " + writeAPIKey);
        client.println("Content-Type: application/x-www-form-urlencoded");
        client.println("Content-Length: " + String(body.length()));
        client.println("");
        client.println(body);

    }

    client.stop();
    delay(postingInterval);
}

