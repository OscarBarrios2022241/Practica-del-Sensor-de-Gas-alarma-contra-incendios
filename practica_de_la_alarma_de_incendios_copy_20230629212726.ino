//Oscar Jose Barrios Cotom - 2022241
//EB5AM

#include "LedControl.h"//incluye libreria LedControl
int buzzer = 9;//Buzzer al pin 9
int SensorA0 = A5;//El A0 del sensor va directo al pin A5 del Arduino
LedControl lc=LedControl(11,13,10,1); //Se definen los pines y se coloca cuantas matrices se usan
int Umbral = 265;//Variable umbral la cual cuando llegue a este parametro nos mandara una señal al buzzer para que encienda

byte uno[8]= {//Simbolo de la llama
  B00101000,
  B00001101,
  B10011100,
  B00111110,
  B01111111,
  B01111111,
  B01111110,
  B00111100
};


void setup() {
  pinMode(buzzer, OUTPUT);//Se configura el pin como salida
  pinMode(SensorA0, INPUT);//Se configura el pin como entrada
  Serial.begin(9600);//Se inicializa el monitor serial
  lc.shutdown(0,false);//Enciende la matriz
  lc.setIntensity(0,4);//Establece brillo
  lc.clearDisplay(0);//Blanquea matriz

}

void loop() {
  int LecturaSensor = analogRead(SensorA0);//Se crea la variable LecturaSensor y se iguala con la variable del pin A5

  Serial.print("Pin A0:");//Valores que da el pin A5
  Serial.println(LecturaSensor);//Se imprimen los valores del pin 5

  if(LecturaSensor > Umbral)//Si la variable lectura del sensor es mayor al la variable umbral entonces el buzzer encendera y mostra el simbolo de la llama
  {
    digitalWrite(buzzer, HIGH);//Buzzer se enciende
    mostrar_1();//Muestra el digito de la llama
  }
  else//Si ya no llega al valor establecido (265) entonces el buzzer se apaga y la matriz se limpia por lo que no imprime datos
  {
    digitalWrite(buzzer, LOW);//Se apaga el buzzer
    lc.clearDisplay(0);//Blanquea la matriz
  }
  delay(100);//Tiempo que tarda en ejecutarse todo esto
}

void mostrar_1(){//funcion mostrar_1
  for (int i = 0; i < 8; i++)//bucle itera 8 veces por el array
  {
  lc.setRow(0,i,uno[i]);//establece fila con valor de array uno en misma posicion
  }
}
