#include<iostream>
#include<string.h>
#include<math.h>
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
			if(top==-1)
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
			for(int i=0;i<=top;i++)
			   cout<<arr[i]<<" ";
		}
		int COUNT()
		{
			return top;
		}
		int topel()
		{
			return arr[top];
		}
};
void ReverseStack(Stack <int>S)
{
	int count=S.COUNT();
	Stack <int>S2(count);
	int a,b=-1;
	while(count!=0)
	{
	a=S.POP();
	while(!S.isempty() && S.topel()!=b)
	{
		S2.PUSH(S.POP());
	}
	b=a;
	S.PUSH(a);
	while(!S2.isempty())
	{
		S.PUSH(S2.POP());
	}
	count--;
	} 
}
int main()
{
  int n,a;
  cout<<"\nEnter size of array implemented Stack you need to reverse :";
  cin>>n;
  Stack <int>S(n);
  cout<<"\nEnter elements of array implemented Stack you need to reverse of size "<<n<<" :\n";
  for(int i=0;i<n;i++)
   {
    cin>>a;
	S.PUSH(a);
   }
    cout<<"Stack before Reversal: ";
    S.PrintStack();
	ReverseStack(S);
	cout<<"\nStack after Reversal: ";
    S.PrintStack();
}
