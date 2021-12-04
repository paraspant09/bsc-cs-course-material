#include<iostream>
#include<math.h>
#include<vector> 
#include<graphics.h>

using namespace std;

struct vertex{
	float x;
	float y;
};

int shift=300;

float* multVectorNMatrix(float a[3],float b[3][3]){
	
	float mult[3]={0};
	
	for(int i = 0; i < 3; ++i)
    	mult[i] += a[0] * b[0][i] + a[1] * b[1][i] + a[2] * b[2][i];
    
    return mult;
}

float* translate(int x0,int y0,int tx,int ty){
	float newM[3][3]={{1,0,0},{0,1,0},{tx,ty,1}};
	
	float point[3]={x0,y0,1};

	return multVectorNMatrix(point,newM);
}

float* scale(int x0,int y0,int sx,int sy){
	float newM[3][3]={{sx,0,0},{0,sy,0},{0,0,1}};
	
	float point[3]={x0,y0,1};

	return multVectorNMatrix(point,newM);
}

float* rotate(int x0,int y0,float theta){
	
	//convert theta to radian
	theta*=(3.14/180);
	cout<<theta<<"\n";
	
	float newM[3][3]={{cos(theta),sin(theta),0},{-sin(theta),cos(theta),0},{0,0,1}};
	
	float point[3]={x0,y0,1};

	return multVectorNMatrix(point,newM);
}

float* shearing(int x0,int y0,int xSh,int ySh){
	float newM[3][3]={{1,ySh,0},{xSh,1,0},{0,0,1}};
	
	float point[3]={x0,y0,1};

	return multVectorNMatrix(point,newM);
}

float* rotate_wrt_point(int x0,int y0,float px,float py,float theta){
	float* trans=translate(x0,y0,-px,-py);
	
	float* rot=rotate(trans[0],trans[1],theta);
	
	float* invtrans=translate(rot[0],rot[1],px,py);

	return invtrans;
}

float* reflection(int px,int py,float x0,float y0,float x1,float y1){
	float m,c,invtan;
	if((x1-x0) != 0){
		m=(y1-y0)/(x1-x0);
		c=y0-(m*x0);
		
		float* trans=translate(px,py,0,-c);
		
		float invtan=atan(m)*(180/3.14);
		
		float* rot=rotate(trans[0],trans[1],-invtan);
	
		rot[1]*=-1;
		
		float* invrot=rotate(rot[0],rot[1],invtan);
		
		float* invtrans=translate(invrot[0],invrot[1],0,c);
		
		return invtrans;
	}
	else{
		float* rot=rotate(px,py,-90);
	
		rot[1]*=-1;
		
		float* invrot=rotate(rot[0],rot[1],90);
		
		return invrot;
	}
}

vector<vertex> translatePolygon(vector<vertex> poly,int tx,int ty){
	vector<vertex> newpoly;
	
	for(int i=0;i<poly.size();i++){
		float* trans=translate(poly.at(i).x,poly.at(i).y,tx,ty);
		vertex v;
		v.x=trans[0];
		v.y=trans[1];
		newpoly.push_back(v);
	}
	return newpoly;
}

vector<vertex> scalePolygon(vector<vertex> poly,int sx,int sy){
	vector<vertex> newpoly;
	
	for(int i=0;i<poly.size();i++){
		float* scaled=scale(poly.at(i).x,poly.at(i).y,sx,sy);
		vertex v;
		v.x=scaled[0];
		v.y=scaled[1];
		newpoly.push_back(v);
	}
	return newpoly;
}

vector<vertex> rotatePolygon(vector<vertex> poly,float theta){
	vector<vertex> newpoly;
	
	for(int i=0;i<poly.size();i++){
		float* rotated=rotate(poly.at(i).x,poly.at(i).y,theta);
		vertex v;
		v.x=rotated[0];
		v.y=rotated[1];
		newpoly.push_back(v);
	}
	return newpoly;
}

vector<vertex> shearingPolygon(vector<vertex> poly,int xSh,int ySh){
	vector<vertex> newpoly;
	
	for(int i=0;i<poly.size();i++){
		float* shear=shearing(poly.at(i).x,poly.at(i).y,xSh,ySh);
		vertex v;
		v.x=shear[0];
		v.y=shear[1];
		newpoly.push_back(v);
	}
	return newpoly;
}

vector<vertex> rotatePolygon_wrt_point(vector<vertex> poly,float px,float py,float theta){
	vector<vertex> newpoly;
	
	for(int i=0;i<poly.size();i++){
		float* rotated=rotate_wrt_point(poly.at(i).x,poly.at(i).y,px,py,theta);
		vertex v;
		v.x=rotated[0];
		v.y=rotated[1];
		newpoly.push_back(v);
	}
	return newpoly;
}

vector<vertex> reflectPolygon(vector<vertex> poly,float x0,float y0,float x1,float y1){
	vector<vertex> newpoly;
	
	for(int i=0;i<poly.size();i++){
		float* reflected=reflection(poly.at(i).x,poly.at(i).y,x0,y0,x1,y1);
		vertex v;
		v.x=reflected[0];
		v.y=reflected[1];
		newpoly.push_back(v);
	}
	return newpoly;
}

vertex vertexshift(vertex v){
	return {v.x+shift , v.y+shift};
}

void viewPolygon(vector<vertex> poly,int color){
	setcolor(color);
	
	int num=poly.size();
	cout<<"\n\nNow you can see polygon.\n\n";
	
	for(int i=0;i<num;i++){
		vertex v=vertexshift(poly.at(i));
		vertex s=vertexshift(poly.at((i+1)%num));
		cout<<v.x<<" "<<v.y<<" ---> "<<s.x<<" "<<s.y<<"\n";
		line(v.x,v.y,s.x,s.y);
		
		if(num==2) break;
	}
	
}
