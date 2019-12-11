#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <FreqCount.h> 

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
 //char str[]="Boldog nonapot kivanok";//24 db karakter választja el a 2 sort
  lcd.print("Booting...");
  //lcd.setCursor(0, 1);
  //lcd.print("Kiva'nok");
   FreqCount.begin(1000);  
   
}

void loop()
{
   digitalWrite(5,HIGH);
 // tone(8, 100);
// digitalWrite(2,HIGH);
  if (FreqCount.available()) {                        //if the code if working
    float count = FreqCount.read();                   //create float var called count and populate it with current frequency count
    float period = (1/count);                         //create float var called period and populate it with the inverse of the frequency
  lcd.clear();        
  lcd.print(count);                               //print the actual counted frequency to buffer
  lcd.print(" Hz");
  lcd.setCursor(0,1);                       //print the name of the fuction to buffer
  lcd.print(period*1000);                         //print the period of signal in milliseconds to buffer
  lcd.print(" mS");                                //print the units to buffer
  lcd.display();                                  //SHOW ME THE BUFFER!!!!
  }
  //delay(100);
  //digitalWrite(2,LOW);
    //delay(100);
     digitalWrite(5,LOW);
}
