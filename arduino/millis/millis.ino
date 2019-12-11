#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

unsigned long preTime;
unsigned long Time;
unsigned long counter=0;
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  // put your setup code here, to run once:
lcd.begin();
  lcd.print("Booting...");
  pinMode(8,OUTPUT),
  analogWrite(8, 10);
  
}



void loop() {
 // Time = millis()-preTime;
 if((millis()-preTime)>=1000)
 {
  
   lcd.clear();
  lcd.print(counter);
  preTime=millis();
  counter=0;
 }
 else{
 counter++;
 
 
 
 }
 /*
  lcd.clear();
  lcd.print(Time);
  preTime=millis();
  delay(1000);*/
 

}
