#include<iostream>
using namespace std;
class Queue{
	int front,rear,*arr,n;
	public:Queue(){
		front=rear=-1;
		cout<<"\nEnter size of array for Queue implementation:";
		cin>>n;
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
   void Display()
   {
   	cout<<"\nQueue is :";
   	for(int i=0;i<n;i++)
   	  cout<<arr[i]<<" ";
   	cout<<endl;
   }
};
int main()
{
	Queue Q;
	Q.Enque(2);
	Q.Enque(3);
	cout<<"\nDeleted Element:"<<Q.Deque();
	Q.Enque(4);
	Q.Enque(5);
	Q.Display();
	cout<<"\nDeleted Element:"<<Q.Deque();
	cout<<"\nDeleted Element:"<<Q.Deque();
	cout<<"\nDeleted Element:"<<Q.Deque();
	cout<<"\nDeleted Element:"<<Q.Deque();
}
