#include "dht11.h"
#include <LiquidCrystal.h>

DHT11 DHT(4);

const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int light, water, soil, humidity, temperature; 


int inputPin = 13;               // Connect sensor to input pin 3 
const int digitalOutPin1 = 2;
const int digitalOutPin2 = 3;
const int digitalOutPin3 = 5;
const int digitalOutPin4 = 6;
bool last_state = digitalRead(inputPin);
int state = 0;

void setup(){
  pinMode(inputPin, INPUT);     // declare pushbutton as input
  // Serial.println("DHT TEST PROGRAM ");
  // Serial.print("LIBRARY VERSION: ");
  // Serial.println();
  // Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop(){


  if (millis() % 2 == 0){
    int val = digitalRead(inputPin);
    if (state == 0){
      Serial.print("state 0\n");
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
      Serial.print("state 1\n");
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
      Serial.print("state 2\n");
      digitalWrite(digitalOutPin1, HIGH);
      Serial.print(digitalRead(digitalOutPin1));
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


    // DISPLAY DATA IN SERIAL
    //Serial.print("Temperature: "); 
    Serial.println(DHT.readTemperature(),1);

    //Serial.print("Light Intensity: ");
    Serial.print(analogRead(2)); 
    Serial.print(",\t");

    //Serial.print("Water Level: ");
    Serial.print(analogRead(1)); 
    Serial.print(",\t");

    //Serial.print("Soil Moisture Level: ");
    Serial.print(analogRead(0)); 
    Serial.print(",\t");

    //Serial.print("Humidity: "); 
    Serial.print(DHT.readHumidity(),1);
    Serial.print(",\t");

    //Serial.print("Wind: "); 
    Serial.print(analogRead(3));
    Serial.print(",\t");
  }

}
