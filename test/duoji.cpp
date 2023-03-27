#include <Arduino.h>
#include <Servo.h>
#include <SoftwareSerial.h>

Servo myservo;   // 定义舵机对象
int pos = 0;     // 定义舵机转动位置
void setup()
{
    myservo.attach(4);   // 设置舵机控制针脚接数字12引脚


    pos = 90;
    myservo.write(pos);
}
void loop()
{
    myservo.write(0);
    delay(2000);

    myservo.write(180);
    delay(2000);
}