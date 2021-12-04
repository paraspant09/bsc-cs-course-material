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
    void BS()
   {
   	 int i,j=0,c=0;
	 for(i=0;i<n;i++)
	 {
	   c=0;
	   for(j=0;j<(n-i-1);j++)
	   {
	  	if(arr[j]>arr[j+1])
	  	 {
	  		int temp=arr[j];
	  		    arr[j]=arr[j+1];
	  		    arr[j+1]=temp;
	  		c++;
	  		swap++;
		 }
		 comp++;
	   }
	  	 if(c==0)
		   break;
      }
    }
    void Testing()
    {
    	cout<<"\nNo. of comparisons :"<<comp;
    	cout<<"\nNo. of swaps :"<<swap;
	}
};
int main()
{
	Sorting ob;
	ob.InputArray();
	ob.BS();
	ob.OutputArray();
	ob.Testing();
}
