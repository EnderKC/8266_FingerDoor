#ifndef MYSERVO_H
#define MYSERVO_H
Servo myservo;     // 定义舵机对象
int pos = 0;       // 定义舵机转动位置
int servo_Pin = 4; // 舵机数据引脚

void myServo_init()
{
    myservo.attach(4);
}

void openDoor()
{
    myservo.write(0);
    delay(5000);
    myservo.write(180);
    delay(2000);
}
#endif