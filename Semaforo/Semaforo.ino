// Declaramos variables.

int iEstado;
int iEstadoRojo, iEstadoAmarillo, iEstadoVerde, iEstadoPrevio;
int i;
int salir;

void setup() {
  // inicializamos y damos valores a las variables.
  iEstadoRojo = 1;
  iEstadoAmarillo = 2;
  iEstadoVerde = 3;
  iEstado = iEstadoRojo;
  iEstadoPrevio = iEstado;
  i = 0;
  pinMode(13, OUTPUT); //PIN 13 ES ROJO
  pinMode(10, OUTPUT); //PIN 10 ES AMARILLO
  pinMode(6, OUTPUT); //PIN 6 ES VERDE
  pinMode(2, INPUT); //PIN 2 ES EL PULSADOR
}

void loop() {
/**
 * Comporbamos que la varible iEstado sea igual a iEstadoRojo.
 * Si es verdad encendemos el led rojo que esta en el pin 13.
 * igualamos i a cero para hacer el while y salir a 1.
 * Mientras i sea menor a 5000 milisegundos y salir no sea igual a 0.
 * si i es menor que 5000 y salir es igual a 1: 
 * Comprovamos si se pulsa el pulsador, de ser pulsado igualamos salir a 0 e igualamos iEstado a iEstadoVerde,
 * sumamos 1 a la variable, hacemos un delay de 1 milisegundo y salimos del while.
 * Apagamos el led y comprobamos que salir no es igual a 0. Igualamos iEstado previo a iEstado e iEstado a iEstadoAmarillo. 
*/
  if (iEstado == iEstadoRojo) {
    digitalWrite(13, HIGH); //enciende el PIN 13 = A BOMBILLA ROJA
    i = 0; //igualamos i a cero para el while
    salir = 1; // igualamos salir a 1
    while (i < 5000 && salir != 0) {
      if (digitalRead(2) == true) {
        salir = 0;
        iEstado = iEstadoVerde;
      }
      i++;
      delay(1);
    }

    digitalWrite(13, LOW);

    if (salir != 0) {
      iEstadoPrevio = iEstado;
      iEstado = iEstadoAmarillo;
    }

  }
  else if (iEstado == iEstadoAmarillo) {
    digitalWrite(10, HIGH); //enciende el PIN 3 = A BOMBILLA ROJA
    i = 0;
    salir = 1;
    while (i < 5000 && salir != 0) {
      if (digitalRead(2) == true) {
        salir = 0;
        iEstado = iEstadoVerde;
      }
      i++;
      delay(1);
    }
    digitalWrite(10, LOW);
    if (iEstado != 0) {
      if (iEstadoPrevio == iEstadoRojo) {
        iEstado = iEstadoVerde;
      } else {
        iEstado = iEstadoRojo;
      }


    }

  }
  else if (iEstado == iEstadoVerde) {
    digitalWrite(6, HIGH); //enciende el PIN 3 = A BOMBILLA ROJA
    delay(5000);
    digitalWrite(6, LOW);
    iEstadoPrevio = iEstado;
    iEstado = iEstadoAmarillo;
  }
}
