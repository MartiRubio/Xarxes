#include <ESP8266WiFi.h>
#include <WiFiClient.h> 

const char* ssid = "wifi_mobile";   // ssid of access point (Server)
const char* password = "1234";    // password of access point (Server)
int port = 80;                // port number

WiFiClient client;  // Declare client

void setup() 
{
    Serial.begin(9600);
    delay(10);

    WiFi.mode(WIFI_STA);  // set mode to station (client)

    // Connect to wiFi
    Serial.println(); Serial.println();
    Serial.println("CONNECTING TO WiFi");
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(500);
        Serial.print(".");  // print dots until connection
    }
    Serial.println();
    Serial.println("WiFi CONNECTED");
}

void loop() 
{
    // Connect client to server
    Serial.println("CONNECTING CLIENT TO SERVER");

    if (client.connect(ip, port)) 
    {
        Serial.println("CONNECTED");
    }
    else 
    {
        Serial.println("CONNECTION FAILED");
    }
    
    client.println();

    client.flush();

    delay(1);
    Serial.println("CLIENT DISCONNECTED");
    Serial.println();
    delay(5000); // delay 5 seconds
}
