#include <ESP8266WiFi.h>


// Dades de connexió a la xarxa WiFi
const char* ssid = "wifi_mota";
const char* password = "1234";

const int mode = 0;

unsigned char number_client;

String JSON_rand_number;

long randNumber;

WiFiServer server(80);

// Codi de configuració
void setup(){
    Serial.begin(9600);
    if(mode == 0){
        WiFi.mode(WIFI_AP);
        WiFi.softAP(ssid, password);
    }
    else{
        WiFi.mode(WIFI_STA);
        WiFi.disconnect();
    }
    delay(2000);
    Serial.println("Setup done");
    if(mode != 0){
        connectToWifi();
    }
}



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
        // Si estem connectats al servidor
        if(client.connect(server, 80)){

            Serial.println("Number Sent: %l", randNumber);

            // L'afegim al body de la petició HTTP
            String body = "field1";
                   body += String(rssi);

            Serial.print("RSSI: ");
            Serial.println(rssi);

            // Fem la petició HTTP POST al servidor
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

        // Ens desconnectem del servidor
        client.stop();
        delay(postingInterval);
    }
}


// En aquesta funció ens connectem a la xarxa amb els paràmetres desitjats.
void connectToWifi(void){
    if(WiFi.status() != WL_CONNECTED){
        WiFi.begin(c_ssid,c_pwd);
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
