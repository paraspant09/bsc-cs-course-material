#include<iostream>
using namespace std;
void Print_LCS(char B[],char **b,int i,int j)
{
	if(i>=0 && j>=0)
	{
		char ch=b[i][j];
		if(ch == 'd')
		{
			Print_LCS(B,b,i-1,j-1);
			cout<<B[j]<<" ";
		}
		else if(ch == 'l')
			Print_LCS(B,b,i,j-1);			
		else if(ch == 'u')
			Print_LCS(B,b,i-1,j);
	}
}

int LCS(char A[],char B[],int m,int n){
	int C[m+1][n+1];	//integer maximum height array
	char b[m][n];	//char direction array 
	
	for(int i=0;i<=n;i++)
		C[0][i]=0;
		
	for(int j=1;j<=m;j++)
		C[j][0]=0;
		
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(A[i-1] == B[j-1])
			{
				C[i][j]=C[i-1][j-1]+1;
				b[i-1][j-1]='d';
			}
			else if(C[i-1][j] > C[i][j-1])
			{
				C[i][j]=C[i-1][j];
				b[i-1][j-1]='u';
			}
			else
			{
				C[i][j]=C[i][j-1];
				b[i-1][j-1]='l';
			}
		}
	}
	cout<<endl;
	
	char **array;
	array = new char *[n];
	for(int i = 0; i <m; i++)
	   array[i] = new char[n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			array[i][j]=b[i][j];
			
/*	cout<<"\nLCS Array is:\n    ";
	for(int i=0;i<m;i++)
		cout<<B[i]<<" ";
	cout<<"\n";
	for(int i=0;i<=m;i++)
	{
		if(i==0)
			cout<<"  ";
		else
			cout<<A[i-1]<<" ";
		for(int j=0;j<=n;j++)
			cout<<C[i][j]<<" ";
		cout<<endl;
	}

	cout<<"\nLCS Character Array is:\n";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout<<array[i][j]<<" ";
		cout<<endl;
	}*/
			
	cout<<"\n\nMaximum length lcs string is:";
	Print_LCS(B,array,m-1,n-1);
	
	return C[m][n];
}


int main(){
	char *A;
	int n1;
	char *B;
	int n2;
	
	cout<<"\nEnter number of elements in A:";
	cin>>n1;
	A=new char[n1];
	cout<<"\nEnter A:";
	for(int i=0;i<n1;++i)
	{
		cin>>A[i];
	}
	
	cout<<"\nEnter number of elements in B:";
	cin>>n2;
	B=new char[n2];
	cout<<"\nEnter B:";
	for(int i=0;i<n2;++i)
	{
		cin>>B[i];
	}
	
	cout<<"\n\nMaximum length of lcs string is:"<<LCS(A,B,n1,n2);
}
