#include<iostream>
using namespace std;
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
   void StackPush(int el)
  {
	Enque(el);
  }  
  int StackPOP()
  {
  	Queue Q1(n);
	int el=Deque();
	if(!isempty())
	{
	while(!isempty())
	{
		Q1.Enque(el);  //Will not run for last element 
		el=Deque();
	}
	while(!Q1.isempty())
	{
		Enque(Q1.Deque());
	}
	return el;    //last element will be stored in el
    }
    else
     return el;
  }
};
int main()
{
	int n;
	cout<<"\nEnter size of array for Queue implementation:";
	cin>>n;
	Queue Q(n);
	Q.StackPush(2);
	Q.StackPush(3);
	cout<<"\nDeleted Element:"<<Q.StackPOP();
	Q.StackPush(4);
	Q.StackPush(5);
	cout<<"\nDeleted Element:"<<Q.StackPOP();
	cout<<"\nDeleted Element:"<<Q.StackPOP();
	cout<<"\nDeleted Element:"<<Q.StackPOP();
	cout<<"\nDeleted Element:"<<Q.StackPOP();
}
