#include<graphics.h>

int abs (int n) 
{ 
    return ( (n>0) ? n : ( n * (-1))); 
} 
  
void makeLineWithDDA(int X0, int Y0, int X1, int Y1,int color) 
{ 
    int dx = X1 - X0; 
    int dy = Y1 - Y0; 
  
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
   
    float Xinc = dx / (float) steps; 
    float Yinc = dy / (float) steps; 
  
    float X = X0; 
    float Y = Y0; 
    for (int i = 0; i <= steps; i++) 
    { 
        putpixel (X,Y,color);  
        X += Xinc;           
        Y += Yinc;           
    } 
} 
