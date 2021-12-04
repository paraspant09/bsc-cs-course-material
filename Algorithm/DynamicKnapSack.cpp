#include<iostream>
using namespace std;
int KnapSack(int P[],int Wt[],int n,int Max){
	int k[n+1][Max+1];
	
	for(int i=0;i<=n;i++)
	{
		for(int w=0;w<=Max;w++)		//w is current weight constraint
		{
			if(i==0 || w==0)
				k[i][w]=0;
			else if(w < Wt[i-1])	//Wt[i-1] same below reason becoz part starts when i=1
				k[i][w]=k[i-1][w];
			else				// this part starts when i=1
			{
				int AbsenceCost=k[i-1][w];
				int PresenceCost=P[i-1] + k[i-1][w-Wt[i-1]];		//P[i-1] and Wt[i-1] not P[i] and Wt[i] becoz this starts at i=1 where P's index must be 0
				if(AbsenceCost > PresenceCost)
					k[i][w]=AbsenceCost;
				else
					k[i][w]=PresenceCost;
			}
		}
	}
/*	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=Max;j++)
			cout<<k[i][j]<<" ";
		cout<<endl;
	}	*/
	
	//Show the items choosen
	int a=k[n][Max];
	int i=0;
	int index=n;
	int weight=Max;
	int Items[n];
	for(int i=0;i<n;i++)
		Items[i]=0;
		
	while(a!=0){
		int b=k[index-1][weight];
//		cout<<a;
		if(a!=b)
		{
			Items[i++]=index;
			weight-= Wt[index-1];
			a=k[--index][weight];
		}
		else
			index--;
	}
	
	cout<<"\nItems are:";
	for(int i=0;i<n;i++)
	{
		if(Items[i]!=0)
			cout<<Items[i]<<" ";
		else 
			break;
	}
		
	return k[n][Max];
}
int main(){
	int *P;		//profits
	int *Wt;	//weights
	int n;		//number of items
	int W;		//Maximum Weight of bag
	
	cout<<"\nEnter number of Items:";
	cin>>n;
	
	P=new int[n];
	cout<<"\nEnter their profits:";
	for(int i=0;i<n;++i)
	{
		cin>>P[i];
	}
	
	Wt=new int[n];
	cout<<"\nEnter their weights:";
	for(int i=0;i<n;++i)
	{
		cin>>Wt[i];
	}
	
	cout<<"\nEnter Maximim weight of bag:";
	cin>>W;
	
	cout<<"\n\nMaximum Profit is:"<<KnapSack(P,Wt,n,W);
}
