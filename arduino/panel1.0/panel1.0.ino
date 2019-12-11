
class Gomb
{

  int pin;
  bool state;
  bool last=false;
  String name;
  public:
Gomb(int pin_,String name_)
{
  name=name_;
  pin=pin_;
   pinMode(pin_, INPUT);
   digitalWrite(pin_,HIGH);
}

void poststate()
{
  state=!digitalRead(pin);
  
  if(last!=state)
  {
    last=state;
    
   Serial.print(name);
   Serial.print(" : ");
   Serial.println(state);
   
  }
  //return false;
}
  
};
//////////////////////////////

Gomb* gombok[5];

//int gomb1=22,gomb2=23,gomb3=24;

int P0A = 2; //zöld jobra
int P0B = 3; //kék balra
int Pos = 0;
int last = LOW;
int now = LOW;

void setup() {
  // put your setup code here, to run once: )
//  for(int i=0;i<sizeof(gombok);i++)
       gombok[0]=new Gomb(22,"R1");
       gombok[1]=new Gomb(23,"R2");
       gombok[2]=new Gomb(24,"L1");
       gombok[3]=new Gomb(25,"L2");
       gombok[4]=new Gomb(27,"RE");
       




  pinMode (P0A, INPUT);
  digitalWrite(P0A, HIGH);
  pinMode (P0B, INPUT);
  digitalWrite(P0B, HIGH);
  last=digitalRead(P0A);


 Serial.begin(9600);

}
void loop() {
  
  for(int i=0;i<5;i++)
  gombok[i]->poststate();

 now = digitalRead(P0A);
  if ((last == LOW) && (now == HIGH)) {
    if (digitalRead(P0B) == LOW) {
      //Pos--;
      Serial.println ("RT : 1"); //jobbra
    } else {
      Serial.println ("RT : 0"); //balra
    }
    /*Serial.print ("Position: ");
    Serial.println (Pos);*/
  }
  last = now;
  
  
delay(1);
}
