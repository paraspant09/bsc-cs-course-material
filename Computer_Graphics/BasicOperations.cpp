#include<graphics.h>

void makeCircle(){
	circle(200,200,100);
}

void makeLine(){
	line(20,30,300,500);
}

void usePixel(){
	for(int i=0;i<100;i++){
		putpixel(i,150,255);
	}
}

void makeLineWithAngle(){
	float m=1.0/3;
	int x,y;
	for(int x=0;x<=200;x++){
		y=m*x;
		putpixel(x,y,255);
	}
}
