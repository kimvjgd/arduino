#include <Led.h>
#include <MsTimer2.h>

boolean led_val = LOW;
Led led(8);

void setup()
{
  MsTimer2::set(500, flash);
  MsTimer2::start();
}

void loop()
{
}

void flash()
{
  led_val = !led_val;
  led.setValue(led_val);
}