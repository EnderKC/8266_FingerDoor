#ifndef CONNECTWIFI_H
#define CONNECTWIFI_H

void initWifiManager()
{
    WiFiManager wifiManager;

    //调试用
    // wifiManager.resetSettings();
    // ESP.eraseConfig();

    // 打印调试内容
    wifiManager.setDebugOutput(true);
    if (!wifiManager.autoConnect("FingerDoorWifi"))
    {
        Serial.println("failed to connect and hit timeout");
        // reset and try again, or maybe put it to deep sleep
        ESP.reset();
        delay(1000);
    }
    Serial.println("local ip");
    Serial.println(WiFi.localIP());
}

#endif