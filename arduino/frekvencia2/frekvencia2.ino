#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


volatile float count=0;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int a =1;
void onevent()
{
  count++;
}
void setup()
{
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
 
  lcd.print("Booting...");
digitalWrite(3,HIGH);
attachInterrupt(digitalPinToInterrupt(3), onevent, FALLING); 

   tone(8,1000);
}

void loop()
{
                //tone(8,a);
  float period = (1/count);                         
  lcd.clear();        
  lcd.print(count);                              
  lcd.print(" Hz");
  lcd.setCursor(0,1);                       
  lcd.print(period*1000);                        
  lcd.print(" mS");  
  count = 0;                              
  lcd.display();
  delay(1000);    
                           
  }

    // digitalWrite(5,LOW);
