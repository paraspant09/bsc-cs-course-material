#include<graphics.h>

void makeLineWithBresenham(int x1,int y1,int x2,int y2,int color){
	int x=x1,y=y1;
	int deltaX=(x2-x1),deltaY=(y2-y1);
	int Xinc = deltaX>0?1:-1; 
    int Yinc = deltaY>0?1:-1;
    
	if(x1>x2)	deltaX=-deltaX;
	if(y1>y2)	deltaY=-deltaY; 
		
	if(deltaY > deltaX){
		int P=2*deltaY-deltaX;
		while(Yinc*y<Yinc*y2){
			
			putpixel(x,y,color);
			y+=Yinc;
			
			if(P<0)
				P+=2*deltaX;
			else{
				P+=2*(deltaX-deltaY);
				x+=Xinc;		
			}
		}
	}
	else if(deltaX >= deltaY){
		int P=2*deltaX-deltaY;
		while(Xinc*x<Xinc*x2){
			
			putpixel(x,y,color);
			x+=Xinc;
			
			if(P<0)
				P+=2*deltaY;
			else{
				P+=2*(deltaY-deltaX);
				y+=Yinc;		
			}
		}
	}
}

