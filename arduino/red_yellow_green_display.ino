const int red = 2;
const int yellow = 3;
const int green = 4;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(green, HIGH);
  delay(3000);
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(3000);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  delay(3000);
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
  delay(3000);
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  delay(3000);
  digitalWrite(yellow, LOW);

}
