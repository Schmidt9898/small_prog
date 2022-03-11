#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

#define img_size 21 //TODO proper size
static const uint8_t PROGMEM img[][8]={
{0x3C, 0x7E, 0x5A, 0x7E, 0x3C, 0x18, 0x3C, 0x3C},    //radio_bmp   
{0xFE, 0x7C, 0x38, 0x10, 0xEE, 0xEE, 0x6C, 0x28},   //rad_bmp      
{0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA},   //semmi_bmp   
{0x3C, 0x18, 0x18, 0x18, 0x3C, 0x66, 0xC3, 0xFF},   //tudosok_bmp   
{0x7C, 0xFE, 0x92, 0xFE, 0xEE, 0xFE, 0x7C, 0x54},   //banditak_bmp  
{0x18, 0x18, 0x18, 0xFF, 0xFF, 0x18, 0x18, 0x18},   //orvosok_bmp   
{0x7E, 0x5A, 0x7E, 0x3C, 0x3C, 0x18, 0x3C, 0x3C},   //gasMask_bmp   
{0xFF, 0x81, 0xA5, 0xA5, 0xA5, 0x99, 0x42, 0x3C},   //katonasag_bmp 
{0x42, 0x66, 0x7E, 0x7E, 0xDB, 0x7E, 0x3C, 0x18},   //szabadsag_bmp 
{0x00, 0x20, 0x70, 0xF8, 0x00, 0x00, 0x04, 0x0E},   //putri_bmp   
{0x00, 0x20, 0x70, 0xF8, 0x00, 0x00, 0x04, 0x0E},   //korX_bmp    
{0x00, 0x00, 0x62, 0x56, 0x62, 0x52, 0x57, 0x00},   //r1_bmp      
{0x00, 0x70, 0x20, 0x20, 0x26, 0x08, 0x08, 0x06},   //tc_bmp      
{0x88, 0xF8, 0xA8, 0x71, 0x21, 0x79, 0x7D, 0xBE},   //cat_bmp     
{0x00, 0xFF, 0x81, 0x81, 0x81, 0xFF, 0x18, 0x3C},   //monitor_bmp   
{0x18, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x7E, 0xFF},   //monolith_bmp  
{0x00, 0x00, 0x24, 0x66, 0x66, 0x3C, 0x18, 0x18},   //technikus_bmp 
{0xFF, 0x42, 0x3C, 0x00, 0x18, 0x34, 0x24, 0x18},   //kituntetes_bmp  
{0x00, 0x00, 0xBC, 0xFE, 0xFF, 0xFE, 0xBC, 0x00},   //ammo_bmp    
{0x00, 0xBA, 0xBA, 0x00, 0x54, 0x92, 0x10, 0x10},   //akna_bmp    
{0x18, 0x18, 0x7E, 0x18, 0x18, 0x3C, 0x7E, 0xFF},   //vorosKirNo_bmp  
{0x00, 0x60, 0x90, 0x90, 0x1E, 0x12, 0x12, 0x1E},   //lakatKi_bmp   
{0x00, 0x0C, 0x12, 0x12, 0x1E, 0x12, 0x12, 0x1E},};  //lakatBe_bmp    


//Matrix variables
Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

enum State
{
    Motion_state,
    Img_loop_state,
    Rand_img_state,
    Lock_anim_state
};


//forward declaration of functions
void Draw_led();
typedef void (*callable_function)(int);
State Motion();
State Image_loop();
State Rand_img();
State Lock_anim();



struct Gomb{
	bool isPressed=false;
	int pin;//this is also the button id, will be passed to calback
	void (*button_callback)(int);
	
	void get_newstate()
	{
	bool res=digitalRead(pin);
	if(res!=isPressed)
	{
		delay(10);
		isPressed=res;
		//button change state
		if(res)
		button_callback(pin);
	}
	}
	//construct
	void init(int pin_,callable_function _func)
	{
		pin=pin_;
		pinMode(pin, INPUT);
		button_callback=_func;
	}
};



//defining global variables
int piezoPin = 8;
int randNumber = 0;


Gomb btn_2, btn_3, btn_4, btn_5;
#define PINLENGTH 4
int pin_code[PINLENGTH]{};// size 3
int pin_code_idx=0;
int correct_pincode[]{2,2,2,2};

State state=Motion_state;


/*
void template_callback (int btn_id)
{
	Serial.println(btn_id);
}
*/
void print_pin()
{
	for(int i=0;i<PINLENGTH;i++)
	{
	Serial.print(pin_code[i]);Serial.print(",");
	}
	Serial.println(" ");
}

void add_pin_clb (int btn_id)
{
	if(pin_code_idx>= PINLENGTH)
	return;
	pin_code[pin_code_idx]=btn_id;
	pin_code_idx++;
	print_pin();//remove this id not debugging
}
void enter_btn_pressed(int btn_id)//id will be ignored
{
	//Serial.print("idx ");Serial.println(pin_code_idx);
	if(pin_code_idx == PINLENGTH)
	{
	bool isgood=true;
	for(int i=0;i<PINLENGTH;i++)
		if(pin_code[i]!=correct_pincode[i])
		{
		isgood=false;
		break;
		}
		if(isgood)
		{
		// add here the unlocking code
		state=Lock_anim_state;
		Serial.println("pin is good.");
		}else
		{
		Serial.println("wrong pin.");
		}
	}

  for(int i=0;i<PINLENGTH;i++)
    pin_code[i]=0;
	Serial.println("clearing...");
	pin_code_idx=0;
}

void pass(int id){}

//long myTime=0;

void setup() {
//Serial
Serial.begin(9600);
matrix.begin(0x70);	// pass in the address
//myTime=millis();
//buttons setup



//Serial.println("Pres the big red button.");
//while(!digitalRead(2))
//	delay(10);

Serial.println("Program Start.");
}




//program
void loop() {

switch(state)
{
	case Motion_state: state= Motion(); break;
	case Img_loop_state: state= Image_loop(); break;
	case Rand_img_state: state= Rand_img(); break;
	case Lock_anim_state: state= Lock_anim(); break;
}



//btn_2.get_newstate();
//btn_3.get_newstate();
//btn_4.get_newstate();
//btn_5.get_newstate();
//Draw_led();
}
State Motion(){
Serial.println("Motion state.");
	while(!digitalRead(/*motion sensore pin*/ 5));
	return Img_loop_state;

}

unsigned long image_loop_time=0;
State Image_loop(){
Serial.println("image loop state.");
	image_loop_time=millis();
	btn_2.init(2,add_pin_clb);
	btn_3.init(3,add_pin_clb);
	btn_4.init(4,add_pin_clb);
	btn_5.init(5,enter_btn_pressed);//enter clear
	while(state==Img_loop_state)
	{
		btn_2.get_newstate();
		btn_3.get_newstate();
		btn_4.get_newstate();
		btn_5.get_newstate();
		Draw_led();
	}


	return state;
}


State Rand_img(){
		Serial.println("Random image state.");
		randNumber = random(0, 21);
        //matrix.clear();this one maybe useless
        matrix.drawBitmap(0, 0, img[randNumber], 8, 8, LED_ON);
        matrix.writeDisplay();
        tone(piezoPin, 1000, 500);
		unsigned long showtime=millis();
        //delay(5000);
		while( millis()<showtime+5000)
		{
		btn_2.get_newstate();
		btn_3.get_newstate();
		btn_4.get_newstate();
		btn_5.get_newstate();
		}
		if (state==Rand_img_state)
			return Img_loop_state;
		return state;

}



State Lock_anim(){
	Serial.println("Lock animation.");

	for(int i=0;i<10;i++)
	{
    tone(piezoPin, 200, 200);
    matrix.clear();
    matrix.drawBitmap(0, 0, img[21], 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(200);
    tone(piezoPin, 100, 200);
    matrix.clear();
    matrix.drawBitmap(0, 0, img[22], 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(200);
	}
	
	
	return Motion_state;
};





int image_idx=0;
void Draw_led()
{
  //Serial.println("asd");
  
  if(millis()>=image_loop_time+100)
  {
    matrix.clear();
    matrix.drawBitmap(0, 0, img[image_idx], 8, 8, LED_ON);
    matrix.writeDisplay();
    tone(piezoPin, 400, 50);
    image_idx++;
    image_loop_time=millis();
    if(image_idx>=img_size){
       image_idx=0;
		state=Rand_img_state;
	}
  }
	
}	
	/*randNumber = random(1, 21);//TODO
	matrix.clear();
	matrix.drawBitmap(0, 0, img[randNumber], 8, 8, LED_ON);
	matrix.writeDisplay();
	tone(piezoPin, 1000, 500);
	delay(5000);
*/
//TODO lock
