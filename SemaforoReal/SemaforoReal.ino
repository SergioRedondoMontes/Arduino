/**
 * Este programa es un semáforo de coche y uno de peatones con un LCD que muestra cuando pasar
 * con una cuenta atras y un no pasar cuando el semáforo de coches esta en ambar o rojo.
 * Tambien cuenta con un pulsador que permite al peaton poder pasar. Se puede pulsar en cualquier
 * momento salvo cuando esta en verde el de peatones y durante los 5 primeros segundos cuando el
 * semaro de coches esta en verde.
 * Versión: 1.0
 * Fecha 08/11/2016
 * Autor: Carlos Rodriguez y Sergio Redondo
 */

//incluimos la libreria <LiquidCrystal.h> para trabajar con el LCD y declaramos las varibles.
#include <LiquidCrystal.h>
int iEstado;
int iEstadoRojo, iEstadoAmarillo, iEstadoVerde;
int i;
int salir;
int change;
LiquidCrystal lcd(3, 4, 7, 9, 11, 12); // aqui le decimos al LCD los pines que corresponden a ( RS, EN, d4, d5, d6, d7) 
void setup() {
  
  // Asignamos un valor a las varibles

  lcd.begin(16, 2); // Fijar el numero de caracteres y de filas
  
  change=0;
  iEstadoRojo=1;
  iEstadoAmarillo=2;
  iEstadoVerde=3;
  iEstado=iEstadoRojo;
  i=0;
  pinMode(13,OUTPUT); //PIN 13 ES ROJO
  pinMode(10,OUTPUT); //PIN 10 ES AMARILLO
  pinMode(6,OUTPUT); //PIN 6 ES VERDE
  pinMode(2,INPUT); //PIN 2 ES EL PULSADOR
  pinMode(8,OUTPUT);//PIN 8 ES EL LED ROJO DE PEATONES
  pinMode(5,OUTPUT); //PIN 5 ES EL LED VERDE DE PEATONES
}

void loop() {

  //lcd.setCursor(0, 0);  // set the cursor to column 0, line 0
  // lcd.print(millis() / 1000);  // print the number of seconds since reset:

if(iEstado==iEstadoRojo) { //comprueba valor iEstado
    digitalWrite(13,HIGH); //enciende el PIN 13 = LED ROJO
    digitalWrite(5,HIGH); //enciende el PIN 5 = LED VERDE PEATON
    // 2 lineas limpia LCD
    lcd.setCursor(0,0); 
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("PASAR"); // Imprime PASAR 

    for(int j=1;j<=10000;j=j+500){ // Bucle para el tiempo que se mantienen encendido los LEDs
      
      lcd.setCursor(0,1);
      lcd.print("  ");
      lcd.setCursor(0,1);
      lcd.print((11000-j)/1000); //imprime cuenta atras peatones
      if(j>5000){ //parpadeo LED VERDE PEATON ultimos 5seg
       if(change==0){
         digitalWrite(5,LOW);
        change=1;  
        }else{
          digitalWrite(5,HIGH);
         change=0;
        }
      }
     delay(500);
    }
    lcd.setCursor(0,1);
    lcd.print("  ");
    
    digitalWrite(13,LOW);
    digitalWrite(5,LOW);
    iEstado=iEstadoVerde; //iguala iEstado a iEstadoVerde
    
  } 
  else if (iEstado==iEstadoAmarillo) {
    lcd.setCursor(0,0);
    lcd.print("NO PASAR"); //Imprime NO PASAR por LCD
    digitalWrite(10,HIGH); //enciende el PIN 10 = LED AMARILLA
    digitalWrite(8,HIGH); //enciende el PIN 8 = LED ROJO PEATON
    for(int j=0;j<5000;j=j+500){ //Parpadeo LED AMARILLO durante 5seg
      if(change==0){
       digitalWrite(10,LOW);
       change=1;  
      }else{
        digitalWrite(10,HIGH);
        change=0;
      }
     delay(500);
    }
    delay(2000); // LED AMARILLO fijo 2seg

    digitalWrite(10,LOW);
    digitalWrite(8,LOW); 
    iEstado=iEstadoRojo; //iguala iEstado a iEstadoRojo
    
  }
   else if (iEstado==iEstadoVerde) {
      lcd.setCursor(0,0);
    lcd.print("NO PASAR");
      digitalWrite(6,HIGH); //enciende el PIN 6 = LED VERDE
      digitalWrite(8,HIGH);//enciende el PIN 8 = LED ROJO PEATON
      i=0;  //igualamos i a 0 para el while
      salir=1; // igualamos salir a 1 
      delay(5000);  //con este delay fijo evitamos que el peaton pulse durante los primeros 5seg
      while(i<5000 && salir!=0){ //cambiar LED al usar el pulsador
      if(digitalRead(2)==true){
        salir=0;
        iEstado=iEstadoAmarillo;
      }
      i++;
    delay(1);  
      }
      digitalWrite(6,LOW);
      digitalWrite(8,LOW);
      if(salir!=0){
         iEstado=iEstadoAmarillo;
      }
     
   }
}
