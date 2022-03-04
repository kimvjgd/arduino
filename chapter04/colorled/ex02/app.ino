// 1초 간격으로 색상을 랜덤하게 변경  ---> 무드등
// 10가지 색상을 정해서, 1초 간격으로 순차적으로 색상 바꾸기 !
// 버튼을 누르면 색상 변경 시간을 변경 0.5초 -> 1초 -> 2초

#include <SimpleTimer.h>
#include <ColorLed.h>
#include <Button.h>

SimpleTimer timer;
ColorLed colorLed(9, 10, 11);
Button btn(2);
const int COLOR_NUM = 10;
int colors[COLOR_NUM][3] = {
    {100, 0, 0},
    {0, 100, 0},
    {0, 0, 100},
    {255, 0, 0},
    {0, 255, 0},
    {0, 0, 255},
    {100, 100, 100},
    {200, 200, 200},
    {30, 100, 100},
    {100, 100, 30},
};
int color_index = -1;

int INTERVAL_NUM = 3;
int INTERVALS[] = {500, 1000, 2000};
int interval_index = 0;
int timer_id = -1; // 현재 가동중인 Timer의 ID
void check()
{
  color_index = (color_index + 1) % COLOR_NUM;
  // index1개의 1차원 배열의 포인터
  int *pcolor = colors[color_index];
  colorLed.rgb(pcolor[0], pcolor[1], pcolor[2]);
  // colorLed.random();
}
// 버튼의 콜백 함수
void change_interval()
{
  // 1. 기존 타이머 제거
  timer.deleteTimer(timer_id);
  // 2. interval_index 조정
  interval_index = (interval_index + 1) % INTERVAL_NUM;
  // 3. 타이머 재설정
  timer_id = timer.setInterval(INTERVALS[interval_index], check);
}
void setup()
{
  Serial.begin(115200);
  timer_id = timer.setInterval(INTERVALS[interval_index], check); // 이제 조정을 해야하니 대상을 알아야한다. id
  btn.setCallback(change_interval);
}
void loop()
{
  btn.check();
  timer.run();
}