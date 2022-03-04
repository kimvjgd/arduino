#include <MiniCom.h>
#include <Button.h>
#include <Melody.h>
#include <songs/pirates.h>

int length = sizeof(notes) / sizeof(int);
Melody melody(9, notes, durations, length);

MiniCom com;
Button btn(2);

void check()
{
  bool bplay = melody.toggle(true); // true 이어서 재생 , false이면 처음부터 연주
  if (bplay)
  {
    com.print(1, "play");
  }
  else
  {
    com.print(1, "pause");
  }
}

void setup()
{
  com.init();
  btn.setCallback(check);
  melody.play();
  com.print(0, "[[MiniCom]]");
  com.print(1, "play");
}

void loop()
{
  com.run();
  melody.run();
  btn.check();
}