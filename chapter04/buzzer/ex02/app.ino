#include <Pitches.h>
#define NUM 49
int melody[NUM] = { // 곰 세마리
    // 도도도도도 // 미솔솔미도
    NOTE_C4, NOTE_C4, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4, NOTE_C4, NOTE_C4,
    NOTE_G4, NOTE_G4, NOTE_E4,
    NOTE_G4, NOTE_G4, NOTE_G4,
    NOTE_G4, NOTE_G4, NOTE_E4,
    NOTE_G4, NOTE_G4, NOTE_G4,
    NOTE_C4, NOTE_C4,
    NOTE_E4, NOTE_C4,
    NOTE_G4, NOTE_G4, NOTE_E4, // 솔솔미솔솔미
    NOTE_C4,
    NOTE_C4,
    // 솔솔미도 // 솔솔솔
    // 솔솔미도 // 솔솔솔
    NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4,          // 솔솔미도
    NOTE_G4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, // 솔솔솔라솔
    NOTE_C5, NOTE_G4, NOTE_C5, NOTE_G4,          // 도솔도솔
    NOTE_E4, NOTE_D4, NOTE_C4};                  // 미레도
// 음표 길이
int noteDuration[NUM] = {
    4, 8, 8, 4, 4, 4, 8, 8, 4, 4, 8, 8, 4, 8, 8, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2,
    4, 4, 4, 4, 8, 8, 8, 8, 2, 4, 4, 4, 4, 4, 4, 2};
const int speaker_pin = 9;
void setup()
{
  pinMode(speaker_pin, OUTPUT);
}
void loop()
{
  int m, d, dd;
  for (m = 0; m < NUM; m++)
  {
    d = 1000 / noteDuration[m];
    dd = d * 1.3; // 음 출력 시간(4분 음표 325ms)
    tone(speaker_pin, melody[m], d);
    delay(dd);
  }
  delay(1000);
}