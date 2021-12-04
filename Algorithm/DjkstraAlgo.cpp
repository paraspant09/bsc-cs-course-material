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
	int **A;
	int **M;
	int n;
	cout<<"\nEnter number of verteces:";
	cin>>n;
	A=new int*[2];		
	for(int i=0;i<2;i++)
		A[i]=new int[n+1];
	A[0][0]=0;
	for(int i=1;i<=n;i++)
		A[0][i]=2147483647;
	A[1][0]=-1;
	for(int i=1;i<=n;i++)
		A[1][i]=0;
		
	int m;
	cout<<"\nEnter number of Edges:";
	cin>>m;
	M=new int*[m];
	for(int i=0;i<m;i++)
		M[i]=new int[4];
	/*M[Source,Destintion,Weight,EdgeConsidered already or not(0/-1)]*/
	/*A[Weights due to adjacent vertex][allverteces]
		[Vertex which affected that weight change(-1,0,vertex no.)][allverteces] -1 means vertex is visited
		0 means not visited as well as its weight not changed no adjacent vertex is visited ,vertex no. means
		not visited but adjacent vertex is visited and changed its weight.*/
	int temp=0;
	while(temp!=m){
		cout<<"\n\nSource vertex[1 to "<<n<<"]:";
		cin>>M[temp][0];
		cout<<"\nDestination vertex[1 to "<<n<<"]:";
		cin>>M[temp][1];
		cout<<"\nWeight of edge:";
		cin>>M[temp++][2];
	}	
	
	for(int i=0;i<m;i++)
		M[i][3]=0;
	
	cout<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<3;j++)
			cout<<M[i][j]<<" ";
		cout<<endl;
	}
	int weight=0;
	int start=1;
	int min_value,min_index;
	cout<<"\nMinimum Spanning tree:{";
	A[0][start]=0;
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){		//Change weight of adjacent vertices in A[0] 
			if(M[j][3]==0){			//for those edges which are not taken
			/*If edge contains start vertex and previous weight of adjacent vertex > new edge weight  */
				if(start == M[j][0] && A[0][M[j][1]] > A[0][start]+M[j][2]){
					A[0][M[j][1]] =A[0][start]+ M[j][2];		//Add new weight to adjacent vertex of that edge
					A[1][M[j][1]] = start;			//Add the vertex no. (start vertex) which affected the weight
					M[j][3]=-1;						//Do not consider this edge again
				}
				if(start == M[j][1] && A[0][M[j][0]] > A[0][start]+M[j][2]){
					A[0][M[j][0]] =A[0][start]+ M[j][2];
					A[1][M[j][0]] = start;
					M[j][3]=-1;
				}
			}
		}
		A[1][start]=-1;
		min_value=2147483647;
		min_index=-1;
		for(int j=1;j<=n;j++){		//Find minimum edge weight of not visited but changed weights.
			if(A[1][j]!=-1){		//not visited
				if(min_value > A[0][j])
				{
					min_value=A[0][j];
					min_index=j;
				}
			}
		}
		cout<<"("<<A[1][min_index]<<","<<min_index<<") ,";		//(Reason of weight change,whose weight change)
		weight+=A[0][min_index];
		start=min_index;
//		cout<<endl;
//		for(int i=1;i<=n;i++)	cout<<A[0][i]<<" ";
//		cout<<endl;
//		for(int i=1;i<=n;i++)	cout<<A[1][i]<<" ";
//		cout<<endl;
	}
	cout<<"}\n";
//	cout<<endl;
//	for(int i=1;i<=n;i++)	cout<<A[0][i]<<" ";
	cout<<"\nMinimum Spanning tree weight:"<<weight;
}
