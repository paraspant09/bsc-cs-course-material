#include<math.h>
#include<vector> 

using namespace std;

struct vertex{
	float x;
	float y;
};

int factorial(int n)    
{    
	if(n<0)    
		return(-1); /*Wrong value*/      
	if(n==0)    
		return(1);  /*Terminating condition*/    
	else    
	{    
		return(n*factorial(n-1));        
	}    
}  

float nCr(int n,int r){
	return( factorial(n) / ( factorial(r) * factorial(n-r) ) );
}

vector<vertex> BezierCurve(vector<vertex> points){
	int n=points.size();
	vector<vertex> curvepoints;
	for(float u=0;u<=1;u+=0.0001){
		vertex p={0,0};
		for(int i=0;i<n;i++){
			float B=nCr(n-1,i)*pow((1-u),(n-1)-i)*pow(u,i);
			float px=points.at(i).x*B;
			float py=points.at(i).y*B;
			
			p.x+=px;
			p.y+=py;
			
		}
		curvepoints.push_back(p);
	}
	
	return curvepoints;
}

vector<vertex> HermiteCurve(vertex p1,vertex p4,vertex r1,vertex r4){
    float x,y,t;
    vector<vertex> curvepoints;
    for(t=0.0;t<=1.0;t+=0.001)
    {
        x=(2*t*t*t-3*t*t+1)*p1.x+(-2*t*t*t+3*t*t)*p4.x+(t*t*t-2*t*t+t)*r1.x+(t*t*t-t*t)*r4.x;
        y=(2*t*t*t-3*t*t+1)*p1.y+(-2*t*t*t+3*t*t)*p4.y+(t*t*t-2*t*t+1)*r1.y+(t*t*t-t*t)*r4.y;
        curvepoints.push_back({x,y});
    }
    return curvepoints;
}

