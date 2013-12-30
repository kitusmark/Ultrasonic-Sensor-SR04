/********************************************************
Ultrasonic distance Sensor using NewPing library
by Marc Cobler
30/12/2013

Este código nos proporciona la distancia en centimetros al sensor
por el monitor serial. Utilizamos la libreria NewPing.h que se 
puede encontrar en:
https://code.google.com/p/arduino-new-ping/

Solo necesitamos 4 cables para conectar el sensor. Los de alimentación,
trigger (disparo) y echo (detección de sonido). La libreria realiza todos 
los cálculos por nosotros.

*********************************************************/
#include <NewPing.h>

#define trigger 12 //pin para el emisor de la señal
#define echo 11 //pin para el retorno de la onda
#define distancia_max 250 //Máxima distancia que nos calculará la libreria

NewPing sensor(trigger, echo, distancia_max); //Creamos una variable del tipo sensor
//--------------------------------------------------------
void setup()
{
  Serial.begin(19200); //19200 baudios es suficiente
}
//--------------------------------------------------------
void loop()
{
  delay(100); // Esperamos 50 milisegundos entre lecturas
  unsigned int tiempo = sensor.ping(); //obtenemos el tiempo de un pulso en microsegundos
  Serial.print("Distancia: ");
  Serial.print(tiempo / US_ROUNDTRIP_CM); //Pasamos el tiempo a centímetros mediante una constante
  Serial.println(" cm"); //Retorno de carro
}
//--------------------------------------------------------
