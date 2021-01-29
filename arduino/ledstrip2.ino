    #include <FastLED.h>
    #include <IRremote.h>
    #include "Mode_t.h"
    #define NUM_LEDS 49
    #define DATA_PIN 4
    

CRGB leds[NUM_LEDS];
Color color;

void sw(CRGB &a,CRGB &b)
{
  CRGB c=a;
  a=b;
  b=c;
}

CRGB nulla;
unsigned long stime=0;
void setup() {
   FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  //Serial.begin(9600);

  
  for(int i=0;i<NUM_LEDS;i++)
  {
  
      //color.zero(leds[i]);
      color.set_0(leds[i]);
         
  }
  leds[0].r=255;
  FastLED.show();
  stime=millis();

}

void loop() {
    for(int i=0;i<NUM_LEDS;i++)
  {
    color.shift(leds[i]);
  }
  delay(10);
  FastLED.show();
  /*if(stime+millis()>1000)
  {
    leds[0].r=255;
    stime=millis();
  }
  for(int i=0;i<NUM_LEDS-1;i++)
  {
    sw(leds[i],leds[i+1]);
     FastLED.show();
  delay(100);
  }
  color.zero(leds[NUM_LEDS-1]);*/

  

}



//action loop
