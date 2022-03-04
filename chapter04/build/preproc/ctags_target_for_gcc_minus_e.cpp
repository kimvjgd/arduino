# 1 "/Users/kimdonghyun/developer/arduino/chapter04/servo/ex03/app.ino"
// 버튼 1개 , 능동 부저 1개, 서보모터 1개
// 버튼 누르면 문열고
// 3초 후에 자동으로 닫힘
// 3초 전에 누르면 그 시점에서 3초 후에 닫힘(시간 연장)
// LCD에 현재 문 상태(OEN/CLOSE) 출력

# 8 "/Users/kimdonghyun/developer/arduino/chapter04/servo/ex03/app.ino" 2
# 9 "/Users/kimdonghyun/developer/arduino/chapter04/servo/ex03/app.ino" 2
# 10 "/Users/kimdonghyun/developer/arduino/chapter04/servo/ex03/app.ino" 2
# 11 "/Users/kimdonghyun/developer/arduino/chapter04/servo/ex03/app.ino" 2

MiniCom com;
Button btn(2);
Servo servo;

SimpleTimer timer;

const int buzzer_pin = 9;

int timer_id = -1;

const int OPEN = true;
const int CLOSE = false;

bool door_state = CLOSE;

void close_door()
{
  servo.write(0);
  door_state = CLOSE;
  com.print(1, "CLOSE");
}
void open_door()
{
  SimpleTimer &timer = com.getTimer();

  if (door_state == OPEN)
  {
    timer.restartTimer(timer_id);
  }
  else
  {
    servo.write(90);
    timer_id = timer.setTimeout(3000, close_door);
  }
  door_state = OPEN;
  com.print(1, "OPEN");
}
void setup()
{
  Serial.begin(115200);
  com.init();
  servo.attach(5);
  com.print(0, "[[MiniCom]]");

  btn.setCallback(open_door);
  close_door();
}
void loop()
{
  btn.check();
  com.run();
}
