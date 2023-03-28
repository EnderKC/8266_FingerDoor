#include <Arduino.h>
#include <Adafruit_Fingerprint.h>
#include <WiFiUdp.h>
#include <ESP8266WiFi.h>
#include <WiFiManager.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>
#include <Servo.h>
#include <string>
#include "Myservo.h"
#include "Finger.h"
#include "ConnectWIFI.h"
#include "Mymqtt.h"

/*

==更新日志==
<2023-3-28>
1. 完成主体部分
<2023-3-27>
2. 优化部分代码，封装部分函数，提高代码复用性
<2023-3-28>
3. 更新部分代码

*/

void setup()
{
    Serial.begin(115200);
    delay(100);
    initWifiManager(); // 链接wifi
    finger_init();     // 指纹模块初始化
    myServo_init();    // 舵机模块初始化
    myMqtt_init();
}

void loop()
{
    checkFinger();
    client.loop();
}
