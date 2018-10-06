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

void wifiNetworkSelection(void){
    if(WiFi.sttus() != WL_CONNECTED){
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