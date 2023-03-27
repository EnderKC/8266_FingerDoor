int servo_Pin = 4;
void openDoor()
{
    for (int dutyCycle = 0; dutyCycle < 1023; dutyCycle++)
    {
        // 通过PWM改变LED亮度
        analogWrite(servo_Pin, dutyCycle);
        delay(10);
    }
}
void closeDoor()
{
}