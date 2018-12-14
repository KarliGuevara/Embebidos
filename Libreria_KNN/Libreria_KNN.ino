#include"datos_entrenamiento.h"
int fil_x1 = 80;
int fil_y1 = 120;
float radio = 0.2;
float promedio[4] = {0, 0, 0, 0};
int encender = 1;
float prom = 0;
float distancia = 0;
float dis_total[40];
float dis_normal[40];
float dis_max = 0;
float matrizreducida[40][5];
int fil_x2 = 0;
int columna = 0;
int cont = 0;

void setup() {
  Serial.begin(9600);
}
void loop() {
  if (encender == 1) {
    fil_x2 = fil_x1;
    for (;columna<4;columna++) {
      for (;fil_x1<fil_y1;fil_x1++) {
        prom=prom+matriz[fil_x1][columna];
      }
      promedio[columna]=prom/(fil_x1-fil_x2);
      fil_x1=fil_x2;
      prom=0;
    }
    fil_x1=fil_x2;
    columna=0;

    for (;fil_x1<fil_y1;fil_x1++) {
      for (;columna<4;columna++) {
        distancia=distancia+ 
        pow(matriz[fil_x1][columna]-promedio[columna],2);
      }
      dis_total[fil_x1-fil_x2]=sqrt(distancia);
      if (dis_total[fil_x1-fil_x2]>dis_max)
        dis_max=dis_total[fil_x1-fil_x2];
      columna=0;
      distancia=0;
    }
    fil_x1=fil_x2;
   
    for (;fil_x1<fil_y1;fil_x1++) {
      dis_normal[fil_x1-fil_x2]=dis_total[fil_x1-fil_x2]/dis_max;
    }
    fil_x1=fil_x2;
    for (;fil_x1<fil_y1;fil_x1++) {
      if (dis_normal[fil_x1-fil_x2]<radio) {
        for (;columna<5;columna++) {
          matrizreducida[cont][columna] = matriz[fil_x1][columna];
        }
        cont++;
      }
      columna = 0;
    }
    fil_x1=fil_x2;
   
    for (int i=0;i<cont;i++) {
      for (;columna<5;columna++) {
        Serial.print(matrizreducida[i][columna]);
        Serial.print(" ");
      }
      Serial.println(" ");
      columna=0;
    }
  }
  encender=2;
}
