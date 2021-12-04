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
};
class Queue{
	int front,rear,*arr,n;
	public:Queue(int a){
		front=rear=-1;
		n=a;
		arr=new int[n];
	}
	bool isempty()
	{
		if(front==-1)
		  return true;
		return false;
	}
	bool isFull()
	{
		if(rear==n-1)
		  return true;
		return false;
	}
	void Clear()
	{
		front=rear=-1;
	}
	void Enque(int el)
	{
		if(!isFull())
		{
	    	if(isempty())
		       front=rear=0;
		    else
		       rear++;
		arr[rear]=el;
        }
        else
           cout<<"\nFull Queue\n";
   }
   int Deque()
   {
   	int el=-1;
   	if(!isempty())
   	{
   		el=arr[front];
   		if(front==rear)           //Single element
   		   front=rear=-1;
   		else
   		   front++;
    }
   	return el;
   }
};
Stack<int> ReverseStack(Stack <int>S,int n)
{
	Queue Q(n);
    while(!S.isempty())
   { 
     Q.Enque(S.POP());
   }
	while(!Q.isempty())
	{
	 S.PUSH(Q.Deque());
	}
  return S;	 
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
	S=ReverseStack(S,n);
	cout<<"\nStack after Reversal: ";
    S.PrintStack();
}
