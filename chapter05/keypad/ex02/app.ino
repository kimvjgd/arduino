#include <MiniCom.h>
#include <NumberPad.h>
#include <Servo.h>

Servo servo;
MiniCom com;
NumberPad keypad;
String input = "";
String dumy_input = "";
bool b_input = false;

int timer_id = -1;
int timer_id1 = -1;
const String PASSWORD = "115200";

void open_door()
{
  servo.write(90);
  timer_id1 = com.getTimer().setTimeout(5000, close_door);
}

void close_door()
{
  servo.write(0);
  timer_id1 = -1;
}

void cancel_input()
{
  b_input = false;
  input = "";
  dumy_input = "";
  com.print(1, "");
  timer_id = -1;
}

void start_input()
{
  b_input = true;
  input = "";
  dumy_input = "";
  timer_id = com.getTimer().setTimeout(5000, cancel_input);
  com.onLcd();
}

void end_input()
{
  b_input = false;
  Serial.print("입력완료:");
  Serial.println(input);
  if (input == PASSWORD)
  {
    open_door();
  }
  else
  {
    // 경고음
  }

  com.print(1, "");
  com.getTimer().deleteTimer(timer_id);
  timer_id = -1;
  com.offLcd();
}
void key_input(char key)
{
  input += key;
  dumy_input += '*';
  com.print(1, dumy_input.c_str());
  com.getTimer().restartTimer(timer_id); // 취소 연장
}
void key_process(char key)
{
  if (key == '*')
  {
    start_input();
  }
  else if (key == '#')
  {
    end_input();
  }
  else if (key && b_input)
  {
    key_input(key);
  }
}
void setup()
{
  com.init();
  com.offLcd();
  com.print(0, "[[Keypad Test]]");
  servo.attach(3);
  servo.write(0);
}
void loop()
{
  com.run(); // software 타이머... 런을 빠뜨리면 안된다.
  char key = keypad.getKey();
  key_process(key);
}