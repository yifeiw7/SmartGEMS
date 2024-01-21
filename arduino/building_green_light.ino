int inputPin = 13;               // Connect sensor to input pin 3 
const int digitalOutPin1 = 41;
const int digitalOutPin2 = 7;
const int digitalOutPin3 = 9;
const int digitalOutPin4 = 8;
bool last_state = digitalRead(inputPin);
int state = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(inputPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(inputPin);
  if (state == 0){
    digitalWrite(digitalOutPin1, LOW);
    digitalWrite(digitalOutPin2, LOW);
    digitalWrite(digitalOutPin3, LOW);
    digitalWrite(digitalOutPin4, LOW);
    if (last_state != val){
      last_state = val;
      if (last_state == HIGH){
        state = 1;
      } else {
        state = 0;
      }
    }
  }
  else if (state == 1){
    digitalWrite(digitalOutPin1, HIGH);
    digitalWrite(digitalOutPin2, HIGH);
    digitalWrite(digitalOutPin3, LOW);
    digitalWrite(digitalOutPin4, LOW);
    if (last_state != val){
      last_state = val;
      // printf("here");
      if (last_state == HIGH){
        // printf("in");
        state = 2;
      } else {
        state = 1;
      }
    }
  }
  else if (state == 2){
    digitalWrite(digitalOutPin1, HIGH);
    //Serial.print(digitalRead(digitalOutPin1));
    digitalWrite(digitalOutPin2, HIGH);
    digitalWrite(digitalOutPin3, HIGH);
    digitalWrite(digitalOutPin4, HIGH);
    if (last_state != val){
      last_state = val;
      if (last_state == HIGH){
        state = 0;
      } else {
        state = 2;
      }
    }
  }
  delay(2);
}
