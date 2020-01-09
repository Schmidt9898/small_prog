#define btn_flash 0xF7D02F
#define btn_strobe 0xF7F00F
#define btn_fade 0xF7C837
#define btn_smooth 0xF7E817
#define btn_r 0xF720DF
#define btn_g 0xF7A05F
#define btn_b 0xF7609F
#define btn_w 0xF7E01F
#define btn_le 0xF7807F
#define btn_fel 0xF700FF
#define btn_off 0xF740BF

/*
struct IRevent{

	
unsigned long code=0;

IRevent()
{
irrecv.enableIRIn();	
}



bool check()
{
	//Serial.println("checking");
	if (irrecv.decode(&results) and results.decode_type!=-1) 
	{
		Serial.println(results.decode_type);
		code=results.value;
		irrecv.resume(); 
		return true;
	}
	return false;
}
bool compare(unsigned long that)
{
	return that==code;
}

};
IRevent irda;
*/



enum Mode{
  shifter_mode,
  game_mode,
  alert_mode,
  none
};
struct Color
    {
     // uint8_t cr=0,cg=0,cb=0;
  

  void set_0(CRGB & led)
  {
 // cr=0;cg=5;cb=0;
  led.r=255;led.g=0;led.b=0;
  }
  
  void shift(CRGB & led)
  {
  //  r+=cr;
   // b+=cb;
   // g+=cg;

    if(led.g==255 and led.r<=255 and led.r>0 and led.b==0)
    {
      led.r+=-5;
      
    }
    else if(led.g==255 and led.r==0 and led.b<255 and led.b>=0)
    {
      led.b+=5;
    }else if(led.g<=255 and led.g>0  and led.r==0 and led.b==255)
    {
      led.g+=-5; 
    }
    else if(led.g==0 and led.r<255 and led.r>=0 and led.b==255)
    {
      led.r+=5;
   
    }else if(led.g==0 and led.r==255 and led.b<=255 and led.b>0)
    {
      led.b+=-5;
    }
    else if(led.g<255 and led.g>=0 and led.r==255 and led.b==0)
    {
      led.g+=5;
    }
    
  }
void zero(CRGB & led)
{
  led.r=0;led.g=0;
  led.b=0;
}
  
 /* Color Next()
  {
    Color uj = *this;
     uj.shift();
    return uj;
  }*/
      
    };
