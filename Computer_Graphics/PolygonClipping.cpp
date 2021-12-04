#include<graphics.h>
#include<iostream>
#include<vector> 

using namespace std; 

struct vertex{
	int x;
	int y;
};
struct clipBoundary{
	double xmin;
	double xmax;
	double ymin;
	double ymax;
};

void PolygonClip(vector<vertex> inPolygon,clipBoundary cB){
	vector<vertex> outPolygon;
	vertex joining;
	bool isjoining=false;
	//left clip
	for(int i=0;i<inPolygon.size();i+=2){
		vertex s=inPolygon.at(i);
		vertex p=inPolygon.at(i+1);
		
		if(s.x>=cB.xmin && p.x>=cB.xmin ){
			outPolygon.push_back(s);
			outPolygon.push_back(p);
		}
		else if(s.x<=cB.xmin && p.x>=cB.xmin ){
			s.y = s.y + (p.y - s.y) * (cB.xmin - s.x) / (p.x - s.x); 
            s.x = cB.xmin;
			outPolygon.push_back(s);
			outPolygon.push_back(p);
			if(!isjoining){
				joining=s;
				isjoining=true;
			}
			else{
				outPolygon.push_back(joining);
				outPolygon.push_back(s);
				isjoining=false;
			}
		}
		else if(s.x>=cB.xmin && p.x<=cB.xmin ){
			p.y = s.y + (p.y - s.y) * (cB.xmin - s.x) / (p.x - s.x); 
            p.x = cB.xmin;
			outPolygon.push_back(s);
			outPolygon.push_back(p);
			
			if(!isjoining){
				joining=p;
				isjoining=true;
			}
			else{
				outPolygon.push_back(p);
				outPolygon.push_back(joining);	
				isjoining=false;
			}
		}
	}
	
	inPolygon.clear();
	copy(outPolygon.begin(), outPolygon.end(), back_inserter(inPolygon)); 
	outPolygon.clear();

	//right clip
	for(int i=0;i<inPolygon.size();i+=2){
		vertex s=inPolygon.at(i);
		vertex p=inPolygon.at(i+1);
		
		if(s.x<=cB.xmax && p.x<=cB.xmax ){
			outPolygon.push_back(s);
			outPolygon.push_back(p);
		}
		else if(s.x<=cB.xmax && p.x>=cB.xmax ){
			p.y = s.y + (p.y - s.y) * (cB.xmax - s.x) / (p.x - s.x); 
            p.x = cB.xmax;
            outPolygon.push_back(s);
			outPolygon.push_back(p);
			
			if(!isjoining){
				joining=p;
				isjoining=true;
			}
			else{
				outPolygon.push_back(p);
				outPolygon.push_back(joining);	
				isjoining=false;
			}
		}
		else if(s.x>=cB.xmax && p.x<=cB.xmax ){
			s.y = s.y + (p.y - s.y) * (cB.xmax - s.x) / (p.x - s.x); 
            s.x = cB.xmax;
			outPolygon.push_back(s);
			outPolygon.push_back(p);
			if(!isjoining){
				joining=s;
				isjoining=true;
			}
			else{
				outPolygon.push_back(joining);
				outPolygon.push_back(s);
				isjoining=false;
			}
		}
	}
	
	inPolygon.clear();
	copy(outPolygon.begin(), outPolygon.end(), back_inserter(inPolygon)); 
	outPolygon.clear();
	//top clip
	for(int i=0;i<inPolygon.size();i+=2){
		vertex s=inPolygon.at(i);
		vertex p=inPolygon.at(i+1);
		
		if(s.y<=cB.ymax && p.y<=cB.ymax ){
			outPolygon.push_back(s);
			outPolygon.push_back(p);
		}
		else if(s.y<=cB.ymax && p.y>=cB.ymax ){
			p.x = s.x + (p.x - s.x) * (cB.ymax - s.y) / (p.y - s.y); 
            p.y = cB.ymax;
            outPolygon.push_back(s);
			outPolygon.push_back(p);
			
			if(!isjoining){
				joining=p;
				isjoining=true;
			}
			else{
				outPolygon.push_back(p);
				outPolygon.push_back(joining);	
				isjoining=false;
			}
		}
		else if(s.y>=cB.ymax && p.y<=cB.ymax ){
			s.x = s.x + (p.x - s.x) * (cB.ymax - s.y) / (p.y - s.y); 
            s.y = cB.ymax;
            
			outPolygon.push_back(s);
			outPolygon.push_back(p);
			if(!isjoining){
				joining=s;
				isjoining=true;
			}
			else{
				outPolygon.push_back(joining);
				outPolygon.push_back(s);
				isjoining=false;
			}
		}
	}
	
	inPolygon.clear();
	copy(outPolygon.begin(), outPolygon.end(), back_inserter(inPolygon)); 
	outPolygon.clear();
	
	//bottom clip
	for(int i=0;i<inPolygon.size();i+=2){
		vertex s=inPolygon.at(i);
		vertex p=inPolygon.at(i+1);
		
		if(s.y>=cB.ymin && p.y>=cB.ymin ){
			outPolygon.push_back(s);
			outPolygon.push_back(p);
		}
		else if(s.y<=cB.ymin && p.y>=cB.ymin ){
			s.x = s.x + (p.x - s.x) * (cB.ymin - s.y) / (p.y - s.y); 
            s.y = cB.ymin;
			outPolygon.push_back(s);
			outPolygon.push_back(p);
			
			if(!isjoining){
				joining=s;
				isjoining=true;
			}
			else{
				outPolygon.push_back(joining);
				outPolygon.push_back(s);
				isjoining=false;
			}
		}
		else if(s.y>=cB.ymin && p.y<=cB.ymin ){
			p.x = s.x + (p.x - s.x) * (cB.ymin - s.y) / (p.y - s.y); 
            p.y = cB.ymin;
			outPolygon.push_back(s);
			outPolygon.push_back(p);
			
			if(!isjoining){
				joining=p;
				isjoining=true;
			}
			else{
				outPolygon.push_back(p);
				outPolygon.push_back(joining);	
				isjoining=false;
			}
		}
	}
//	cout<<outPolygon.size()<<"\n";
	for(int i=0;i<outPolygon.size();i+=2){
		vertex s=outPolygon.at(i);
		vertex p=outPolygon.at(i+1);

		cout<<s.x<<","<<s.y<<","<<p.x<<","<<p.y<<"\n";
		setcolor(BLUE);
		line(s.x,s.y,p.x,p.y);
	}
}

