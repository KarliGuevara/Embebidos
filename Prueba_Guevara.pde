int x=0;
int y=0;
int i=0;

void setup(){
  size(1200,900);
  //background(255);
  
}

void draw(){
if (x>0)
{
 background(255);
  x++;
}

 dinosaurio();
 fill(255);
rect(300+x,50+y,25,25);

}

void dinosaurio(){
beginShape();

fill(100,100,150);
vertex(50/2+x,250/2+y);
vertex(100/2+x,250/2+y);
vertex(100/2+x,350/2+y);
vertex(150/2+x,350/2+y);
vertex(150/2+x,400/2+y);
vertex(200/2+x,400/2+y);
vertex(200/2+x,450/2+y);
vertex(300/2+x,450/2+y);
vertex(300/2+x,400/2+y);
vertex(350/2+x,400/2+y);
vertex(350/2+x,350/2+y);
vertex(400/2+x,350/2+y);
vertex(400/2+x,300/2+y);
vertex(450/2+x,300/2+y);
vertex(450/2+x,250/2+y);
vertex(500/2+x,250/2+y);
vertex(500/2+x,100/2+y);
vertex(550/2+x,100/2+y);
vertex(550/2+x,50/2+y);
vertex(800/2+x,50/2+y);
vertex(800/2+x,100/2+y);
vertex(850/2+x,100/2+y);
vertex(850/2+x,200/2+y);
vertex(650/2+x,200/2+y);
vertex(650/2+x,250/2+y);
vertex(850/2+x,250/2+y);
vertex(850/2+x,300/2+y);
vertex(600/2+x,300/2+y);
vertex(600/2+x,350/2+y);
vertex(700/2+x,350/2+y);
vertex(700/2+x,400/2+y);
vertex(600/2+x,400/2+y);
vertex(600/2+x,500/2+y);
vertex(550/2+x,550/2+y);
vertex(550/2+x,650/2+y);
vertex(500/2+x,650/2+y);
vertex(500/2+x,600/2+y);
vertex(450/2+x,600/2+y);
vertex(450/2+x,550/2+y);
vertex(400/2+x,550/2+y);
vertex(400/2+x,600/2+y);
vertex(350/2+x,600/2+y);
vertex(350/2+x,650/2+y);
vertex(300/2+x,650/2+y);
vertex(300/2+x,550/2+y);
vertex(150/2+x,550/2+y);
vertex(150/2+x,500/2+y);
vertex(100/2+x,500/2+y);
vertex(100/2+x,450/2+y);
vertex(50/2+x,450/2+y);
vertex(50/2+x,250/2+y);


endShape(); 
}


void keyPressed(){
background(255);  
switch(keyCode){
  case 38:
  y=y-10;
  break;
  case 40:
  y=y+10;
  break;
  case 39:
  x=x+10;
  break;
  case 37:
  x=x-10;
  break;
}

}
