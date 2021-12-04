#include<iostream>
using namespace std;
int LCS(int i,int j,char A[],char B[],int n1,int n2){
	if(i==n1 || j==n2)
		return 0;
	else if(A[i]==B[j])
		return 1+LCS(i+1,j+1,A,B,n1,n2);
	else
		return max(LCS(i+1,j,A,B,n1,n2),LCS(i,j+1,A,B,n1,n2));
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

//	int max_ct;
	
//	max_ct=LCS(0,0,A,B,n1,n2);
	
	cout<<endl<<LCS(0,0,A,B,n1,n2);
}
