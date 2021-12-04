#include<iostream>
using namespace std;
class Sorting
{
	int *a,size,comp,shift;
	public :
	void Input()
	{
		cout<<"Enter the size of array\n";
		cin>>size;
		a=new int[size];
		cout<<"Enter the array\n";
		for(int i=0;i<size;i++)
		{
			cin>>a[i];
		}
		shift=0;
		comp=0;
		
   }
	void IS()
   {
   	 for(int i=1;i<size;i++)
	 {
	 	int temp=a[i];
	 	int j=i-1;
	 	while( a[j]>temp && j>=0)
	 	{
	 		a[j+1]=a[j];
	 		j--;
	 		comp++;
	 		shift++;
		 }
		 if(j>=0)
		    comp++;
		 a[j+1]=temp;
	 }
   }
   void Output()
   {
   	for(int i=0;i<size;i++)
   	    cout<<a[i]<<" ";
   }
   void Comparisons()
   {
   	cout<<"\nNo. of comparisons"<<comp;
   	cout<<"\nNo. of Shifts"<<shift;
   }
};
int main()
{
  Sorting ob;
  ob.Input();
  ob.IS();
  ob.Output();
  ob.Comparisons();
  return 0;	
}
