const int buzzer_pin = 9;

void setup()
{
  pinMode(buzzer_pin, OUTPUT);
}

void loop()
{
  digitalWrite(buzzer_pin, HIGH);
  delay(200);

  digitalWrite(buzzer_pin, LOW);
  delay(300);
}
