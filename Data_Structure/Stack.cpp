#include<iostream>
using namespace std;
template<class X> class Stack
{
 X *arr;
 int n,top;
 public:
        Stack(int a)	
        {
        	n=a;
        	arr=new X[n];
        	top=-1;
		}
	    void PUSH(X a)
		{
			if(top==n-1)
			   cout<<"OverFlow";
			else
			   arr[++top]=a;
		}
	    X POP()
		{
			if(isempty())
			   cout<<"UnderFlow";
			else
			   return (arr[top--]);
			return -1;
		}
		bool isempty()
		{
			if(top==-1)
			    return true;
			return false;
		}
		void PrintStack()
		{
			if(!isempty())
			{
			cout<<"\nStack is:";
			for(int i=0;i<=top;i++)
			   cout<<arr[i]<<" ";
			cout<<"\n";
			}
			else
			cout<<"\nStack is empty\n";
		}
		void clear()
		{
			top=-1;
		}
};
int main()
{
  int n,a;
  char ch;
  cout<<"\nEnter size of array implemented Stack:";
  cin>>n;
  Stack <int>S(n);
  do
  {
  	cout<<"\nPress \n1)Push \n2)POP \n3)Clear \n4)Display \n5)isEmpty \n";
  	cin>>a;
  	switch(a)
  	{
  		case 1: cout<<"\nEnter element to PUSH:";
  				cin>>a;
		  		S.PUSH(a);
		  		break;
		case 2: S.POP();
				break;
		case 3: S.clear();
				break;
		case 4: S.PrintStack();
				break;
		case 5: if(S.isempty())
					cout<<"\nStack is empty";
				else
					cout<<"\nStack is not empty";
				break;
		default:cout<<"\n!!Wrong Choice!!";
	}
  	cout<<"\nPress y/Y to continue:";
  	cin>>ch;
  }while(ch=='y'||ch=='Y');
}
