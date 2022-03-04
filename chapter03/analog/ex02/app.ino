#include "PWMLed.h"

PWMLed led(8);

void setup()
{
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, 0);
}

void loop()
{
  int pwm_val;

  for (pwm_val = 0; pwm_val < 256; pwm_val += 5)
  {
    led.setValue(pwm_val);
    delay(100);
  }
  led.off();
  delay(2000);
}