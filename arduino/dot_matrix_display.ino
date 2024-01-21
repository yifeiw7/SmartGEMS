#include <dht11.h>
#include <LiquidCrystal.h>
#include <LedControl.h>
#include <binary.h>
LedControl lc=LedControl(10,12,11,1);
byte he[1]= {B11111111};
void setup() {
  // put your setup code here, to run once:
  //lcd.begin(16, 2);
  Serial.begin(9600);

  lc.shutdown(0,false);
  // Set brightness to a medium value
  lc.setIntensity(0,1);
  // Clear the display
  lc.clearDisplay(0);  
}

void loop() {
  // put your main code here, to run repeatedly:
  lc.setColumn(0,0,0);
  lc.setColumn(0,1,0);
  lc.setColumn(0,2,0);
  lc.setColumn(0,3,0);
  lc.setColumn(0,4,0);
  lc.setColumn(0,5,he[0]);
  lc.setColumn(0,6,he[0]);
  lc.setColumn(0,7,he[0]);
  delay(3000);
  lc.setColumn(0,0,0);
  lc.setColumn(0,1,0);
  lc.setColumn(0,2,0);
  lc.setColumn(0,3,he[0]);
  lc.setColumn(0,4,he[0]);
  lc.setColumn(0,5,he[0]);
  lc.setColumn(0,6,he[0]);
  lc.setColumn(0,7,he[0]);
  delay(3000);
  lc.setColumn(0,0,he[0]);
  lc.setColumn(0,1,he[0]);
  lc.setColumn(0,2,he[0]);
  lc.setColumn(0,3,he[0]);
  lc.setColumn(0,4,he[0]);
  lc.setColumn(0,5,he[0]);
  lc.setColumn(0,6,he[0]);
  lc.setColumn(0,7,he[0]);
  delay(3000);
}
