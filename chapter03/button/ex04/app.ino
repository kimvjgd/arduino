#include <Led.h>

const int OFF = 0;
const int ON = 1;

const int sw_pin = 2;
Led leds[4] = {
    Led(8), Led(9), Led(10), Led(11)};

int out_no = -1;

void setup()
{
  Serial.begin(115200);
  pinMode(sw_pin, INPUT_PULLUP);
}

void loop()
{
  boolean o_sw, n_sw;
  o_sw = !digitalRead(sw_pin);
  delay(10);
  n_sw = !digitalRead(sw_pin);

  if (o_sw == OFF && n_sw == ON)
  {
    move_led();
  }
}

void move_led()
{
  out_no = (++out_no) % 4;
  Serial.println(out_no);
  for (int n = 0; n < 4; n++)
  {
    leds[n].setValue(n == out_no);
  }
}