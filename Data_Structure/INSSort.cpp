#include<iostream>
using namespace std;

void print(int *arr,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<< ' ' << arr[i];
	}
	
}

void insertion_sort(int *arr,int size)
{
	int key,i,j,a,c,A=0,C=0;
	bool f;
	for(i=1;i<size;i++)
	{
		f=false;
		a=0;
		c=0;
		cout<<"\nPass"<<i<<"\n";
		
		key=arr[i];
		j=i-1;
		
		cout << endl;
		print(arr,size);
		cout<<"-->";
		while(j>=0 && ++c && arr [j]>key)
		{   
			f=true;
			arr[j+1]=arr[j];
			j=j-1;
			a++;
    	}
		arr[j+1]=key;
		print(arr,size);
		cout<<"\n\nNumber of Shifts= "<<a;
		A+=a;
		cout<<"\nNumber of Comparisons= "<<c;
		C+=c;
	}
	cout<<"\nTotal Number of Shifts= "<<A;
    cout<<"\nTotal Number of Comparisons= "<<C;
}

int main()
{
	int *arr,size;
	cout<<"Enter the number of elements in the array:";
	cin>>size;
	arr=new int[size];
	cout << "\nEnter the elements : ";
	for (int i=0; i<size; i++)
  		cin>>arr[i];
  	insertion_sort(arr, size);	
	return 0;
}
