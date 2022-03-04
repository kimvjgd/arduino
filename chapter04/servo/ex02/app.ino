#include <Analog.h>
#include <Servo.h>

Analog a_value(A0, 180, 0);

Servo myServo;
const int servo_pin = 5;

void setup()
{
  myServo.attach(servo_pin);
}

void loop()
{
  int angle = a_value.read();
  myServo.write(angle);
  delay(100);
}