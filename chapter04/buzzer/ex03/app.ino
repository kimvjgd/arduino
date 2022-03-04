#include <Melody.h>
#include <songs/pirates.h>

int length = sizeof(notes) / sizeof(int);
Melody melody(9, notes, durations, length);

void setup()
{
  melody.play();
}

void loop()
{
  melody.run();
}