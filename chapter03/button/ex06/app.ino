#include <Led.h>
#include <Button.h>

Led led(8);
Button btn(2);
boolean led_st = LOW;

int t1, t2;

void flash(void)
{
  // // 채터링 체 : 200ms 이내에 스위치가 또 눌려진 상태이면 무시
  // t2 = millis(); // 현재 시간 저장

  // // 인터럽트 시간 간격 체크
  // if ((t2 - t1) < 200) // 200ms 보다 작으면 무시
  //   return;            // 인터럽트 발생 시간 갱신
  // else
  //   t1 = t2;
  // count++;
  // Serial.println(count);
  if (!btn.debounce())
    return;
  led_st = !led_st;
  led.setValue(led_st);
}

void setup()
{
  // Serial.begin(115200);
  // pinMode(sw_pin, INPUT_PULLUP);
  // attachInterrupt(digitalPinToInterrupt(sw_pin), flash, FALLING);
  // t1 = millis(); // 프로그램 시작 시간 저장
  btn.attachInterrupt(flash);
}

void loop()
{
}