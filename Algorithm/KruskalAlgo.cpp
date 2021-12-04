#include<iostream>
using namespace std;
int find_Set(int n,int A[]){
	if(n==A[n])		//he is parent of itself
		return n;
	else
		find_Set(A[n],A);
}
void Merge_Set(int v1,int v2,int A[]){
	A[v1]=A[v2];	//their parents were pointing to themselves make one pointing to other
}
int main(){
	int *A;
	int **M;
	int n;
	cout<<"\nEnter number of verteces:";
	cin>>n;
	A=new int[n+1];			//Fill up all vertices with themselves value as they are parent of their own at start
	for(int i=0;i<=n;i++)
		A[i]=i;
	
	int m;
	cout<<"\nEnter number of Edges:";
	cin>>m;
	M=new int*[m];
	for(int i=0;i<m;i++)
		M[i]=new int[3];
	
	int temp=0;
	while(temp!=m){
		cout<<"\n\nSource vertex[1 to "<<n<<"]:";
		cin>>M[temp][0];
		cout<<"\nDestination vertex[1 to "<<n<<"]:";
		cin>>M[temp][1];
		cout<<"\nWeight of edge:";
		cin>>M[temp++][2];
	}	
	
	for(int i=0;i<m-1;i++)
		for(int j=0;j<m-1-i;j++)
			if(M[j][2] > M[j+1][2]){
				swap(M[j][0],M[j+1][0]);
				swap(M[j][1],M[j+1][1]);
				swap(M[j][2],M[j+1][2]);
			}
	
	cout<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<3;j++)
			cout<<M[i][j]<<" ";
		cout<<endl;
	}
	int weight=0;
	int temp2=0;
	cout<<"\nMinimum Spanning tree:{";
	for(int i=0;i<m;i++){
		int v1=M[i][0];
		int v2=M[i][1];
		
		int parent_v1=find_Set(v1,A);
		int parent_v2=find_Set(v2,A);
		if( parent_v1 != parent_v2)
		{
			weight+=M[i][2];
			cout<<"("<<v1<<","<<v2<<") , ";
			temp2++;
			Merge_Set(parent_v1,parent_v2,A);
		}
		if(temp2 == n-1)	break;
	}
	cout<<"}\n";
	for(int i=0;i<=n;i++)	cout<<A[i]<<" ";
	cout<<"\nMinimum Spanning tree weight:"<<weight;
}
