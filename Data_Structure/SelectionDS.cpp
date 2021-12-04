#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int temp=a;
    a=b;
    b=temp;
}
int main()
{   int n,*arr;
	cout<<"\tEnter the size of array: ";
	cin>>n;
	arr=new int[n];
	cout<<"\n\tEnter the array: ";
		for(int i=0;i<n;i++)
	{
	 cin>>arr[i];
	}

	int i, j, min, count=0;
    for (i=0;i<n-1;i++)  
    {  
    
        min=i;  
        for(j=i+1;j<n;j++)  
        if (++count&&(arr[j]<arr[min]))  
            min=j;  
        swap(arr[min], arr[i]);  
    }  
    cout<<"The sorted array is: "<<endl;
    
		for(int i=0;i<n;i++)
	{
		
	 cout<<arr[i];
	}
	cout<<"\nNumber of comparisons are: "<<count<<endl;

}
