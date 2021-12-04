#include<graphics.h>
#include<iostream>
#include<vector> 

using namespace std;
typedef unsigned int outcode;

struct vertex{
	float x;
	float y;
};

struct vertex3d{
	float x;
	float y;
	float z;
};

struct edge3d{
	int ver1;
	int ver2;
};

enum TranformAboutAxis { X , Y , Z };

struct clipBoundary{
	double xmin;
	double xmax;
	double ymin;
	double ymax;
};

void makeCircle();

void makeLine();

void usePixel();

void makeLineWithAngle();

void makeLineWithBresenham(int x1,int y1,int x2,int y2,int color);

void putpixelWithShift(int x,int y,int color,int radius);

void putpixelWithShift(int x,int y,int color,int a,int b);

void makeCircleWithPixel(int radius);

void makeElipseWithPixel(int a,int b);

int abs (int n);
  
void makeLineWithDDA(int X0, int Y0, int X1, int Y1,int color);

outcode computeCode(double xmin, double xmax,double ymin, double ymax);

void cohenSutherlandClipAndDraw(double x0, double y0, double x1, double y1,
		double xmin, double xmax,double ymin, double ymax) ;

void PolygonClip(vector<vertex> inPolygon,clipBoundary cB);

void PolygonFill(vector<vertex> inPolygon,int color);

// 2-d transformations

float* multVectorNMatrix(float a[3],float b[3][3]);

float* translate(int x0,int y0,int tx,int ty);

float* scale(int x0,int y0,int sx,int sy);

float* rotate(int x0,int y0,float theta);

float* shearing(int x0,int y0,int xSh,int ySh);

float* rotate_wrt_point(int x0,int y0,float px,float py,float theta);

float* reflection(int px,int py,float x0,float y0,float x1,float y1);

vector<vertex> translatePolygon(vector<vertex> poly,int tx,int ty);

vector<vertex> scalePolygon(vector<vertex> poly,int sx,int sy);

vector<vertex> rotatePolygon(vector<vertex> poly,float theta);

vector<vertex> shearingPolygon(vector<vertex> poly,int xSh,int ySh);

vector<vertex> rotatePolygon_wrt_point(vector<vertex> poly,float px,float py,float theta);

vector<vertex> reflectPolygon(vector<vertex> poly,float x0,float y0,float x1,float y1);

vertex vertexshift(vertex v);

void viewPolygon(vector<vertex> poly,int color);

// 3-d transformations

float* multVectorNMatrix_3D(float a[4],float b[4][4]);

float* translate_3D(float x0,float y0,float z0,float tx,float ty,float tz);

float* scale_3D(float x0,float y0,float z0,float sx,float sy,float sz);

float* rotate_3D(float x0,float y0,float z0,float theta,TranformAboutAxis axis);

float* shearing_3D(float x0,float y0,float z0,float xSh,float ySh,float zSh);

float* rotate_wrt_line_3D(float x0,float y0,float z0,vertex3d p1,vertex3d p2,float theta);

float* reflect_wrt_plane_3D(float x0,float y0,float z0,vertex3d p1,vertex3d p2,vertex3d p3);

float* project_3D(float x0,float y0,float z0,float p,float q,float r);

vector<vertex3d> translateMesh_3D(vector<vertex3d> mesh,float tx,float ty,float tz);

vector<vertex3d> scaleMesh_3D(vector<vertex3d> mesh,float sx,float sy,float sz);

vector<vertex3d> rotateMesh_3D(vector<vertex3d> poly,float theta,TranformAboutAxis axis);

vector<vertex3d> shearingMesh_3D(vector<vertex3d> mesh,float xSh,float ySh,float zSh);

vector<vertex3d> rotateMesh_wrt_line_3D(vector<vertex3d> mesh,vertex3d p1,vertex3d p2,float theta);

vector<vertex3d> reflectMesh_wrt_plane_3D(vector<vertex3d> mesh,vertex3d p1,vertex3d p2,vertex3d p3);

vector<vertex3d> projectMesh_3D(vector<vertex3d> mesh,float p,float q,float r);

vertex3d vertexshift_3D(vertex3d v);

void viewMesh(vector<vertex3d> mesh,vector<edge3d> meshedges);

void viewProjectedMesh(vector<vertex3d> mesh,vector<edge3d> meshedges,float shift);

//Hermite and bezier curve
int factorial(int n);

int nCr(int n,int r);

vector<vertex> BezierCurve(vector<vertex> points);

vector<vertex> HermiteCurve(vertex p1,vertex p4,vertex r1,vertex r4);

int main()
{   

//int gd=DETECT,gm;
//char *path="C:\\TC\\BGI";
initwindow(600,600);

{
	//makeCircle();
//usePixel();
//makeLine();
//makeLineWithAngle();
//makeLineWithDDA(20,30,330,160,BLUE);
//makeLineWithDDA(30,20,160,330,YELLOW);
//makeLineWithDDA(200,40,20,360,RED);
//makeLineWithDDA(40,200,360,20,GREEN);
//makeLineWithDDA(10,20,280,20,WHITE);
//makeLineWithDDA(20,20,20,320,255);

//makeLineWithBresenham(20,30,330,160,BLUE);
//makeLineWithBresenham(30,20,160,330,YELLOW);
//makeLineWithBresenham(200,40,20,360,RED);
//makeLineWithBresenham(40,200,360,20,GREEN);
//makeLineWithBresenham(10,20,280,20,WHITE);
//makeLineWithBresenham(20,20,20,320,255);

//int x1,y1,x2,y2;
//
//cout<<"\nEnter line 1 coordinates, x1 = ";
//cin>>x1;
//cout<<" y1 = ";
//cin>>y1;
//cout<<"\nEnter line 2 coordinates, x2 = ";
//cin>>x2;
//cout<<" y2 = ";
//cin>>y2;
//makeLineWithDDA(x1,y1,x2,y2,RED);
//makeLineWithBresenham(x1,y1,x2,y2,RED);

//makeCircleWithPixel(50);
//makeElipseWithPixel(100,50);

//line(30,50,400,50);
//line(30,200,400,200);
//line(30,50,30,200);
//line(400,50,400,200);

//setcolor(RED);
//line(10,10,300,500);
//cohenSutherlandClipAndDraw(10,10,300,500,30,400,50,200);
//line(20,30,330,160);
//cohenSutherlandClipAndDraw(20,30,330,160,30,400,50,200);
//line(30,20,160,330);
//cohenSutherlandClipAndDraw(30,20,160,330,30,400,50,200);
//line(200,40,20,360);
//cohenSutherlandClipAndDraw(200,40,20,360,30,400,50,200);
//line(40,200,360,20);
//cohenSutherlandClipAndDraw(40,200,360,20,30,400,50,200);
//line(10,20,280,20);
//cohenSutherlandClipAndDraw(10,20,280,20,30,400,50,200);
//line(20,20,20,320);
//cohenSutherlandClipAndDraw(20,20,20,320,30,400,50,200);
 
// clipBoundary cB={30,400,50,200};
// vertex temp[]={
////	{250,10},{300,10},
////	{300,10},{10,200},
////	{10,200},{20,100},
////	{20,100},{250,10}
//	
////	{300,10},{10,200},
////	{10,200},{420,100},
////	{420,100},{300,10}
//
////	{300,10},{10,200},
////	{10,200},{400,300},
////	{400,300},{420,100},
////	{420,100},{300,10}
//
////	{200,10},{10,100},
////	{10,100},{300,300},
////	{300,300},{320,100},
////	{320,100},{500,150},
////	{500,150},{200,10}
//	
////	{200,10},{10,100},
////	{10,100},{300,300},
////	{300,300},{320,100},
////	{320,100},{500,150},
////	{500,150},{400,10},
////	{400,10},{250,100},
////    {250,100},{200,10}
//};
// vector<vertex> inPolygon;
// 
// for(int i=0;i<sizeof(temp)/sizeof(temp[0]);i++){
// 	inPolygon.push_back(temp[i]);
// }

// line(300,10,10,200);
// line(10,200,20,100);
// line(20,100,250,10);
// line(250,10,300,10);

// line(300,10,10,200);
// line(10,200,420,100);
// line(420,100,300,10);

// line(300,10,10,200);
// line(10,200,400,300);
// line(400,300,420,100);
// line(420,100,300,10);
 
// line(200,10,10,100);
// line(10,100,300,300);
// line(300,300,320,100);
// line(320,100,500,150);
// line(500,150,200,10);
 
// line(200,10,10,100);
// line(10,100,300,300);
// line(300,300,320,100);
// line(320,100,500,150);
// line(500,150,400,10);
// line(400,10,250,100);
// line(250,100,200,10);
 
// PolygonClip(inPolygon,cB);
// PolygonFill(inPolygon,GREEN);
}

	//	2-D Transformations
{
		
//	int x,y,num=0;
//    
//    cout<<"\nEnter number of vertices of polygon:";
//    cin>>num;
//    
//    vector<vertex> poly;
// 
//	for(int i=0;i<num;i++){
//		cout<<"\nEnter the coordinates x0 and y0 for "<<i+1<<" vertex out of "<<num<<":";
//    	cin>>x>>y;
//	 	poly.push_back({x,y});
//	}
//	
//	vector<vertex> transformpoly;
//	
//	int choice;
//	while(1)
//	{
//		cleardevice();
//		setcolor(WHITE);
//		line(300,0,300,600);
//		line(0,300,600,300);
//	
//        cout<<"\n\n2d transformation:\n";
//        cout<<"1: Translation "<<endl;
//        cout<<"2: Scaling "<<endl;
//        cout<<"3: Rotation "<<endl;
//        cout<<"4: Shearing "<<endl;
//        cout<<"5: Rotate w. r. t. point. "<<endl;
//        cout<<"6: Reflect w. r. t. line. "<<endl;
//        cout<<"7: View Polygon "<<endl;
//        cout<<"8: Exit "<<endl;
//        cout<<" Enter Your Choice :=";
//        cin>>choice;
//        switch(choice)
//        {
//            case 1:
//                int tx,ty;
//				cout<<"\nEnter the translation for x and y axis:";
//				cin>>tx>>ty;
//				    
//				transformpoly=translatePolygon(poly,tx,ty);
//				viewPolygon(poly,RED);
//                viewPolygon(transformpoly,BLUE);
//                break;
//
//            case 2:
//                int sx,sy;
//				cout<<"\nEnter the scaling for x and y axis:";
//				cin>>sx>>sy;
//				    
//				transformpoly=scalePolygon(poly,sx,sy);
//				viewPolygon(poly,RED);
//                viewPolygon(transformpoly,BLUE);
//                break;
//
//            case 3: 
//                int theta;
//				cout<<"\nEnter the angle of rotation:";
//				cin>>theta;
//				    
//				transformpoly=rotatePolygon(poly,theta);
//				viewPolygon(poly,RED);
//                viewPolygon(transformpoly,BLUE);
//                break;
//
//            case 4:
//                int xSh,ySh;
//				cout<<"\nEnter the shearing in x and y axis:";
//				cin>>xSh>>ySh;
//				    
//				transformpoly=shearingPolygon(poly,xSh,ySh);
//				viewPolygon(poly,RED);
//                viewPolygon(transformpoly,BLUE);
//                break;
//                        
//            case 5:
//            	int px,py;
//				
//				cout<<"\nEnter the point w.r.t rotate:";
//    			cin>>px>>py;
//				
//				int ang;
//				cout<<"\nEnter the angle of rotation:";
//				cin>>ang;
//				    
//				transformpoly=rotatePolygon_wrt_point(poly,px,py,ang);
//				viewPolygon(poly,RED);
//                viewPolygon(transformpoly,BLUE);
//                break;
//            
//            case 6:
//            	float x0,y0,x1,y1;
//            	
//				cout<<"\nEnter the coordinates x0 and y0 for line:";
//			    cin>>x0>>y0;
//			    cout<<"\nEnter the coordinates x1 and y1 for line:";
//			    cin>>x1>>y1;
//			    
//			    line(x0+300,y0+300,x1+300,y1+300);
//				    
//				transformpoly=reflectPolygon(poly,x0,y0,x1,y1);
//				viewPolygon(poly,RED);
//                viewPolygon(transformpoly,BLUE);
//                break;
//                        
//            case 7:
//                viewPolygon(poly,RED);
//                break;
//            
//            case 8:
//                exit(0);
//
//            default:
//                cout<<" Press A Valid Key...!!! ";
//                break;
//        }
//        
//        cout<<"\nPress any key to exit viewing window\n\n";
//		getch();
//    }
    
}
	
	//	3-D Transformations
{
//	float x,y,z;
//	int num=0,edges=0;
//    
//    cout<<"\nEnter number of vertices of 3d mesh:";
//    cin>>num;
//    
//    cout<<"\nEnter number of edges in 3d mesh:";
//    cin>>edges;
//    
//    vector<vertex3d> mesh;
//    vector<edge3d> meshedges;
// 
//	for(int i=0;i<num;i++){
//		cout<<"\nEnter the coordinates x0 , y0 and z0 for "<<i+1<<" vertex out of "<<num<<":";
//    	cin>>x>>y>>z;
//    	vertex3d v={x,y,z};
//	 	mesh.push_back(v);
//	}
//	
//	for(int i=0;i<edges;i++){
//		int v1,v2;
//		cout<<"\nFor "<<i+1<<" edge:";
//		cout<<"\nEnter vertices numbers:";
//    	cin>>v1>>v2;
//    	edge3d e={v1,v2};
//	 	meshedges.push_back(e);
//	}
//	
//	setcolor(BROWN);
//	
//	vector<vertex3d> transformmesh;
//	
//	int choice;
//	while(1)
//	{
//		line(300,0,300,600);
//		line(0,300,600,300);
//	
//        cout<<"\n\n3d transformation:\n";
//        cout<<"1: Translation "<<endl;
//        cout<<"2: Scaling "<<endl;
//        cout<<"3: Rotation "<<endl;
//        cout<<"4: Shearing "<<endl;
//        cout<<"5: Rotate w. r. t. line. "<<endl;
//        cout<<"6: Reflect w. r. t. plane. "<<endl;
//        cout<<"7: Projection "<<endl;
//        cout<<"8: View the mesh "<<endl;
//        cout<<"9: Exit "<<endl;
//        cout<<" Enter Your Choice :=";
//        cin>>choice;
//        switch(choice)
//        {
//            case 1:
//                int tx,ty,tz;
//				cout<<"\nEnter the translation for x , y and z axis:";
//				cin>>tx>>ty>>tz;
//				    
//				transformmesh=translateMesh_3D(mesh,tx,ty,tz);
//                viewMesh(transformmesh,meshedges);
//                break;
//
//            case 2:
//                int sx,sy,sz;
//				cout<<"\nEnter the scaling for x , y and z axis:";
//				cin>>sx>>sy>>sz;
//				    
//				transformmesh=scaleMesh_3D(mesh,sx,sy,sz);
//                viewMesh(transformmesh,meshedges);
//                break;
//
//            case 3:
//                	
//                int ch;
//                cout<<"-=[ Rotation About ]=-"<<endl;
//			    cout<<"1:X-Axis "<<endl;
//			    cout<<"2:Y-Axis"<<endl;
//			    cout<<"3:Z-Axis "<<endl;
//			    cout<<"Enter Your Choice "<<endl;
//			    cin>>ch;
//			        
//			    TranformAboutAxis t;
//			    if(ch==1)	t=X;
//			    else if(ch==2)	t=Y;
//			    else if(ch==3)	t=Z;
//			    else{
//			        cout<<"\nInvalid axis entered\n";
//			        break;
//				}
//			        
//                int theta;
//				cout<<"\nEnter the angle of rotation:";
//				cin>>theta;
//				    
//				transformmesh=rotateMesh_3D(mesh,theta,t);
//                viewMesh(transformmesh,meshedges);
//                break;
//
//            case 4:
//                int xSh,ySh,zSh;
//				cout<<"\nEnter the shearing in x , y and z axis:";
//				cin>>xSh>>ySh>>zSh;
//				    
//				transformmesh=shearingMesh_3D(mesh,xSh,ySh,zSh);
//                viewMesh(transformmesh,meshedges);
//                break;
//                        
//            case 5:
//            	vertex3d p1;
//				vertex3d p2;
//            	
//				cout<<"\nEnter the vertex 1(x0,y0,z0) of line:";
//				cin>>p1.x>>p1.y>>p1.z;
//				
//				cout<<"\nEnter the vertex 2(x1,y1,z1) of line:";
//				cin>>p2.x>>p2.y>>p2.z;
//				
//				line(300+p1.x,300+p1.y,300+p2.x,300+p2.y);
//				
//				int ang;
//				cout<<"\nEnter the angle of rotation:";
//				cin>>ang;
//				    
//				transformmesh=rotateMesh_wrt_line_3D(mesh,p1,p2,ang);
//                viewMesh(transformmesh,meshedges);
//                break;
//            
//            case 6:
//            	vertex3d ver1,ver2,ver3;
//            	
//				cout<<"\nEnter the vertex 1(x0,y0,z0) of plane:";
//				cin>>ver1.x>>ver1.y>>ver1.z;
//				
//				cout<<"\nEnter the vertex 2(x1,y1,z1) of plane:";
//				cin>>ver2.x>>ver2.y>>ver2.z;
//				
//				cout<<"\nEnter the vertex 3(x2,y2,z2) of plane:";
//				cin>>ver3.x>>ver3.y>>ver3.z;
//				    
//				transformmesh=reflectMesh_wrt_plane_3D(mesh,ver1,ver2,ver3);
//                viewMesh(transformmesh,meshedges);
//                break;
//            
//            case 7:
//                float shift;
//				cout<<"\nEnter the shift in projections:";
//				cin>>shift;
//				    
//                viewProjectedMesh(mesh,meshedges,shift);
//                break;
//                
//            case 8:
//                viewMesh(mesh,meshedges);
//                break;
//                        
//            case 9:
//                exit(0);
//
//            default:
//                cout<<" Press A Valid Key...!!! ";
//                break;
//        }
//    }
}
  
{
//		int num=0,x,y;
//	    
//	    cout<<"\nEnter number of control points:";
//	    cin>>num;
//	    
//	    vector<vertex> cp,curvepoints;
//	    //setlinestyle(0, 0, 3);
//	 
//		for(int i=0;i<num;i++){
//			cout<<"\nEnter the coordinates x0 , y0 for "<<i+1<<" control point out of "<<num<<":";
//	    	cin>>x>>y;
//	    	vertex v;
//	    	v.x=x;
//	    	v.y=y;
//	    	cp.push_back(v);
//	    	putpixel(x,y,RED);
//		}  
//		curvepoints=BezierCurve(cp);
//		int n=curvepoints.size();
//		
//		for(int i=0;i<n;i++){
//			if(i+1!=n){
//				line(curvepoints.at(i).x,curvepoints.at(i).y,curvepoints.at(i+1).x,curvepoints.at(i+1).y);	
//			}
//		}
}
  	
	int num=4,x,y;
    
    vector<vertex> cp,curvepoints;
    //setlinestyle(0, 0, 3);
 
	for(int i=0;i<num;i++){
		cout<<"\nEnter the coordinates x0 , y0 for "<<i+1<<" control point out of "<<num<<":";
    	cin>>x>>y;
    	vertex v;
    	v.x=x;
    	v.y=y;
    	cp.push_back(v);
    	putpixel(x,y,RED);
	}  
	curvepoints=HermiteCurve(cp.at(0),cp.at(1),cp.at(2),cp.at(3));
	int n=curvepoints.size();
	
	for(int i=0;i<n;i++){
		if(i+1!=n){
			line(curvepoints.at(i).x,curvepoints.at(i).y,curvepoints.at(i+1).x,curvepoints.at(i+1).y);	
		}
	}
	getch();
 //closegraph();

}
