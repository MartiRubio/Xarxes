#include <ESP8266WiFi.h>


// Dades de connexió a la xarxa WiFi
const char* ssid = "wifi_mobile";
const char* password = "t9rfepxq";

WiFiClient client;


// Dades de connexió a la API
const int channelID = 623430;
String writeAPIKey = "3DJ9KMQGRMNTYST0";

const char* server = "api.thingspeak.com";
const int postingInterval = 20*1000;


// Codi de configuració
void setup(){
    Serial.begin(9600);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(2000);
    Serial.println("Setup done");
    wifiNetworkSelection();
    connectToWifi();
}

void loop(){
    // Si estem connectats al servidor
    if(client.connect(server, 80)){

        // Calculem el valor RSSI
        long rssi = WiFi.RSSI();

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

// En aquest codi seleccionem el nom i la contrasenya de la xarxa a la que ens volem connectar.
void wifiNetworkSelection(void){
    if(WiFi.status() != WL_CONNECTED){
        Serial.print("SSID? >");
        while(!Serial.available());
        ssid = Serial.readString();
        Serial.print("SSID selected >");
        Serial.println(ssid);
        delay(1000);
        Serial.print("Password? >");
        while(!Serial.available());
        password = Serial.readString();
        Serial.print("Password >");
        Serial.println(password);
        delay(1000);
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
