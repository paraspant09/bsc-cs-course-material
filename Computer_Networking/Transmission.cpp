#include<iostream>
#include<math.h>
using namespace std;
class Transmission{
	int *arr,*arr2,n,m,r,*redarr;
	public:Transmission()
	      {
	      	cout<<"Enter the size of the data bits (m) of sender:";
	      	cin>>m;
	      	arr=new int[m];
	      	n=r=0;
	      }
	      
	      void InputSender()
	      {
	      	cout<<"Enter the data bits in 1/0 Format :";
	      	for(int i=m-1;i>=0;i--)
	      	  cin>>arr[i];
	      	RedundantBits();
		  }
		  
		  void InputReceiver()
	      {
	      	RedundantBits();
	      	arr2=new int[n];
	      	cout<<"Enter the data bits in 1/0 Format in Humming code of size "<<n<<" bits:";
	      	for(int i=0;i<n;i++)
	      	  cin>>arr2[i];
		  }
		  
	/*	  void ReverseArray(int arr[],int size)
		  {
			  for(int i=0;i<size/2;i++)
		    {
		    	int temp=arr[size-i-1];
		    	    arr[size-i-1]=arr[i];
		    	    arr[i]=temp;
			}
		  }	*/
		  
		  void RedundantBits()
		  {
		  	for(int i=0;i<m;i++)
		  	 if( pow(2,i)>=m+i+1 )
		  	 {
		        r=i;
		  	    break;
		  	 }
		  	 n=m+r;
		  }
		  
		  void Sender()
		  {
		  	InputSender();
		  	arr2=new int[n];
		  	int shift=0,a=r-1,b=0,c=0,count;
		  	//Putting the values of data bits in n to 1 form
		  	for(int i=n;i>=1;i--)
		  	{
				if(pow(2,a)==i)
		  		  a--;
				else
		  		{
		  			arr2[i-1]=arr[b];
		  			b++;
				}
			}
			//Putting value in redundant bits in 1 to n form
		  	while(c!=r)
		  	{
		  		shift=pow(2,c);
		  		count=0;
		  	for(int i=1;i<=n;i++)
		  	{
		  		if((shift&i)==shift)
		  		{
		  			if(arr2[i-1]==1)
		  			  count++;
				}
			}
			if(count%2==0)
			    arr2[shift-1]=0;
			else
			    arr2[shift-1]=1;
			c++;
		    }
		    cout<<"Data Transfered is :"; // can return as well in reverse order of array
		   //Just to print the transmitted data
	//	   ReverseArray(arr2,n);
		   DataArray();
		  }
		  
		  void Receiver()
		  {
		  	//if array arr2[] is received in reverse order then reverse it again
		  	InputReceiver();  //If donot want to enter the array then remove this will automatically give it previous value of arr2 fom sender
		  //	ReverseArray(arr2,n);
		  	redarr=new int[r];
		  	int c=0,temp=0,shift=0,count=0;
			while(c!=r)
		  	{
		  		shift=pow(2,c);
		  		count=0;
		  	for(int i=1;i<=n;i++)
		  	{
		  		if((shift&i)==shift)
		  		{
		  			if(arr2[i-1]==1)
		  			  count++;
				}
			}
			if(count%2==0)
			    redarr[c]=0;
			else
			    redarr[c]=1;
			c++;
		    }
		    for(int i=0;i<r;i++)
		    {
		    	temp+=redarr[i]*pow(2,i);
			}
			if(temp!=0)
			{
			  	cout<<"Error in no. "<<temp<<" Bit from backward .";
				cout<<"\n";
			  	if(arr2[temp-1]==1) arr2[temp-1]=0;
			  	else arr2[temp-1]=1;
			}
			else
			  cout<<"\nNo error\n";
		    cout<<"\nCorrected Data Received is :"; 
		 //   ReverseArray(arr2,n);
		    DataArray();
		  }
		  
		  void DataArray()
		  {
		  	 for(int i=0;i<n;i++)
		      cout<<arr2[i]<<" ";
		  }
};
int main()
{
	Transmission ob;
	ob.Receiver();
	return 0;
}
