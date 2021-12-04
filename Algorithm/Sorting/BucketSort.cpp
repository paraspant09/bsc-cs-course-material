#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>

using namespace std;

void Bucket_Sort(float arr[],int n)
{
	vector<float> b[n];
	
	for(int i=0;i<n;i++)
	{
		int index=n*arr[i];
		b[index].push_back(arr[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		sort(b[i].begin(),b[i].end());
	}
	
	int k=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<b[i].size();j++)
		{
			arr[k++]=b[i][j];
		}
	}
}

int main()
{
	int n=0;
	cout<<"\nEnter No. of elements:";
	cin>>n;
	
	float *arr;	
	arr=new float[n];
	
	cout<<"\n Enter Elements(Ex-0.1234 0.3434 0.565 0.656 0.665 0.897):";
	for(int i=0;i<n;i++) 
	{
		cin>>arr[i];
	}
	Bucket_Sort(arr,n);
	
	cout<<"\n\nSorted array is:";
	for(int i=0;i<n;i++) 
		cout<<arr[i]<<" ";
}
