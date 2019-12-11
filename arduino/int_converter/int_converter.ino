/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/

// digital pin 2 has a pushbutton attached to it. Give it a name:
int p = 53;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(p, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  byte buff[8];
  Serial.readBytes(buff,8);
  Serial.read();
  Serial.println(asscii_to_int(buff,8));
  // read the input pin:
 // int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  //Serial.println(buttonState);
  delay(1000);        // delay in between reads for stability
}


unsigned long tiza(int e)
{
  unsigned long tiz=1;
  for(int i=0;i<e;i++)
  {
    tiz*=10;
  }
  return tiz;
}


unsigned long asscii_to_int(byte bufferem[],float meret)
{
  int i;
  int vege=meret;
  unsigned long temp=0;
  unsigned long alma=0;
  unsigned long po;
  unsigned long eredmeny=0;
   Serial.println("------");
   meret-=1;
for(i=0;i<vege;i++)
{
  alma=(bufferem[i]-48);
  po= tiza(meret);
  meret--;
  temp=alma*po;
  eredmeny+=temp;
}
 return eredmeny; 
}










