// beginShape() subrutina para inicio de figura
int i=0;
int x=0;
int y=0;

void setup(){

size(1200,900);

}


void draw(){
fill(200,10,150);
rect(250,200,150,400);
fill(200,10,150);
rect(750,200,150,400);
figura();
}


void figura(){
beginShape();
fill(247,98,67);
vertex(10+x,20+y);
vertex(15+x,20+y);
vertex(15+x,15+y);
vertex(20+x,15+y);
vertex(20+x,10+y);
vertex(45+x,10+y);
vertex(45+x,15+y);
vertex(50+x,15+y);
vertex(50+x,20+y);
vertex(55+x,20+y);
vertex(55+x,30+y);
vertex(45+x,30+y);
vertex(45+x,25+y);
vertex(20+x,25+y);
vertex(20+x,30+y);
vertex(10+x,30+y);
vertex(10+x,20+y);
endShape();

//cara




beginShape();
fill(255,235,205);
vertex(15+x,30+y);
vertex(15+x,40+y);
vertex(20+x,40+y);
vertex(20+x,45+y);
vertex(45+x,45+y);
vertex(45+x,40+y);
vertex(50+x,40+y);
vertex(50+x,30+y);//
vertex(45+x,30+y);
vertex(45+x,25+y);
vertex(20+x,25+y);
vertex(20+x,30+y);
vertex(15+x,30+y);
endShape();
fill(0);
rect(25+x,25+y,5,7.5);
rect(35+x,25+y,5,7.5);
}

void keyPressed(){
background(255);  
//println(keyCode);// key-> convierte de hexa a letra, key Code->solo recibe hex
//textSize(20);
//text(keyCode,100,50);
switch(keyCode){
  case 38:
  y=y-5;
  break;
  case 40:
  y=y+5;
  break;
  case 39:
  x=x+5;
  break;
  case 37:
  x=x-5;
  break;
}

}
