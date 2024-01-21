#include <dht11.h>
#include <LiquidCrystal.h>
#include <LedControl.h>
#include <binary.h>

DHT11 DHT(43);

const int rs = 25, en = 27, d4 = 29, d5 = 31, d6 = 33, d7 = 35;
// const int rs = 33, en = 31, d4 = 29, d5 = 27, d6 = 25, d7 = 23;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//5 4 43 41
const int light, water, soil, humidity, temperature; 
int val = 0;
int inputPin = 13;               // Connect sensor to input pin 3 
const int digitalOutPin1 = 41;
const int digitalOutPin2 = 7;
const int digitalOutPin3 = 9;
const int digitalOutPin4 = 8;
const int red = 2;
const int yellow = 3;
const int green = 4;
bool last_state = digitalRead(inputPin);
int state = 0;

LedControl lc=LedControl(10,12,11,1);

// delay time between faces
//unsigned long delaytime=1000;

byte he[1]= {B11111111};

void setup(){
  pinMode(inputPin, INPUT);     // declare pushbutton as input
  // Serial.println("DHT TEST PROGRAM ");
  // Serial.print("LIBRARY VERSION: ");
  // Serial.println();
  // Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
  lcd.begin(16, 2);
  Serial.begin(9600);

  lc.shutdown(0,false);
  // Set brightness to a medium value
  lc.setIntensity(0,1);
  // Clear the display
  lc.clearDisplay(0);  
}

void drawFaces(){
  if (val == 0){
    lc.setRow(0,0,0);
    lc.setRow(0,1,0);
    lc.setRow(0,2,0);
    lc.setRow(0,3,0);
    lc.setRow(0,4,0);
    lc.setRow(0,5,0);
    lc.setRow(0,6,0);
    lc.setRow(0,7,0);
    //delay(delaytime);
  }
  else if (val == 1){
    lc.setRow(0,0,he[0]);
    lc.setRow(0,1,0);
    lc.setRow(0,2,0);
    lc.setRow(0,3,0);
    lc.setRow(0,4,0);
    lc.setRow(0,5,0);
    lc.setRow(0,6,0);
    lc.setRow(0,7,0);
    //delay(delaytime);
  }
  else if (val == 2){
    lc.setRow(0,0,he[0]);
    lc.setRow(0,1,he[0]);
    lc.setRow(0,2,0);
    lc.setRow(0,3,0);
    lc.setRow(0,4,0);
    lc.setRow(0,5,0);
    lc.setRow(0,6,0);
    lc.setRow(0,7,0);
    //delay(delaytime);
  }
  else if (val == 3){
    lc.setRow(0,0,he[0]);
    lc.setRow(0,1,he[0]);
    lc.setRow(0,2,he[0]);
    lc.setRow(0,3,0);
    lc.setRow(0,4,0);
    lc.setRow(0,5,0);
    lc.setRow(0,6,0);
    lc.setRow(0,7,0);
    //delay(delaytime);
  }
  else if (val == 4){
    lc.setRow(0,0,he[0]);
    lc.setRow(0,1,he[0]);
    lc.setRow(0,2,he[0]);
    lc.setRow(0,3,he[0]);
    lc.setRow(0,4,0);
    lc.setRow(0,5,0);
    lc.setRow(0,6,0);
    lc.setRow(0,7,0);
    //delay(delaytime);
  }
  else if (val == 5){
    lc.setRow(0,0,he[0]);
    lc.setRow(0,1,he[0]);
    lc.setRow(0,2,he[0]);
    lc.setRow(0,3,he[0]);
    lc.setRow(0,4,he[0]);
    lc.setRow(0,5,0);
    lc.setRow(0,6,0);
    lc.setRow(0,7,0);
    //delay(delaytime);
  }
  else if (val == 6){
    lc.setRow(0,0,he[0]);
    lc.setRow(0,1,he[0]);
    lc.setRow(0,2,he[0]);
    lc.setRow(0,3,he[0]);
    lc.setRow(0,4,he[0]);
    lc.setRow(0,5,he[0]);
    lc.setRow(0,6,0);
    lc.setRow(0,7,0);
    //delay(delaytime);
  }
  else if (val == 7){
    lc.setRow(0,0,he[0]);
    lc.setRow(0,1,he[0]);
    lc.setRow(0,2,he[0]);
    lc.setRow(0,3,he[0]);
    lc.setRow(0,4,he[0]);
    lc.setRow(0,5,he[0]);
    lc.setRow(0,6,he[0]);
    lc.setRow(0,7,0);
    //delay(delaytime);
  }
  else if (val == 8){
    lc.setRow(0,0,he[0]);
    lc.setRow(0,1,he[0]);
    lc.setRow(0,2,he[0]);
    lc.setRow(0,3,he[0]);
    lc.setRow(0,4,he[0]);
    lc.setRow(0,5,he[0]);
    lc.setRow(0,6,he[0]);
    lc.setRow(0,7,he[0]);
    //delay(delaytime);
  }
}

void loop(){
  // // DISPLAY DATA IN SERIAL
  // Serial.print(DHT.readTemperature(),1);
  // Serial.print(",");

  // //Serial.print("Water Level: ");
  // Serial.print(analogRead(0)); 
  // Serial.print(",");

  // //Serial.print("Soil Moisture Level: ");
  // Serial.print(analogRead(1)); 
  // Serial.print(",");
  
  // //Serial.print("Wind: "); 
  // Serial.print(analogRead(3));
  // Serial.print(",");

  // //Serial.print("Light Intensity: ");
  // Serial.print(analogRead(2)); 
  // Serial.println(",");
  

  if (millis() % 2 == 0){
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
  }

  if (millis() % 1000 == 0){
    // DISPLAY DATA ON LCD
    lcd.setCursor(0, 0);
    lcd.print("D:");
    lcd.setCursor(2, 0);
    lcd.print("150");

    lcd.setCursor(6, 0);
    lcd.print("H:");
    lcd.setCursor(8, 0);
    lcd.print(analogRead(1)); 

    lcd.setCursor(12, 0);
    lcd.print("W:");
    lcd.setCursor(14, 0);
    lcd.print(analogRead(3)); 

    lcd.setCursor(0, 1);
    lcd.print("S:");
    lcd.setCursor(2, 1);
    lcd.print(analogRead(0));

    lcd.setCursor(6, 1);
    lcd.print("L:");
    lcd.setCursor(8, 1);
    lcd.print(analogRead(2));

    lcd.setCursor(12, 1);
    lcd.print("T:");
    lcd.setCursor(14, 1);
    lcd.print(DHT.readTemperature()); 

    // if (analogRead(2) > 500){ 
    // }

  }
}
