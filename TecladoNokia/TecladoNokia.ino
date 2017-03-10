#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13); //    ( RS, EN, d4, d5, d6, d7)
int btn1=6, btn2=56, btn3=5, btn4=57, btn5=4, btn6=58, btn7=3, btn8=59, btn9=2;//A0=54, A1=55
int asdf=1; 
char caracter=97;
int i=0;
char a=45;
char b=32;

void setup() {
  lcd.begin(16, 2); // Fijar el numero de caracteres y de filas
  pinMode(btn1, INPUT);
  
  pinMode(btn3, INPUT);
  
  pinMode(btn5, INPUT);
  
  pinMode(btn7, INPUT);
  
  pinMode(btn9, INPUT);

}

void loop() {
  lcd.setCursor(i,1);
  lcd.print(a);
    asdf=1;
    if(digitalRead(btn1)){
      lcd.setCursor(i,0);
      lcd.print('a');
      delay(200);
      for(int j=0;j<20;j++){
         if(digitalRead(btn1)){
          asdf++;
          lcd.setCursor(i,0);
          if(asdf%3==0){
            lcd.print('b');
          }else if(asdf%3==1){
            lcd.print('c');
          }else{
            lcd.print('a');
          }
        }
        delay(200);
      }
      lcd.setCursor(i,1);
      lcd.print(b);
      i++;
      
    }
     if(analogRead(2)>1000){
      lcd.setCursor(i,0);
      lcd.print('d');
      delay(200);
      for(int j=0;j<20;j++){
         if(analogRead(5)>1000){
          asdf++;
          lcd.setCursor(i,0);
          if(asdf%3==0){
            lcd.print('e');
          }else if(asdf%3==1){
            lcd.print('f');
          }else{
            lcd.print('d');
          }
        }
        delay(200);
      }
      lcd.setCursor(i,1);
      lcd.print(b);
      i++;
      
    }
    if(digitalRead(btn3)){
      lcd.setCursor(i,0);
      lcd.print('g');
      delay(200);
      for(int j=0;j<20;j++){
         if(digitalRead(btn3)){
          asdf++;
          lcd.setCursor(i,0);
          if(asdf%3==0){
            lcd.print('h');
          }else if(asdf%3==1){
            lcd.print('i');
          }else{
            lcd.print('g');
          }
        }
        delay(200);
      }
      lcd.setCursor(i,1);
      lcd.print(b);
      i++;
      
    }
    if(analogRead(3)>1000){
      lcd.setCursor(i,0);
      lcd.print('j');
      delay(200);
      for(int j=0;j<20;j++){
         if(analogRead(3)>1000){
          asdf++;
          lcd.setCursor(i,0);
          if(asdf%3==0){
            lcd.print('k');
          }else if(asdf%3==1){
            lcd.print('l');
          }else{
            lcd.print('j');
          }
        }
        delay(200);
      }
      lcd.setCursor(i,1);
      lcd.print(b);
      i++;
    }
    if(digitalRead(btn5)){
      lcd.setCursor(i,0);
      lcd.print('m');
      delay(200);
      for(int j=0;j<20;j++){
         if(digitalRead(btn5)){
          asdf++;
          lcd.setCursor(i,0);
          if(asdf%3==0){
            lcd.print('n');
          }else if(asdf%3==1){
            lcd.print('o');
          }else{
            lcd.print('m');
          }
        }
        delay(200);
      }
      lcd.setCursor(i,1);
      lcd.print(b);
      i++;
    }
    if(analogRead(4)>1000){
      lcd.setCursor(i,0);
      lcd.print('p');
      delay(200);
      for(int j=0;j<20;j++){
         if(analogRead(4)>1000){
          asdf++;
          lcd.setCursor(i,0);
          if(asdf%3==0){
            lcd.print('q');
          }else if(asdf%3==1){
            lcd.print('r');
          }else{
            lcd.print('p');
          }
        }
        delay(200);
      }
      lcd.setCursor(i,1);
      lcd.print(b);
      i++;
    }
    if(digitalRead(btn7)){
      lcd.setCursor(i,0);
      lcd.print('s');
      delay(200);
      for(int j=0;j<20;j++){
         if(digitalRead(btn7)){
          asdf++;
          lcd.setCursor(i,0);
          if(asdf%3==0){
            lcd.print('t');
          }else if(asdf%3==1){
            lcd.print('u');
          }else{
            lcd.print('s');
          }
        }
        delay(200);
      }
      lcd.setCursor(i,1);
      lcd.print(b);
      i++;
    }
    if(analogRead(5)>1000){
      lcd.setCursor(i,0);
      lcd.print('v');
      delay(200);
      for(int j=0;j<20;j++){
         if(analogRead(5)>1000){
          asdf++;
          lcd.setCursor(i,0);
          if(asdf%3==0){
            lcd.print('w');
          }else if(asdf%3==1){
            lcd.print('x');
          }else{
            lcd.print('v');
          }
        }
        delay(200);
      }
      lcd.setCursor(i,1);
      lcd.print(b);
      i++;
    }
    if(digitalRead(btn9)){
      lcd.setCursor(i,0);
      lcd.print('y');
      delay(200);
      for(int j=0;j<20;j++){
         if(digitalRead(btn9)){
          asdf++;
          lcd.setCursor(i,0);
          if(asdf%3==0){
            lcd.print('z');
          }else if(asdf%3==1){
            lcd.print(' ');
          }else{
            lcd.print('y');
          }
        }
        delay(200);
      }
      lcd.setCursor(i,1);
      lcd.print(b);
      i++;
    }
  
  
/*  if(digitalRead(btn1)){
    lcd.setCursor(0,0);
    lcd.print(caracter);
    delay(1000);
    for(int i=0;i<4;i++){
       if(btn1){
        caracter++;
       }
      delay(1000);
    }
    
  }*/
  

}
