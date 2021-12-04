#include<iostream>
#include<conio.h>
using namespace std;
 
 int partition(int a[], int low,int high)
 {
 	int pivot=a[high];
 	int i=low-1;
 	for(int j=low;j<high;j++)
 	{
 		if(a[j]<=pivot)
 		{
 			i++;
 			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[high]);
	return i+1;
 }
 
 void quicksort(int a[],int low,int high)
 {
 	if(low<high)
	 {
 		int pi=partition(a,low,high);
		 quicksort(a,low,pi-1);
		 quicksort(a,pi+1,high);	
	 }
 }
 
 int main()
{
	int size;
	cout<<"size";
	cin>>size;
	int arr[size];
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	cout<<"\n";
	
	quicksort(arr,0,size-1);
	
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<"  ";
	}
	getch();
}
