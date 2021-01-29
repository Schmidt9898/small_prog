    #include <FastLED.h>
    #include <IRremote.h>
    #include "Mode_t.h"
    #define NUM_LEDS 49
    #define DATA_PIN 13
    

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

CRGB leds[NUM_LEDS];
Color color;

void setup() {
  irrecv.enableIRIn();
 FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
//Serial.begin(9600);


for(int i=0;i<NUM_LEDS;i++)
{

 color.set_0(leds[i]);
  
}




 
}


Mode mode = shifter_mode;
void loop() {

switch(mode)
{
  case shifter_mode:
  shifter_loop();
  break;
  case game_mode:
  break;
  case alert_mode:
  break; 
  default:
  break;
}

mode = Switch_loop();
}



void shifter_loop()
{
  //prep
  for(int i=0;i<NUM_LEDS;i++)
{
 for(int j=0;j<i;j++)
  {
    for(int k=0;k<10;k++)
    {
     color.shift(leds[i]);
    }  
  }

  
}

//action loop
while(true)
{
  /*
if (irrecv.decode(&results) and results.decode_type!=-1 and btn_off==results.value) {
  return;
}
  */
  
  
  

  
  for(int i=0;i<NUM_LEDS;i++)
  {
    color.shift(leds[i]);
    

  }
  FastLED.show();
  delay(10);
}

  

  

}

void game_loop()
{

}

void alert_loop()
{

}



Mode Switch_loop()
{
  //Serial.println("menu");
  
  for(int i=0;i<NUM_LEDS;i++)
  {
    
  
  leds[i] = CRGB(100,100,255,0); 
  }
  FastLED.show();
  
  
  while(true)
  {

  if (irrecv.decode(&results) and results.decode_type!=-1) 
  {
   // Serial.println(results.decode_type);
    
     
    
    switch(results.value)
    {
      case btn_flash:
      //Serial.println("shifter case");
      irrecv.resume();
      return shifter_mode;
      break;


      
    }
    }
  delay(10);
    
  }
  

  
return shifter_mode;
}
