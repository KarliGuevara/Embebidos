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
#include <LiquidCrystal.h> 
LiquidCrystal lcd(13,12,11,10,9,8);

void setup() {
  lcd.begin(16,2); // Definir columnas y filas 
  Serial.begin(9600);// Iniciando cx serial
}

void loop() {  
  String textos[2] = {"FICA", "CIERCOM"}; // Declaramos un arreglo de 2 posiciones
  for(int i=0;i<2;i++)// recorrer palabras // Recorremos posiciones 
  {
    String texto=textos[i];
    
    for(int j=16-1;j>=0;j--)// Recorremos columnas
    {
      lcd.clear(); // Limpiamos LCD 
      lcd.setCursor(j,1);// Nos posicionamos en la ultima columna
      lcd.print(texto);// Escribimos el texto
      delay(500);
    }
    
    for(int j=1;j<texto.length();j++) // Desaparemos el texto por la izquierda
    {
      lcd.clear(); // Limpiamos LCD
      lcd.setCursor(0,1); // Nos posicionamos en la ultima columna
      lcd.print(texto.substring(j)); //Eliminamos letra a letra por la izquierda
      delay(500);
      
    }
  }
}
