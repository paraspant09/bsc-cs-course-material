#include<graphics.h>

void putpixelWithShift(int x,int y,int color,int a,int b){
	putpixel(100+a+x,100+b+y,RED);
}

void makeElipseWithPixel(int a,int b){
	float x=0,y=b;
	int asqr=a*a,bsqr=b*b;
	
	float p1=bsqr-(asqr*b)+(0.25*asqr);
	float dx=2*bsqr*x,dy=2*asqr*y;
	while(dx<dy){
		putpixelWithShift(x,y,RED,a,b);
		putpixelWithShift(-x,-y,RED,a,b);
		putpixelWithShift(x,-y,RED,a,b);
		putpixelWithShift(-x,y,RED,a,b);
		
		dx+=(2*bsqr);
		if(p1<0){
            p1+= dx + bsqr; 
		}
		else{
			dy-=(2*asqr);
            p1+= dx-dy + bsqr; 
			y--;		
		}
		x++;
	}
	
	float p2=(bsqr * ((x + 0.5) * (x + 0.5))) +  
         (asqr * ((y - 1) * (y - 1))) - 
          (asqr * bsqr);
    while(y>=0){
		putpixelWithShift(x,y,RED,a,b);
		putpixelWithShift(-x,-y,RED,a,b);
		putpixelWithShift(x,-y,RED,a,b);
		putpixelWithShift(-x,y,RED,a,b);
		
		dy-=(2*asqr);
		if(p2>0){
            p2+= asqr-dy; 	
		}
		else{
			dx+=(2*bsqr);
            p2+= dx-dy + asqr; 
			x++;		
		}
		y--;
	}
}
