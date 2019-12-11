    #include <FastLED.h>
    #define NUM_LEDS 50
    #define DATA_PIN 6

 struct Color
    {
      uint8_t cr=0,cg=1,cb=0;
      uint8_t r=255,g=0,b=0;
  void set(uint8_t r_,uint8_t g_,uint8_t b_)
  {
  cr=0;cg=1;cb=0;
  r=255;g=0;b=0;
  }
  void shift()
  {
    r+=cr;
    b+=cb;
    g+=cg;

    if(g==255 and r==255 and b==0)
    {
      cr=-1;
      cg=0;
      cb=0;
    }
    else if(g==255 and r==0 and b==0)
    {
      cr=0;
      cg=0;
      cb=1;
    }else if(g==255 and r==0 and b==255)
    {
      cr=0;
      cg=-1;
      cb=0;
    }
    else if(g==0 and r==0 and b==255)
    {
      cr=1;
      cg=0;
      cb=0;
    }else if(g==0 and r==255 and b==255)
    {
      cr=0;
      cg=0;
      cb=-1;
    }
    else if(g==0 and r==255 and b==0)
    {
      cr=0;
      cg=1;
      cb=0;
    }
    
  }
void zero()
{
  r=0;g=0;
  b=0;
}
  
  Color Next()
  {
    Color uj = *this;
     uj.shift();
    return uj;
  }
      
    };



CRGB leds[NUM_LEDS];


   Color color;
Color tomb[NUM_LEDS];


long start;
void setup() {
  
 FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
//Serial.begin(9600);

for(int i=0;i<NUM_LEDS;i++)
{
  /*for(int j=0;j<i;j++)
  {
    for(int k=0;k<50;k++)
    {
      tomb[i].shift();
    }  
  }*/
  tomb[i].zero();
  
}
 start = millis();
 
}

Color last,temp;


void loop() {
  if(millis()-start>200){
  tomb[0].set(0,0,0);
  start=millis();
  //Serial.println(start);
  }else
  {
   // Serial.println(0);
    tomb[0].zero();
  }
  last=tomb[0];
   leds[0] = CRGB(last.r,last.g,last.b);
  for(int i=1;i<NUM_LEDS;i++)
  {
  temp=tomb[i];
  tomb[i]=last;
  last=temp;
  
  
  leds[i] = CRGB(temp.r,temp.g,temp.b); 
         
    
  }
  FastLED.show();
  
   delay(10);

}
