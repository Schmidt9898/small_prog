
int tomb[]={2,3,4,5,6,7};
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  for(int i=0;i<6;i++){
  pinMode(i, OUTPUT);  
  }
//Serial.begin(9600);  
}

// the loop function runs over and over again forever
void loop() {
            //  while(Serial.available()==0);
            //  int szamolo=Serial.parseInt();
             // Serial.flush();
             // if(szamolo>7 || szamolo<1)
            //  {
               // Serial.println("nem jó");
                
             // }else{
              for(int i=0;i<6;i++){
              digitalWrite(tomb[i], LOW); 
             // Serial.println("Miéert?"); 
               }
            //   if(szamolo==7)
             //  {
             //   szamolo=0;
              // }
               for(int i=0;i<szamolo;i++){
              digitalWrite(tomb[i], HIGH);  
               }
              
            //  }
}
