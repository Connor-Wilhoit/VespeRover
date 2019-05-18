void startup_blink()
{
  for (int i=0; i < 6; ++i) {
    digitalWrite(led, HIGH);
    delay(75);
    digitalWrite(led, LOW);
    delay(75);
  }
}
