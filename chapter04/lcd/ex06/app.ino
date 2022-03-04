#include <MiniCom.h>
#include <Analog.h>

Analog sensor(A0, 1023, 0);
MiniCom com;

void check()
{

  int value = sensor.read();

  com.print(1, "value: ", value);
}

void setup()
{
  com.init();
  com.print(0, "[[MiniCom]]");
  com.setInterval(100, check);
}

void loop()
{
  com.run();
}
