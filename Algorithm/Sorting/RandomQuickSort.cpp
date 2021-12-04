#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

void Swap(int &a,int &b)
{
	int temp=a;
		a=b;
		b=temp;
}
void RandomPivot(int a[],int l,int r)
{
	int i=rand()%(r-l)+l;
	Swap(a[i],a[l]);
}
int Partition(int a[],int l,int r)	//first pivot element
{
	int i=l,j=r;
	RandomPivot(a,l,r);
	int pivot=a[l];
	while(i<j)
	{
		while(pivot>=a[++i] );
		while(pivot<a[--j] );
		if(i<j)
		{
			Swap(a[i],a[j]);
		}
	}
	Swap(a[l],a[j]);
	return j;
}

void Quick_Sort_1(int a[],int l,int r)
{
	if(l<r)
	{
		int j=Partition(a,l,r);
		Quick_Sort_1(a,l,j);
		Quick_Sort_1(a,j+1,r);
	}
}

int main()
{
	int *arr,n=0;
	
	srand(time(0));
	cout<<"\nEnter No. of elements:";
	cin>>n;
	arr=new int[n];
	cout<<"\nElements are:";
	for(int i=0;i<n;i++) 
	{
		arr[i]=rand()%n +1;
		cout<<arr[i]<<" ";
	}

	Quick_Sort_1(arr,0,n);
		
	cout<<"\n\nSorted array is:";
	for(int i=0;i<n;i++) 
		cout<<arr[i]<<" ";
}
