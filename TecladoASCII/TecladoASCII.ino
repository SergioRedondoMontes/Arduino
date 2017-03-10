#include <LiquidCrystal.h>
// give it a name:
int btn1 = 5, btn10 = 4, btnAceptar = 3, btnBorrar = 2;
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
char a; 

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(btn1, INPUT);
  pinMode(btn10, INPUT);
  pinMode(btnAceptar, INPUT);
  pinMode(btnBorrar, INPUT);
  lcd.begin(16,2);
  
}
void loop() {
  // put your main code here, to run repeatedly:
 
   for (int i=0; i<16; i++){
      lcd.setCursor(i,0);    
      a = 65;
      
    while (digitalRead(btnAceptar) == false) {
      if (digitalRead(btn1) == true){
        a = a + 1;
        if (a>90){
          a=65;
        }
        lcd.setCursor(i,0);
        lcd.print(a);
        delay(500);
        
      } else if (digitalRead(btn10) == true){
        a = a + 10;
        if (a>90){
          a=65;
        }
        lcd.setCursor(i,0);
        lcd.print(a);
        delay(500);
        
      } else if (digitalRead(btnBorrar) == true){
        lcd.setCursor(0,0); 
        lcd.print("                ");
        delay(500);
        i = 0;
      }
      
    }
    delay(500);
  }
}
