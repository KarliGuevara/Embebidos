#include"datos_entrenamiento.h"
#include"datos_test.h"
int col=0;
int row=0;
float distancia=0;
float dist_menor=1000;
int columna=0;
int fila=0;
int k[3]={0,0,0};
int vector[50];
int i=3;
void setup() {
 Serial.begin(9600);
}

void loop() {

  if(fila=0){
  for(;row<120;row++){ // contador de filas (for lento)
       distancia= sqrt( pow((matriz[row][0]-prueba[19][0]),2)+
                        pow((matriz[row][1]-prueba[19][1]),2)+
                        pow((matriz[row][2]-prueba[19][2]),2)+
                        pow((matriz[row][3]-prueba[19][3]),2));
      if(dist_menor>distancia){ 
       dist_menor=distancia; 
       columna++;
       Serial.println(matriz[row][4]);
      }             
      
  }
  fila=1;
  }
  
 if (fila == 1) {
    Serial.println("Distancias mas cortas");
    if (Serial.available()>0){
    for (i=Serial.read(); i > 0; i--) {
      Serial.println(" ");
      Serial.println(vector[columna - i]);
      if (vector[columna - i] == 1)
        k[0]++; 
      if (vector[columna - i] == 2)
          k[1]++;  
      if (vector[columna - i] == 3)
             k[2]++;
      }
    }

    fila = 2;
  }

  if (fila == 2) {
  columna = k[0];
  for (int j = 0; j < 2; j++) {
  if (k[0] < k[j + 1])
     columna = k[j + 1];
    }
    
    for (int j = 0; j < 3; j++) {
      if (columna == k[j]) {
        
        if (j == 0)
          Serial.println("Iris_setosa");
        if (j == 1)
          Serial.println("Iris_versicolor");
       if (j == 2)
             Serial.println("Iris_virginica");  
       } 
    }
    fila = 3;
  }

}
  

