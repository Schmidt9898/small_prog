const int REB=21;
const int REJ=20;
const int REG=26;
const int L1=22;
const int L2=23;
const int R2=24;
const int R1=25;


  String zold;
  String kek;
int Pos = 0;

int last = LOW;
int now = LOW;
volatile bool Free=true;
void onevent()
{
  int j=digitalRead(REJ);
  if(j==LOW)
  Pos--;
  else if(j==HIGH)
  Pos++;
  Serial.print ("Position: ");
    Serial.println (Pos);
  /*
  
  now = digitalRead(REB);
  if ((last == LOW) && (now == HIGH)) {
    if (digitalRead(REJ) == LOW) {
      Pos--;
    } else {
      Pos++;
    }
    Serial.print ("Position: ");
    Serial.println (Pos);
  }
  last = now;*/
  
  /*
  if(digitalRead(REJ)==LOW and !locked) {
    locked=true;
      Pos++;
    } else {
      Pos--;
    }
    Serial.print ("Position: ");
    Serial.println (Pos);
    delay(10000);
    Serial.print ("unlock ");
    locked=false;
    */
    
}

void oneventB()
{//b is faling
   if(Free)
   {
    Free=false;
    if(digitalRead(REJ)==HIGH)
    Pos--;}
    else{
    Pos++;
    Serial.print ("Position: ");
    Serial.println (Pos);
    
   }//else do nothing
}
void oneventJ()
{
  if(Free)
   {
    Free=false;
    if(digitalRead(REB)==HIGH)
    Pos++;
    //Serial.print ("Position: ");
    Serial.println (0);
    Free=true;
   }
}

void setup() {
  pinMode (REB, INPUT);
  digitalWrite(REB, HIGH);
  pinMode (REJ, INPUT);
  digitalWrite(REJ, HIGH);
  //pinMode (21, INPUT);
  //digitalWrite(21,HIGH);
  //last=digitalRead(P0A);
  
attachInterrupt(digitalPinToInterrupt(REB), onevent, FALLING); 
 // attachInterrupt(digitalPinToInterrupt(REB), oneventB, FALLING); 
  //attachInterrupt(digitalPinToInterrupt(REJ), oneventJ, FALLING); 
  Serial.begin (9600);
}

void loop() {
  delay(1);
  delayMicroseconds(Pos);
//  if(digitalRead(REB)==HIGH and digitalRead(REJ)==HIGH)
 // locked=false;
/*  if(digitalRead(P0A))
  zold="high";
  else
  zold="low";
  if(digitalRead(P0B))
  kek="high";
  else
  kek="low";
  
   Serial.println (zold+" : "+kek);
   while(t)
   {
    if(digitalRead(21)==HIGH)
    {
      t=false;
    }
    
   }*/
  /*
now=digitalRead(P0A);
  if(now!=last)
  {
    if(digitalRead(P0B)!=now)
    {
      Pos++;
    }else
     {
      Pos--;
     }
     Serial.print ("Position: ");
    Serial.println (Pos);
  }
  last=now;
delay(1);

*/

  
  /*
  now = digitalRead(P0A);
  if ((last == LOW) && (now == HIGH)) {
    if (digitalRead(P0B) == LOW) {
      Pos--;
    } else {
      Pos++;
    }
    Serial.print ("Position: ");
    Serial.println (Pos);
  }
  last = now;
  delay(1);
*/
/*
 now = digitalRead(P0A);
  if ((last == LOW) && (now == HIGH)) {
    if (digitalRead(P0B) == LOW) {
      Pos--;
          Serial.print ("Position: ");
    Serial.println (Pos);
    }
  }else if(last == LOW)
  {
    if (digitalRead(P0B) == HIGH) {
      Pos++;
    Serial.print ("Position: ");
    Serial.println (Pos);
    }
   
  }
  last = now;
  delay(1);*/
}
