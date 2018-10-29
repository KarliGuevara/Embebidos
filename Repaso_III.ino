/*
 *          Universidad Técnica del Norte
 *   Facultad de Ingenierías en Ciencias Aplicadas
 * Carrera de Electrónica y Redes de la Comunicación
 * 
 * Nombre:Karla Guevara
 * Fecha: 29 de octubre 2018
 * 
 * Embebidos
 */
#include <MsTimer2.h>
#include <LiquidCrystal.h> 
LiquidCrystal lcd(13,12,11,10,9,8);

int i=0;
int encendido =0;

void setup() {
lcd.begin(16,2);
Serial.begin(9600);
MsTimer2::set(1000,conteo);// trabajar con 1 segundo
MsTimer2::start();// inicializacion timer 2
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
pinMode(5,OUTPUT);
attachInterrupt(0,on,LOW);// interrupcion de encendido
}

void loop() {
}

void conteo(){
  if(encendido==1) //metodo de conteo 
  lcd.clear(); // limpiamos LCD
  lcd.setCursor(5,0);// posicionamos el cursor
  lcd.print(i);// Imprimos el contador
  i++;

  if(i==20) {
  digitalWrite(5,HIGH);
  lcd.setCursor(0,1);
  lcd.print("1 ON");
  }
  if(i==30){
  digitalWrite(5,LOW);
  lcd.clear();
  }
  

  if(i==25){  
  digitalWrite(6,HIGH);
  lcd.setCursor(6,1);
  lcd.print("2 ON");
  }
  if(i==35){
  digitalWrite(6,LOW);
  lcd.clear();
  }

  if(i==30){  
  digitalWrite(7,HIGH);
  lcd.setCursor(11,1);
  lcd.print("3 ON");
  }
  if(i==25){
  digitalWrite(7,LOW);
  lcd.clear();
  }
}

void on(){
  encendido = 1- encendido;
  if(encendido==1)
  lcd.setCursor(0,0);
  lcd.print("Sistema encendido");

}

