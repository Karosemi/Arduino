#include<math.h>
void setup() {
  pinMode(A0,INPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);}

//digitalWrite(11,LOW);//rozladowywanie
void loop() {
  int Alfa=100;
  int Beta=900;
  int Cpin=12;
  int Rpin=13;
  int a;
  unsigned long time_0=millis();
  while(a<=Beta){
    a=analogRead(A0);
   digitalWrite(12,HIGH);
    Serial.println(a);
    delay(50);
    }
  unsigned long time_1=millis();  
  while(a>=Alfa){
  digitalWrite(12,LOW);
    a = analogRead(A0);
    Serial.println(a);
    delay(50);
    }
  unsigned long time_2=millis();
  unsigned long ChargeTime=time_1-time_0;
  unsigned long DchargeTime=time_2-time_1;
  
  
  long R=67;
  long u=Beta/Alfa;
  long C1=(DchargeTime)/R*1/log (u);
  //Serial.println(C1);
  long v=(1-Alfa/1023)/(1-Beta/1023);
  long C2=(ChargeTime)/R*1/log (v);
 //Serial.println(C2);
  
}
