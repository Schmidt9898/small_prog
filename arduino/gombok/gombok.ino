#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
///////////////////////////////////////
class Gomb
{

  int pin;
  bool state;
  bool last;
  public:
Gomb(int pin_)
{
  pin=pin_;
   pinMode(pin_, INPUT);
   digitalWrite(pin_,HIGH);
}

void poststate()
{
  state=digitalRead(pin);
  
  if(last!=state)
  {
    last=state;
    
   Serial.print(pin);
   Serial.print(" : ");
   Serial.println(state);
   
  }
  //return false;
}
  
};
//////////////////////////////




LiquidCrystal_I2C lcd(0x27, 16, 2);

Gomb* gombok[3];

//int gomb1=22,gomb2=23,gomb3=24;
String str;




void setup() {
  // put your setup code here, to run once: )
//  for(int i=0;i<sizeof(gombok);i++)
       gombok[0]=new Gomb(22);
       gombok[1]=new Gomb(23);
       gombok[2]=new Gomb(24);
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
 //char str[]="yes";//24 db karakter választja el a 2 sort
 lcd.print("Verzio 1.2");
}
void loop() {
  
  for(int i=0;i<3;i++)
  gombok[i]->poststate();
delay(10);
}
