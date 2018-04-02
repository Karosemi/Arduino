int red=11;
int green=10;
int blue=9;
int redsyg=3;
int yellowsyg=5;
int greensyg=6;
int a=0; //sygnal z przycisku
int i=0;//licznik czasu dla sygnalizacji 
int j=0;//licznik czasu dla diody RGB
void setup() {
  pinMode(2, INPUT);
  pinMode(redsyg, OUTPUT);
  pinMode(greensyg, OUTPUT);
  pinMode(yellowsyg, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(2, INPUT);
}
//funkcje kolorów dla diody RGB
//czerwony
void Red(){
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
    }
//zolty
void Yellow(){
    digitalWrite(red,HIGH);
    digitalWrite(green,HIGH);
    digitalWrite(blue,LOW);
    }
//zielony
  void Green(){
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    digitalWrite(blue,LOW);
    }
//cyjan
 void Cyan(){
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    digitalWrite(blue,HIGH);
    }
//niebieski
void Blue(){
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    digitalWrite(blue,HIGH);
    }
//magenta
void Magenta(){
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(blue,HIGH);
 }
 //bialy
 void White(){
    digitalWrite(red,HIGH);
    digitalWrite(green,HIGH);
    digitalWrite(blue,HIGH);
 }   
void loop() {
  a=digitalRead(2); //zczytuje sygnal z przycisku i przypisuje mu zmienna a
  //jezeli j<14 sekund to wysylany jest sygnal do diody czerwonej
  if (i<14){
    digitalWrite(redsyg,HIGH);
    }
  else{digitalWrite(redsyg,LOW);}//w innych przypadkach dioda gasnie
  // sygnał dla diody zoltej
  if((i>=12 and i<14)or(i>28 and i<=30)){
    digitalWrite(yellowsyg,HIGH);}
  else{digitalWrite(yellowsyg,LOW);}
  //sygnal dla diody zielonej
  if(i>=14 and i<=28){
    digitalWrite(greensyg,HIGH);
    /*jezeli zostanie nacisniety przycisk to a=1. Jezeli swieci sie wtedy dioda zielona
    w ciagu pieciu sekund sygnalizacja zmienia kolor na czerwony (w tym czasie dioda RGB swieci swiatlem bialym*/
    if(a==1){
      White();//dioda RGB swieci swiatlem bialym
      delay(3000);
      digitalWrite(greensyg,LOW);//gaśnie zielone światlo
      digitalWrite(yellowsyg,HIGH);//zapala sie żólte swiatlo
      delay(2000);
      i=0; //nastepnie sygnalizaca wraca do fazy poczatkowej
      j=0;}}
  else{digitalWrite(greensyg,LOW);}
//Kiedy minie 30s licznik wraca do stanu poczatkowego
  if (i==30){
    i=0;}
 //licznik dla diody RGB
  if(j<2){
    Red();} //przez pierwsze 2 sekundy dioda RGB swieci na czerwono
  if(j>=2 and j<4){
    Yellow();}//przez kolejne 2 sekundy dioda RGB swieci na żolto
  if(j>=4 and j<6){
    Green();//przez kolejne 2 sekundy dioda RGB swieci na zielono
  }
  if(j>=6 and j<8){
    Cyan();//przez kolejne 2 sekundy dioda RGB swieci w kolorze cyjan
  }
  if(j>=8 and j<10){
    Blue();//przez kolejne 2 sekundy dioda RGB swieci w kolorze niebieskim
  }
  if(j>=10 and j<=12){
    Magenta();//przez kolejne 2 sekundy dioda RGB swieci w kolorze magenta
    
  }
  //gdy minie 12s (wykona sie caly cykl) j wraca do stanu poczatkowego
  if(j==12){
    j=0;}
  i+=1;
  j+=1;
  delay(1000);//petla wykonuje sie co sekunde
 
 
}
