#include<iostream>
#include<queue>

using namespace std;

bool Check(int a,int A[],int n,queue <int> q);

int main(){
	int *A;		//array of visited verteces
	int **AdacencyMat;
	queue <int> unvisit; 
	
	int n;
	cout<<"\nEnter number of verteces:";
	cin>>n;
	A=new int[n];			//Fill up all vertices with -1
	for(int i=0;i<n;i++)
		A[i]=-1;
	
	int m;
	cout<<"\nEnter number of Edges:";
	cin>>m;
	
	AdacencyMat=new int*[n];
	for(int i=0;i<n;i++)
		AdacencyMat[i]=new int[n];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			AdacencyMat[i][j]=0;
		}
	}
		
	int temp=0;
	while(temp!=m){
		int a,b;
		cout<<"\n\nSource vertex[1 to "<<n<<"]:";
		cin>>a;
		cout<<"\nDestination vertex[1 to "<<n<<"]:";
		cin>>b;
		AdacencyMat[a-1][b-1]=1;
		AdacencyMat[b-1][a-1]=1;
		temp++;
	}	
	
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			cout<<AdacencyMat[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<"\nVisited Verteces are:";
	int start;
	unvisit.push(0);
	for(int i=0;i<n;i++)
	{
		start=unvisit.front();
		A[i]=start;
		unvisit.pop();
		cout<<start+1<<" ";
		for(int j=0;j<n;j++)
		{
			int a=AdacencyMat[start][j];
			if(a && Check(j,A,n,unvisit))
				unvisit.push(j);	
		}	
	}
}
bool Check(int a,int A[],int n,queue<int> q){
	int i=0;
	while(A[i]!=-1 && i!=n){		//visited or not
		if(a==A[i++])
			return false;
	}
	queue <int> g = q; 
    while (!g.empty()) 				//in unvisited already or not
    { 
        if(a==g.front())
			 return false;
        g.pop(); 
    } 
	return true;
}
