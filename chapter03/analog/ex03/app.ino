#include <PWMLed.h>
#include <Analog.h>

Analog sensor(A0, 255, 0);
PWMLed led(9);

void setup()
{
}

void loop()
{
  int pwm_val = sensor.read();

  led.setValue(pwm_val);
}