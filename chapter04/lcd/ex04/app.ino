#include <LiquidCrystal_I2C.h>

uint8_t name_k[8] = {B11101, B00101, B01001, B10001, B00000, B01111, B01001, B01111};
uint8_t name_d[8] = {B11111, B10000, B11111, B00100, B11111, B01110, B10001, B01110};
uint8_t name_h[8] = {B01001, B11101, B01011, B10101, B01011, B00001, B01000, B01111};

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.init();

  lcd.createChar(0, name_k);
  lcd.createChar(1, name_d);
  lcd.createChar(2, name_h);
}

void loop()
{
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0); // 커서 2행 1열(0, 1)
  lcd.backlight();
  lcd.print("Hello, Arduino!"); // 문자열 표시
  lcd.setCursor(0, 1);
  lcd.print("My name is ");
  lcd.write(0);
  lcd.write(1);
  lcd.write(2);
}