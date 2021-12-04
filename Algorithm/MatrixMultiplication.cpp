#include<iostream>
using namespace std;
int main(){
	int n;
	int *d;
	int j,q;
	int **M,**S;
	
	cout<<"\nEnter number of arrays:";
	cin>>n;
	
	M=new int*[n];
	S=new int*[n];
	d=new int[n+1];
	
	for(int i=0;i<n;++i)
	{
		M[i]=new int[n];
		S[i]=new int[n];
	}
	cout<<"\nEnter "<<n+1<<" dimensions of the arrays:";
	for(int i=0;i<n+1;++i)
	{
		cin>>d[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		M[i-1][i-1]=0;
		S[i-1][i-1]=0;
	}
	//everywhere same only places for indices of matrices will be -1.  
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=(n-(l-1));i++)		
		{
			j=i+l-1;
			M[i-1][j-1]=32767;
			for(int k=i;k<=j-1;k++)
			{
				q=M[i-1][k-1]+M[k][j-1]+d[i-1]*d[k]*d[j];	
				
				if(M[i-1][j-1] > q)
				{
					M[i-1][j-1]=q;
					S[i-1][j-1]=k;
				}
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
	1		cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			cout<<S[i][j]<<" ";
		}
		cout<<endl;
	}
}
