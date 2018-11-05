
int datos[10][4]= {{3,5,-6,7},{3,8,6,17},{2,-4,4,27},{2,4,8,10},{2,4,-2,5},
{4,5,6,7},{5,-8,6,-7},{1,5,16,8},{0,5,12,7},{4,5,16,7}};

char val;
float sum=0;

void setup(){
  Serial.begin(9600);
  Serial.println("Seleccione uno de los items");
  Serial.println("a} Promedio filas");
  Serial.println("b} Promedio columnas");
  Serial.println("c) Numero mas alto de cada fila");
  Serial.println("d} Numero mas bajo de cada columna");
  Serial.println("e) Numero mas alto de la matriz");
  Serial.println("f} Numero mas bajo de la matriz");
}


void loop (){
  val=Serial.read();
  
  switch(val){
   case'a':
   Serial.println("Promedio filas");
   a();
   break;   

   case'b':
   Serial.println("Promedio columnas");
   b();
   break; 

   case'c':
   Serial.println("Numero mas alto de cada fila");
   c();
   break;

   case'd':
   Serial.println("Numero mas bajo de cada columna");
   d();
   break;

   case'e':
   Serial.println("Numero mas alto de la matriz");
   e();
   break;

   case'f':
   Serial.println("Numero mas bajo de la matriz");
   f();
   break;
  }
}

void a(){
  for (int i=0; i<10; i++){
    for (int j=0; j<4; j++){
      sum=sum+datos[i][j];
    }
    Serial.print("fila ");
    Serial.print(i+1);
    Serial.print(": ");
    Serial.println(sum/4);
    sum=0;
  }
  sum=0;
}

void b(){
  for (int j=0; j<4; j++){
    for (int i=0; i<10; i++){
      sum=sum+datos[i][j];
    }
    Serial.print("columna ");
    Serial.print(j+1);
    Serial.print(": ");
    Serial.println(sum/10);
    sum=0;
  }
  sum=0;
}

void c(){
 int mayor=0;
  for (int i=0; i<10; i++){
      mayor=datos[i][0];
      for (int j=0; j<3; j++){
        if (mayor<datos[i][j+1])
        mayor =datos[i][j+1];
      }
    Serial.print("fila ");
    Serial.print(i+1);
    Serial.print(": ");
    Serial.println(mayor);
  }
}

void d(){
  int menor=0;
  for (int j=0; j<4; j++){
      menor=datos[0][j];
      for (int i=0; i<9; i++){
        if (menor<datos[i+1][j])
        menor =datos[i+1][j];
      }
    Serial.print("fila ");
    Serial.print(j+1);
    Serial.print(": ");
    Serial.println(menor);
  }
}

void e(){
  int mayor=0;
  for(int i=0; i<10; i++){
    for (int j=0; j<4; j++){
      if (datos[i][j]>mayor)
      mayor=datos[i][j];
    }
  }
  Serial.println(mayor);
}

void f(){
  int menor=0;
  for(int i=0; i<10; i++){
    for (int j=0; j<4; j++){
      if (menor>datos[i][j])
      menor=datos[i][j];
    }
  }
  Serial.println(menor);
}
