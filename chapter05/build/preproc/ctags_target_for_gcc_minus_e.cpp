# 1 "/Users/kimdonghyun/developer/arduino/chapter05/joystick/ex01/app.ino"
# 2 "/Users/kimdonghyun/developer/arduino/chapter05/joystick/ex01/app.ino" 2
# 3 "/Users/kimdonghyun/developer/arduino/chapter05/joystick/ex01/app.ino" 2
# 4 "/Users/kimdonghyun/developer/arduino/chapter05/joystick/ex01/app.ino" 2
# 5 "/Users/kimdonghyun/developer/arduino/chapter05/joystick/ex01/app.ino" 2

MiniCom com;
Analog x(A0, 0, 180); // 서보모터 방향을 제어
Analog y(A1, 100, -100); // rc카의 속도 및 방향제어
Button z(A2); //
Servo servo;

void check()
{
  int dx, dy;
  bool sw;

  dx = x.read();
  dy = y.read();
  sw = z.read();

  char buf[17];
  sprintf(buf, "%d ,%d [%d]", dx, dy, sw);
  com.print(1, buf);
  servo.write(dx);
}

void setup()
{
  com.init();
  com.setInterval(100, check);
  com.print(0, "[[Joystick]]");
  servo.attach(3);
}

void loop()
{
  com.run();
}
