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
#include <Keypad.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

char teclas [4] [4] = {{'1', '4', '7', 'X'},{'2', '5', '8', '0'},{'3', '6', '9', '='},{'+', '-', '*', '/'}}; // Asignacion de teclas
byte filas[4] = {3, 2, 1, 0}; //Definimos lineas
byte columnas[4] = {7 ,6 ,5 ,4}; //Definimos columnas
Keypad teclado = Keypad( makeKeymap(teclas),filas,columnas, 4, 4 );
boolean valorActual = false;
boolean siguiente = false;
boolean final = false;
String num1,num2,num3;
int total;
int movimiento;
char operacion;
float r1,r2,r3,r4;
float decimal;
int cont=0;

void setup(){
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print(">");
}

void loop()
{
 char tecla = teclado.getKey();
 int tam; 

 // Verifico que se presionó una teclada determinada.
 if (tecla != NO_KEY && (tecla=='1'||tecla=='2'||tecla=='3'||tecla=='4'||tecla=='5'||tecla=='6'||tecla=='7'||tecla=='8'||tecla=='9'||tecla=='0'))
 {
   // Inicialización de las variables
   if (cont == 1){
      lcd.clear();
      valorActual = false;
      final = false;
      num1= "";
      num2= "";
      total= 0;
      operacion = ' ';
      lcd.setCursor(0,0);
      lcd.print(">");
      cont=0;                  
                   }
   if (valorActual != true){
       num1= num1 + tecla;
       tam= num1.length();
       movimiento = tam;
       lcd.setCursor(1, 0);
       lcd.print(num1);
   } else {
       num2 = num2 + tecla;
       tam = num2.length();
       lcd.setCursor(movimiento+2, 0);
       lcd.print(num2);
       final = true;
                                 }
  } else if ((tecla == '+' || tecla == '-' || tecla == '*' || tecla == '/') && valorActual == false && tecla != NO_KEY)
{
 if (valorActual == false){
    valorActual = true;
    operacion = tecla;
    lcd.setCursor(movimiento+1,0);
    lcd.print(operacion);
                         }
 } else if (final == true && tecla != NO_KEY && tecla == '=')
 {
  
   switch (operacion) { //usamos casos pra las distintas operaciones 
    case '+':
      total = num1.toInt() + num2.toInt();// suma
      break;
    case '-':
      total = num1.toInt() - num2.toInt();//resa
      break;
    case '*':
      total = num1.toInt() * num2.toInt();//multiplicacion 
      break;
    case '/':// division 
      if(num2.toInt()==0){
        total = 'E'; // Error al dividor por 0 (cero)//division
        }else
        {
        total = (num1.toInt()) / (num2.toInt());
        r1=num1.toInt();// Asignacion en r1 = calculo de los numeros decimales
        r2=num2.toInt();// Asignacion en r2 = calculo de los numeros decimales
        decimal= r1/r2;// Asignacion en decimal para la division entre r1/r2 = numero decimal
        }
      break;
    default: 
      // opcion por defecto
    break;
  }
 num3=String(total);
 lcd.clear();
 lcd.setCursor(15,0);
 lcd.autoscroll();
 if(total=='E'){
   lcd.print(" Err.de Sintaxis");
   } else if(num3.length()>4){
   lcd.print("*Sin Memoria*");
   }else{
 if (operacion == '/') {lcd.print(decimal,2);} 
    else {lcd.print(total);}; 
    cont=1;
                                                        }
lcd.noAutoscroll();
} else if (tecla == 'X' && tecla != NO_KEY){
  lcd.clear();
  valorActual = false;
  final = false;
  num1 = "";
  num2 = "";
  total = 0;
  operacion = ' ';
  lcd.setCursor(0,0);
  lcd.print(">");
 }
}

