


  String zold;
  String kek;

int P0A = 3;
int P0B = 2;
int Pos = 0;
int last = LOW;
int now = LOW;
volatile bool t=false;
void onevent()
{
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
}

void onevent2()
{
   //Serial.println ("Stopped");
  t=true;
 // delay(1000);
    //Serial.println ("Stopped");
}
void onevent3()
{
  
  t=false;

}

void setup() {
  pinMode (P0A, INPUT);
  digitalWrite(P0A, HIGH);
  pinMode (P0B, INPUT);
  digitalWrite(P0B, HIGH);
  pinMode (21, INPUT);
  digitalWrite(21,HIGH);
  last=digitalRead(P0A);
  
//attachInterrupt(digitalPinToInterrupt(P0A), onevent, HIGH); 
  attachInterrupt(digitalPinToInterrupt(21), onevent2, LOW); 
   //attachInterrupt(digitalPinToInterrupt(21), onevent3, RISING); 
  Serial.begin (9600);
}

void loop() {
  if(digitalRead(P0A))
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
    
   }
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
