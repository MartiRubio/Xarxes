#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

const char* ssid = "wifi_mobile";       // ssid of server (Access Point (AP))
const char* password = "1234";        // password of server (Access Point (AP))
WiFiServer server(80);            //Service Port

void setup() 
{
    delay(1000);
    Serial.begin(9600);    // to use tools->serial monitor

    pinMode(ledPin, OUTPUT);   // set GPIO 2 as an output

    WiFi.mode(WIFI_AP_STA);  // Set WiFi to AP and station mode

    // Connect to the WiFi network
    Serial.println();
    Serial.print("Connecting to: "); Serial.println(ssid);
    WiFi.softAP(ssid, password);

    // Display the server address
    Serial.print("Connected, My address: ");
    Serial.print("http://");
    Serial.print(WiFi.softAPIP());
    Serial.println("/");

    // Tell the server to begin listening for incoming connections
    server.begin();
    Serial.println("Server listening for incoming connections");
}  

void loop() 
{
    // Check if a client has connected
    WiFiClient client = server.available();
    if (client) // if not available, return
    {
        JSON_rand_number = "{number: " + String(random(100)) + "}";
            Serial.println("\n[Client connected]");
            while (client.connected()){
                // read line by line what the client (web browser) is requesting
                if (client.available()){
                    client.println(JSON_rand_number);
                    break;
                }
    }

    client.flush();
    Serial.println("Client disconnected");
}
