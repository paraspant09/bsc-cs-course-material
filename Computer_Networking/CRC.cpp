#include<iostream>
using namespace std;
class CRC{
	int *arr,n,r;	//data to be use to check correction in arr2(polynomial)
	int *arr2,n2;	//data to be send
	int *arr3;		//remainder
	int *arr4,n3;	//data to be received 
	public:
	CRC()
	{
		cout<<"\nEnter the highest degree of polynomial(key) use to send the data:";
		cin>>r;			//redundand bits
		n=r+1;			//no. of bits in divisor
	
		arr=new int[n];		//key
		arr3=new int[n];	//remainder(of both)
	}
	void InputKey()
	{
		int a=r;
		cout<<"\nEnter the divisor polynomial\n";
		for(int i=0;i<n;i++)
		{
			cout<<"\nEnter the coefficient of x^"<<a<<" :";
			cin>>arr[i];
			a--;
		}
		cout<<"\nPolynomial to be used in binary equivalent:";
		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<"\n";
	}
	void InputDataSender()
	{
		cout<<"\nEnter the size of the data bits to send:";
		cin>>n2;			//for  sender
		arr2=new int[n2+r];	//data bit(sender)
		cout<<"\nEnter the data to send:";
		for(int i=0;i<n2;i++)
			cin>>arr2[i];
		for(int i=n2;i<n2+r;i++)
			arr2[i]=0;
		cout<<"\nData bits appended with zero acc. to redundand bits:";
		for(int i=0;i<r+n2;i++)
			cout<<arr2[i]<<" ";
		cout<<"\n";
	}
	void Sender()
	{
		InputDataSender();
		int j=r,i=0,a,k=0,b=r;
		for(int i=0;i<n;i++)
			arr3[i]=arr2[i];
		a=arr3[0];
		while(true)
		{
			if(a==0)
			{
				arr3[k]=XOR(0,arr3[k]);
			}
			else
			{
				arr3[k]=XOR(arr[i],arr3[k]);
			}
			
			i++;
			k++;
			if(i==n)
			{
			 i=0;
			}
		
			if(k==n)
			{
				if(j==n2+r-1)
					break;
		/*		cout<<"\nPrinting before next bit:";
				for(int i=0;i<n;i++)
					cout<<arr3[i]<<" ";
				cout<<"\n";*/
				j++;
			//	cout<<j<<":"<<arr2[j]<<" ";
				k=0;
				while(k<n-1)
				{
					arr3[k]=arr3[k+1];
					k++;
				}
				arr3[k]=arr2[j];
				a=arr3[0];
		/*		cout<<"\nPrinting after next bit:";
				for(int i=0;i<n;i++)
					cout<<arr3[i]<<" ";
				cout<<"\n";*/
				k=0;
			}
		}
		
		for(int i=n2+r-1;i>=n2;i--)
		{
			arr2[i]=arr3[b];
			b--;
		}
		
		cout<<"\nRemainder:";
		for(int i=n2;i<n2+r;i++)
		{
			cout<<arr2[i]<<" ";
		}
		cout<<"\n";
	
		cout<<"\nData bits need to be sent:";
		for(int i=0;i<r+n2;i++)
			cout<<arr2[i]<<" ";
		cout<<"\n";
	}
	void InputDataReceiver()
	{
		cout<<"\nEnter the size of the data bits to be received:";
		cin>>n3;			//for  receiver
		arr4=new int[n3];	//Receiver data bit
		cout<<"\nEnter the data which is received:";
		for(int i=0;i<n3;i++)
			cin>>arr4[i];
	}
	void Receiver()
	{
		InputDataReceiver();
		bool check=true;
		int j=r,i=0,a,k=0,b=r;
		for(int i=0;i<n;i++)
			arr3[i]=arr4[i];
		a=arr3[0];
		while(true)
		{
			if(a==0)
			{
				arr3[k]=XOR(0,arr3[k]);
			}
			else
			{
				arr3[k]=XOR(arr[i],arr3[k]);
			}
			
			i++;
			k++;
			if(i==n)
			{
			 i=0;
			}
		
			if(k==n)
			{
				if(j==n3-1)
					break;
				j++;
				k=0;
			/*	cout<<"\nPrinting before next bit:";
				for(int i=0;i<n;i++)
					cout<<arr3[i]<<" ";
				cout<<"\n";*/
				while(k<n-1)
				{
					arr3[k]=arr3[k+1];
					k++;
				}
				arr3[k]=arr4[j];
			/*	cout<<"\nPrinting after next bit:";
				for(int i=0;i<n;i++)
					cout<<arr3[i]<<" ";
				cout<<"\n";*/
				a=arr3[0];
				k=0;
			}
		}
	/*		for(int i=n2+r-1;i>=n2;i--)
			{
				arr2[i]=arr3[b];
				b--;
			}	Not required here				*/
		cout<<"\nRemainder:";
		for(int i=1;i<n;i++)
		{
			cout<<arr3[i]<<" ";
			if(arr3[i]!=0)	check=false;
		}
		cout<<"\n";
	
		cout<<"\nData bits :";
		for(int i=0;i<n3;i++)
			cout<<arr4[i]<<" ";
		cout<<" received has ";
	
		if(check)
			cout<<"no error.\n";
		else
			cout<<"error.\n";
	}
	int XOR(int a,int b)
	{
		return(a^b);
	}
};
int main()
{
	CRC ob;
	int n;
	ob.InputKey();
	do
	{
		cout<<"Press:\n1)Sender Side \n2)Receiver Side \n3)Exit\n";
		cin>>n;
		cout<<"\n";
		if(n==1)
			ob.Sender();
		else if(n==2)
			ob.Receiver();
		else if(n==3)
			break;
		else
			cout<<"!!!Wrong choice!!!\n";
	}while(true);
}
