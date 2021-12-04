#include<iostream>
using namespace std;
class Sorting
{
int *arr,n,swap,comp;
public:Sorting()
      {
      	cout<<"Enter no. of elements to be sorted\n";
      	cin>>n;
       arr=new int[n];	
       swap=comp=0;
      }
      void InputArray()
      {
      	cout<<"Enter the unsorted array\n";
      	for(int i=0;i<n;i++)
		  cin>>arr[i];
	  }
	  void OutputArray()
	  {
	  	cout<<"Sorted Array :";
	  	for(int i=0;i<n;i++)
		  cout<<arr[i]<<" ";
	  }
    void SS()
   {
   	 int i,j=0,min_index=0,temp=0;
	 for(i=0;i<n-1;i++)
	 {
	 	min_index=i;
	   for(j=i+1;j<n;j++)                  //Array will be started sorting from begining after each iteration
	   {
	    if(arr[j]<arr[min_index])           //Find min. index
	    {
			min_index=j;
	    }
	    comp++;
	   }
	   if(i!=min_index)
	   { int temp=arr[i];                  //Swapping with minimum value leaving sorted element from consideration
	     arr[i]=arr[min_index];
	     arr[min_index]=temp;
	     swap++;
       }
     }
    }
    void Testing()
    {
    	cout<<"\nNo. of comparisons :"<<comp;  //will be same for same no. of elements
    	cout<<"\nNo. of swaps :"<<swap;
	}
};
int main()
{
	Sorting ob;
	ob.InputArray();
	ob.SS();
	ob.OutputArray();
	ob.Testing();
}
