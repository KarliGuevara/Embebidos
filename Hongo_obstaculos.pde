// beginShape() subrutina para inicio de figura
int i=0;
int x=0;
int y=0;

int torre1_lado1=0;
int torre1_lado2=0;
int torre1_lado3=0;
int torre1_lado4=0;

int torre2_lado1=0;
int torre2_lado2=0;
int torre2_lado3=0;
int torre2_lado4=0;

void setup(){
size(1200,900);
}

void draw(){
fill(200,10,150);
rect(250,200,150,400);
fill(200,10,150);
rect(550,500,200,100);
figura();

if((x>=195&&x<=340)
&& (y>=155&&y<=595))
{torre1_lado1=1;}
else {torre1_lado1=0;}

if((x>=195&&x<=390)
&& (y>=150&&y<=550))
{torre1_lado2=1;}
else {torre1_lado2=0;}

if((x>=190&&x<=390)
&& (y>=155&&y<=590))
{torre1_lado3=1;}
else {torre1_lado3=0;}

if((x>=195&&x<=395)
&& (y>=155&&y<=590))
{torre1_lado4=1;}
else {torre2_lado4=0;}
  

if((x>=495&&x<=640)
&& (y>=455&&y<=595))
{torre2_lado1=1;}
else {torre2_lado1=0;}

if((x>=495&&x<=640)
&& (y>=450&&y<=550))
{torre2_lado2=1;}
else {torre2_lado2=0;}

if((x>=490&&x<=640)
&& (y>=455&&y<=590))
{torre2_lado3=1;}
else {torre2_lado3=0;}

if((x>=495&&x<=545)
&& (y>=455&&y<=590))
{torre2_lado4=1;}
else {torre2_lado4=0;}
  
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
   switch(keyCode) {
  case 38:
    if(torre1_lado1==1
    ||torre2_lado1==1){}
  else{
    if(y>-5)
    y=y-5;
    else
    y=700;   
  }
      break;
  case 40:
  if(torre1_lado2==1
  ||torre2_lado2==1){}
  else
  {
  if(y<700)
    y=y+5;
    else 
    y=0;   
  }
    break;
  case 39:
  if(torre1_lado3==1
  ||torre2_lado3==1){}
    else
  {
    if(x<1170)
    x=x+5;
    else
    x=0; 
  }
    break;
  case 37:
  if(torre1_lado4==1
  ||torre2_lado4==1){}
  else
  {
   if(x>-5)
    x=x-5;
    else
    x=1170; 
  }
      break;
  }

}
