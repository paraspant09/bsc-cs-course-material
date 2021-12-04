#include<iostream>
using namespace std;
 
 int partition(int a[], int low,int high)
 {
	int pivot=a[low];
	int i=low;
	int j=high;
	while(i<j)
	{
		do{
			i++;
		}while(a[i]<=pivot);
		
		while(a[j]>pivot){
			j--;
		}
		
		if(i<j)
			swap(a[i],a[j]);
	}
	swap(a[low],a[j]);
	return j;
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
	cout<<"\nSize:";
	cin>>size;
	int arr[size];
	cout<<"\nEnter the array:";
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
}
