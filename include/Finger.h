#ifndef FINGER_H
#define FINGER_H
// 软串口 GPIO2 GPIO3
SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
// 指纹模块初始化
void finger_init()
{
    finger.begin(57600);
    delay(5);
    if (finger.verifyPassword())
    {
        Serial.println("找到指纹模块");
    }
    else
    {
        Serial.println("没有找到指纹模块");
        while (1)
        {
            Serial.println("等待指纹模块接入");
            delay(1);
        }
    }
    finger.getParameters();
    finger.getTemplateCount();
    if (finger.templateCount == 0)
    {
        Serial.print("传感器不包含任何指纹数据。 请运行“注册”示例。");
    }
    pinMode(D6, INPUT_PULLUP); // 设置引脚输入上拉
}
// 匹配指纹是否匹配
int getFingerprintID()
{
    uint8_t p = finger.getImage();
    if (p != FINGERPRINT_OK)
        return -1;

    p = finger.image2Tz();
    if (p != FINGERPRINT_OK)
        return -1;

    p = finger.fingerFastSearch();
    if (p != FINGERPRINT_OK)
        return -1;

    // found a match!
    Serial.print("Found ID #");
    Serial.print(finger.fingerID);
    Serial.print(" with confidence of ");
    Serial.println(finger.confidence);
    return finger.fingerID;
}
// 检查是否有手指放上去
void checkFinger()
{
    if (digitalRead(D6) == 1)
    {
        int result = getFingerprintID();
        if (result != -1)
        {
            openDoor();
        }
    }
}
#endif