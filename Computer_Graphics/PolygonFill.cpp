#include<graphics.h>
#include<vector> 
#include <bits/stdc++.h>

using namespace std;

struct vertex{
	int x;
	int y;
};

void PolygonFill(vector<vertex> inPolygon,int color){
	vector<float> xintrscts;
	int maxy=0,miny=getmaxy();
	
	for(int i=0;i<inPolygon.size();i++){
		int y=inPolygon.at(i).y;
		if(y>maxy)	maxy=y;
		if(y<miny)	miny=y;
	}
	
	for(float y=miny;y < maxy;y+=1){
		for(int i=0;i<inPolygon.size();i+=2){
			vertex s=inPolygon.at(i);
			vertex p=inPolygon.at(i+1);
			
			if(min(s.y,p.y) < y && max(s.y,p.y) > y){
				vertex v;
				v.x = s.x + (p.x - s.x) * (y - s.y) / (p.y - s.y); 
            	v.y=y;
            	xintrscts.push_back(v.x);
            	//cout<<v.x<<",";
			}
			else if(s.y == y){
				if(p.y>s.y){
					//cout<<s.x<<".";
					xintrscts.push_back(s.x);	
				}	
			}
			else if(p.y == y){
				if(p.y<s.y){
					//cout<<p.x<<".";
					xintrscts.push_back(p.x);	
				}	
			}
		}
		//cout<<"\n";
		sort(xintrscts.begin(), xintrscts.end());
		
		setcolor(color);
		for(int i=0;i<xintrscts.size();i+=2){
//			delay(10);
			line(xintrscts.at(i),y,xintrscts.at(i+1),y);
		}
		xintrscts.clear();
	}
}


