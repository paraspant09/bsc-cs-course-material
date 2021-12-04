#include<iostream>
#include<math.h>
#include<vector> 
#include<graphics.h>

using namespace std;

int shift3d=300;

enum TranformAboutAxis { X , Y , Z };

struct vertex3d{
	float x;
	float y;
	float z;
};

struct edge3d{
	int ver1;
	int ver2;
};

float* multVectorNMatrix_3D(float a[4],float b[4][4]){
	
	float mult[4]={0};
	
	for(int i = 0; i < 4; ++i)
    	mult[i] += a[0] * b[0][i] + a[1] * b[1][i] + a[2] * b[2][i] + a[3] * b[3][i];
    
    return mult;
}

float* translate_3D(float x0,float y0,float z0,float tx,float ty,float tz){
	float newM[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{tx,ty,tz,1}};
	
	float point[4]={x0,y0,z0,1};

	return multVectorNMatrix_3D(point,newM);
}

float* scale_3D(float x0,float y0,float z0,float sx,float sy,float sz){
	float newM[4][4]={{sx,0,0,0},{0,sy,0,0},{0,0,sz,0},{0,0,0,1}};
	
	float point[4]={x0,y0,z0,1};

	return multVectorNMatrix_3D(point,newM);
}

float* rotate_3D(float x0,float y0,float z0,float theta,TranformAboutAxis axis){
	//convert theta to radian
	theta*=(3.14/180);
	
	float newM[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
	
	switch (axis)
    {
	    case X: newM[1][1]=cos(theta); newM[1][2]=sin(theta); newM[2][1]=-sin(theta); newM[2][2]=cos(theta);
	        break;
	    case Y: newM[0][0]=cos(theta); newM[0][2]=-sin(theta); newM[2][0]=sin(theta); newM[2][2]=cos(theta);
	        break;
	    case Z: newM[0][0]=cos(theta); newM[0][1]=sin(theta); newM[1][0]=-sin(theta); newM[1][1]=cos(theta);
	        break;
	    default:
	        cout << "\nInvalid Axis tranformation!!";
    }
	
	float point[4]={x0,y0,z0,1};

	return multVectorNMatrix_3D(point,newM);
}

float* shearing_3D(float x0,float y0,float z0,float xSh,float ySh,float zSh){
	float newM[4][4]={{1,ySh,zSh,0},{xSh,1,zSh,0},{xSh,ySh,1,0},{0,0,0,1}};
	
	float point[4]={x0,y0,z0,1};

	return multVectorNMatrix_3D(point,newM);
}

float* rotate_wrt_line_3D(float x0,float y0,float z0,vertex3d p1,vertex3d p2,float theta){
	float* trans=translate_3D(x0,y0,z0,-p1.x,-p1.y,-p1.z);
	
	float thetax=acos( p2.z / sqrt( p2.y*p2.y + p2.z*p2.z ) )*(180/3.14);
	
	float* rotx=rotate_3D(trans[0],trans[1],trans[2],thetax,X);
	
	float thetay=acos( sqrt( p2.y*p2.y + p2.z*p2.z ) / sqrt( p2.x*p2.x + p2.y*p2.y + p2.z*p2.z ) )*(180/3.14);
	
	float* roty=rotate_3D(rotx[0],rotx[1],rotx[2],-thetay,Y);
	
	float* actual_rot=rotate_3D(roty[0],roty[1],roty[2],theta,Z);
	
	float* invroty=rotate_3D(actual_rot[0],actual_rot[1],actual_rot[2],thetay,Y);
	
	float* invrotx=rotate_3D(invroty[0],invroty[1],invroty[2],-thetax,X);
	
	float* invtrans=translate_3D(invrotx[0],invrotx[1],invrotx[2],p1.x,p1.y,p1.z);

	return invtrans;
}

float* reflect_wrt_plane_3D(float x0,float y0,float z0,vertex3d p1,vertex3d p2,vertex3d p3){
	
	vertex3d a={ (p3.x - p1.x) , (p3.y - p1.y) , (p3.z - p1.z) };
	
	vertex3d b={ (p2.x - p1.x) , (p2.y - p1.y) , (p2.z - p1.z) };
	
	vertex3d cross ={ (a.y*b.z - a.z*b.y) , -(a.x*b.z - a.z*b.x) , (a.x*b.y - a.y*b.x) };
	
	float mag= sqrt(cross.x * cross.x + cross.y * cross.y + cross.z * cross.z);
	
	vertex3d normal= { cross.x / mag , cross.y / mag , cross.z / mag};
	
	float d= sqrt( normal.y * normal.y + normal.z * normal.z);
	
	float alpha = acos( normal.z / d) * (180/3.14);
	
	float beta = acos( d ) * (180/3.14);
	
	float* trans=translate_3D(x0,y0,z0,-p3.x,-p3.y,-p3.z);
	
	float* rotx=rotate_3D(trans[0],trans[1],trans[2],alpha,X);
	
	float* roty=rotate_3D(rotx[0],rotx[1],rotx[2],-beta,Y);
	
	float* reflect=scale_3D(roty[0],roty[1],roty[2],1,1,-1);
	
	float* invroty=rotate_3D(reflect[0],reflect[1],reflect[2],beta,Y);
	
	float* invrotx=rotate_3D(invroty[0],invroty[1],invroty[2],-alpha,X);
	
	float* invtrans=translate_3D(invrotx[0],invrotx[1],invrotx[2],p3.x,p3.y,p3.z);

	return invtrans;
}

float* project_3D(float x0,float y0,float z0,float p,float q,float r){
	float newM[4][4]={{1,0,0,p},{0,1,0,q},{0,0,1,r},{0,0,0,1}};
	
	float point[4]={x0,y0,z0,1};

	float* newpoint=multVectorNMatrix_3D(point,newM);
	
	if(newpoint[3]!=1 && newpoint[3]!=0){
		newpoint[0] /= newpoint[3];
		newpoint[1] /= newpoint[3];
		newpoint[2] /= newpoint[3];
	}
	
	return newpoint;
}

vector<vertex3d> translateMesh_3D(vector<vertex3d> mesh,float tx,float ty,float tz){
	vector<vertex3d> newmesh;
	
	for(int i=0;i<mesh.size();i++){
		float* translated=translate_3D(mesh.at(i).x,mesh.at(i).y,mesh.at(i).z,tx,ty,tz);
		vertex3d v;
		v.x=translated[0];
		v.y=translated[1];
		v.z=translated[2];
		newmesh.push_back(v);
	}
	return newmesh;
}

vector<vertex3d> scaleMesh_3D(vector<vertex3d> mesh,float sx,float sy,float sz){
	vector<vertex3d> newmesh;
	
	for(int i=0;i<mesh.size();i++){
		float* scaled=scale_3D(mesh.at(i).x,mesh.at(i).y,mesh.at(i).z,sx,sy,sz);
		vertex3d v;
		v.x=scaled[0];
		v.y=scaled[1];
		v.z=scaled[2];
		newmesh.push_back(v);
	}
	return newmesh;
}

vector<vertex3d> rotateMesh_3D(vector<vertex3d> mesh,float theta,TranformAboutAxis axis){
	vector<vertex3d> newmesh;
	
	for(int i=0;i<mesh.size();i++){
		float* rotated=rotate_3D(mesh.at(i).x,mesh.at(i).y,mesh.at(i).z,theta,axis);
		vertex3d v;
		v.x=rotated[0];
		v.y=rotated[1];
		v.z=rotated[2];
		newmesh.push_back(v);
	}
	return newmesh;
}

vector<vertex3d> shearingMesh_3D(vector<vertex3d> mesh,float xSh,float ySh,float zSh){
	vector<vertex3d> newmesh;
	
	for(int i=0;i<mesh.size();i++){
		float* sheared=shearing_3D(mesh.at(i).x,mesh.at(i).y,mesh.at(i).z,xSh,ySh,zSh);
		vertex3d v;
		v.x=sheared[0];
		v.y=sheared[1];
		v.z=sheared[2];
		newmesh.push_back(v);
	}
	return newmesh;
}

vector<vertex3d> rotateMesh_wrt_line_3D(vector<vertex3d> mesh,vertex3d p1,vertex3d p2,float theta){
	vector<vertex3d> newmesh;
	cout<<"\nOutput:\n";
	for(int i=0;i<mesh.size();i++){
		float* rotated=rotate_wrt_line_3D(mesh.at(i).x,mesh.at(i).y,mesh.at(i).z,p1,p2,theta);
		vertex3d v;
		v.x=rotated[0];
		v.y=rotated[1];
		v.z=rotated[2];
		cout<<"\n"<<v.x<<" "<<v.y<<" "<<v.z;
		newmesh.push_back(v);
	}
	return newmesh;
}

vector<vertex3d> reflectMesh_wrt_plane_3D(vector<vertex3d> mesh,vertex3d p1,vertex3d p2,vertex3d p3){
	vector<vertex3d> newmesh;
	cout<<"\nOutput:\n";
	for(int i=0;i<mesh.size();i++){
		float* reflected=reflect_wrt_plane_3D(mesh.at(i).x,mesh.at(i).y,mesh.at(i).z,p1,p2,p3);
		vertex3d v;
		v.x=reflected[0];
		v.y=reflected[1];
		v.z=reflected[2];
		cout<<"\n"<<v.x<<" "<<v.y<<" "<<v.z;
		newmesh.push_back(v);
	}
	return newmesh;
}

vector<vertex3d> projectMesh_3D(vector<vertex3d> mesh,float p,float q,float r){
	vector<vertex3d> newmesh;
	
	for(int i=0;i<mesh.size();i++){
		float* projected=project_3D(mesh.at(i).x,mesh.at(i).y,mesh.at(i).z,p,q,r);
		vertex3d v;
		v.x=projected[0];
		v.y=projected[1];
		v.z=projected[2];
		newmesh.push_back(v);
	}
	return newmesh;
}

vertex3d vertexshift_3D(vertex3d v){
	vertex3d newv={v.x+shift3d , v.y+shift3d , v.z+shift3d};
	return newv;
}

void viewMesh(vector<vertex3d> mesh,vector<edge3d> meshedges){
	vector<vertex3d> rotatemesh,new_mesh=mesh;
	
	cout<<"\n\nNow you can play around with mesh by rotating it about different axis.\n";
	cout<<"\nPress x(for x axis rotation),y(for y axis rotation),z(for z axis rotation)\n";
	cout<<"\nPress anything else to get out of viewing the mesh.\n";
	
	for(int i=0;i<meshedges.size();i++){
		edge3d e=meshedges.at(i);
		vertex3d v=vertexshift_3D(mesh.at(e.ver1-1));
		vertex3d s=vertexshift_3D(mesh.at(e.ver2-1));
//		cout<<v.x<<" "<<v.y<<" ---> "<<s.x<<" "<<s.y<<"\n";
		line(v.x,v.y,s.x,s.y);
	}
	
	int c = 0;
	while(1)
    {
        c = 0;
        setlinestyle(0, 0, 3);
        
        switch((c=getch())) {
	        case 'x':
	        	cleardevice();
				rotatemesh=rotateMesh_3D(new_mesh,10,X);
	            cout << endl << "X" << endl;
	            break;
	        case 'y':
	        	cleardevice();
	        	rotatemesh=rotateMesh_3D(new_mesh,10,Y);
	            cout << endl << "Y" << endl;
	            break;
	        case 'z':
	        	cleardevice();
	        	rotatemesh=rotateMesh_3D(new_mesh,10,Z);
	            cout << endl << "Z" << endl;
	            break;
	        default:
	            cout << endl << "null" << endl;  // not arrow
	            cleardevice();
	            return;
        }
        
        for(int i=0;i<meshedges.size();i++){
			edge3d e=meshedges.at(i);
			vertex3d v=vertexshift_3D(rotatemesh.at(e.ver1-1));
			vertex3d s=vertexshift_3D(rotatemesh.at(e.ver2-1));
//			cout<<v.x<<" "<<v.y<<" ---> "<<s.x<<" "<<s.y<<"\n";
			line(v.x,v.y,s.x,s.y);
		}
        
        new_mesh=rotatemesh;
    }
}

void viewProjectedMesh(vector<vertex3d> mesh,vector<edge3d> meshedges,float shift){
	vector<vertex3d> projectmesh;
	
	cout<<"\n\nNow you can play around with mesh by projecting it with different r values.\n";
	cout<<"\nPress p(for increasing p value by "<<shift<<" )";
	cout<<"\nPress q(for decreasing q value by "<<shift<<" )";
	cout<<"\nPress r(for decreasing r value by "<<shift<<" )";
	cout<<"\nPress anything else to get out of viewing the mesh.\n";
	
	for(int i=0;i<meshedges.size();i++){
		edge3d e=meshedges.at(i);
		vertex3d v=vertexshift_3D(mesh.at(e.ver1-1));
		vertex3d s=vertexshift_3D(mesh.at(e.ver2-1));
//		cout<<v.x<<" "<<v.y<<" ---> "<<s.x<<" "<<s.y<<"\n";
		line(v.x,v.y,s.x,s.y);
	}
	
	int c = 0;
	float p=0,q=0,r=0;
	while(1)
    {
        c = 0;
        setlinestyle(0, 0, 3);
        
        switch((c=getch())) {
	        case 'p':
	        	cleardevice();
	        	p+=shift;
	            cout << endl << "increased p by "<< shift << endl;
	            break;
	        case 'q':
	        	cleardevice();
	        	q+=shift;
	            cout << endl << "increased q by "<< shift << endl;
	            break;
	        case 'r':
	        	cleardevice();
	        	r+=shift;
	            cout << endl << "increased r by "<< shift << endl;
	            break;
	        default:
	            cout << endl << "null" << endl;  // not arrow
	            cleardevice();
	            return;
        }
        
        projectmesh=projectMesh_3D(mesh,p,q,r);
        cout << endl << "new (p,q,r) : "<< p << " " << q << " " << r << endl;
        
        for(int i=0;i<meshedges.size();i++){
			edge3d e=meshedges.at(i);
			vertex3d v=vertexshift_3D(projectmesh.at(e.ver1-1));
			vertex3d s=vertexshift_3D(projectmesh.at(e.ver2-1));
//			cout<<v.x<<" "<<v.y<<" ---> "<<s.x<<" "<<s.y<<"\n";
			line(v.x,v.y,s.x,s.y);
		}
    }
}
