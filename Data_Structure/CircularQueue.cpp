#include<iostream>
using namespace std;
template <class X> class CircularQueue{
	int front,rear,n;
	X *arr;
	public:CircularQueue(){
		front=rear=-1;
		cout<<"\nEnter size of array for CircularQueue implementation:";
		cin>>n;
		arr=new X[n];
	}
	bool isempty()
	{
		if(front==-1)
		  return true;
		return false;
	}
	bool isFull()
	{
		return ((rear+1)%n==front);//return((rear==n-1&&front==0) || (rear+1==front)); or when rear+1==front and if rear goes after n-1 then %n bring it back to 0
	}
	void Clear()
	{
		front=rear=-1;
	}
	void Enque(X el)
	{
		if(!isFull())
		{
	    	if(isempty())
		       front=0;
		rear=(rear+1)%n;  //increment rear acc. to size it means if rear goes after n-1 then %n bring it back to 0
		arr[rear]=el;
//		cout<<rear<<" "<<arr[rear]<<" ";
        }
        else
           cout<<"\nFull Queue\n";
   }
   X Deque()
   {
   	X el=-1;
   	if(!isempty())
   	{
   		el=arr[front];
   		if(front==rear)           //Single element
   		   front=rear=-1;
   		else
   		   front=(front+1)%n;
    }
   	return el;
   }
   	void Display()
		{
			if(!isempty())
			{
			int i=front;
			cout<<"\nCircular Queue is:";
			cout<<arr[i]<<" ";
			do
			{
				i=(i+1)%n;
				cout<<arr[i]<<" ";
			}while(i!=rear);
			cout<<"\n";
			}
			else
			cout<<"\nCircular Queue is empty\n";
		}
};
int main()
{
  CircularQueue <int>Q;
  int a;
  char ch;
  do
  {
  	cout<<"\nPress \n1)Enqueue \n2)Dequeue \n3)Clear \n4)Display \n5)isEmpty \n6)isFull \n";
  	cin>>a;
  	switch(a)
  	{
  		case 1: cout<<"\nEnter element to Enqueue:";
  				cin>>a;
		  		Q.Enque(a);
		  		break;
		case 2: Q.Deque();
				break;
		case 3: Q.Clear();
				break;
		case 4: Q.Display();
				break;
		case 5: if(Q.isempty())
					cout<<"\nCircular Queue is empty";
				else
					cout<<"\nCircular Queue is not empty";
				break;
		case 6: if(Q.isFull())
					cout<<"\nCircular Queue is full";
				else
					cout<<"\nCircular Queue is not full";
				break;
		default:cout<<"\n!!Wrong Choice!!";
	}
  	cout<<"\nPress y/Y to continue:";
  	cin>>ch;
  }while(ch=='y'||ch=='Y');
}
