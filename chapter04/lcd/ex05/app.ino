// 1초에 10번 가변 저항을 읽어서
// 가변 저항의 값을 lcd로 출력하세요

#include <SimpleTimer.h>
#include <Analog.h>
#include <LiquidCrystal_I2C.h>

SimpleTimer timer;
Analog sensor(A0, 1023, 0);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void check()
{
  // 저항값을 읽어서, lcd로 출력
  int value = sensor.read();
  // lcd.clear();  // 너무 깜빡거린다.
  lcd.setCursor(0, 1);

  char str[17]; // 1줄에 16글자로 가정하면, NULL 문자 포함 --> 17 크기
  sprintf(str, "value: %4d", value);

  lcd.print(str);
}

void setup()
{
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  timer.setInterval(100, check); // 100ms 간격
  String title = "[reg. value]"; // PC에서 c++ 문자열 객체: string
  lcd.setCursor(0, 0);
  lcd.print(title);
}

void loop()
{
  timer.run();
}