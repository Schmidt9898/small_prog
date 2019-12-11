int selected=0;
#define piros 2
#define feher 3
const uint16_t tones[]={ 31  ,
33  ,
35  ,
37  ,
39  ,
41  ,
44  ,
46  ,
49  ,
52  ,
55  ,
58  ,
62  ,
65  ,
69  ,
73  ,
78  ,
82  ,
87  ,
93  ,
98  ,
104 ,
110 ,
117 ,
123 ,
131 ,
139 ,
147 ,
156 ,
165 ,
175 ,
185 ,
196 ,
208 ,
220 ,
233 ,
247 ,
262 ,
277 ,
294 ,
311 ,
330 ,
349 ,
370 ,
392 ,
415 ,
440 ,
466 ,
494 ,
523 ,
554 ,
587 ,
622 ,
659 ,
698 ,
740 ,
784 ,
831 ,
880 ,
932 ,
988 ,
1047  ,
1109  ,
1175  ,
1245  ,
1319  ,
1397  ,
1480  ,
1568  ,
1661  ,
1760  ,
1865  ,
1976  ,
2093  ,
2217  ,
2349  ,
2489  ,
2637  ,
2794  ,
2960  ,
3136  ,
3322  ,
3520  ,
3729  ,
3951  ,
4186  ,
4435  ,
4699  ,
4978  ,
};


void setup() {
  // put your setup code here, to run once:
pinMode(piros,INPUT_PULLUP);
pinMode(feher,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(piros), hatra, FALLING);
  attachInterrupt(digitalPinToInterrupt(feher), elore, FALLING);
}

void loop() {
    if(selected<0 or selected>89)
selected=0;
 tone(8,tones[selected]);
delay(20);
 noTone(8);
 delay(1000);
  
}

void elore(){
  if(digitalRead(3)==HIGH)
  selected++;}
void hatra(){if(digitalRead(2)==HIGH)
  selected--;}
