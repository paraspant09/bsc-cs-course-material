#include<graphics.h>

void putpixelWithShift(int x,int y,int color,int radius){
	putpixel(100+radius+x,100+radius+y,RED);
}

void makeCircleWithPixel(int radius){
	int x=0,y=radius;
	int d=1-radius;		//(5/4 - r)
	while(y>=x){
		putpixelWithShift(x,y,RED,radius);
		putpixelWithShift(y,x,RED,radius);
		putpixelWithShift(-x,-y,RED,radius);
		putpixelWithShift(-y,x,RED,radius);
		putpixelWithShift(x,-y,RED,radius);
		putpixelWithShift(y,-x,RED,radius);
		putpixelWithShift(-x,y,RED,radius);
		putpixelWithShift(-y,-x,RED,radius);
		if(d<0)
			d+=2*x+3;
		else{
			d+=2*(x-y)+5;
			y--;		
		}
		x++;
	}
}
