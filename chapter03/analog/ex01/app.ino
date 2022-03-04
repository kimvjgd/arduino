#include <SimpleTimer.h>

SimpleTimer timer;
const int var_pin = A0;
int anlog_val;

void setup()
{
  Serial.begin(115200);
  timer.setInterval(2000, check);
}

void loop()
{
  timer.run();
}

void check()
{
  int digital_val;
  float ff;

  digital_val = analogRead(var_pin);
  ff = (float)digital_val / 1023. * 5.0;

  Serial.print("Input Voltage(0~5V) = ");
  Serial.println(ff);

  Serial.print("Digital Value(0~1023) = ");
  Serial.println(digital_val);
  Serial.println("------------------------");
}
