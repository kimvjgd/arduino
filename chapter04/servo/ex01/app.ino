#include <MiniCom.h>
#include <Servo.h>

MiniCom com;
Servo myServo;
const int servo_pin = 5;

void setup()
{
  com.init();
  com.print(0, "Servo Test");
  myServo.attach(servo_pin);
}

void move_angle(int angle, int delay_time)
{
  myServo.write(angle);
  com.print(1, "Angle:", angle);
  delay(delay_time);
}

void loop()
{
  move_angle(0, 1000);
  move_angle(90, 1000);
  move_angle(180, 1000);
  move_angle(90, 1000);
}