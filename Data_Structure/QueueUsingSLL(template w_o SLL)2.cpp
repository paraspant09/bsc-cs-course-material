#include<iostream>
using namespace std;
template <class X> class Node2
{
	X data;
	Node2<X> *next;        
	public:Node2(X val,Node2<X> *ptr=0)
	      {
	      	data=val;
	      	next=ptr;
		  }
	template<class U> friend class Queue;
};
template <class Y> class Queue
{
  	Node2<Y> *front, *rear;
  	public:Queue()
	      {
	      	front=rear=0;
	      }
  	      void addToTail(Y el)
  	      {
  	      	if(rear)
  	      	{
		    Node2<Y> *temp=new Node2<Y>(el);
  	      	rear->next=temp;
			rear=temp;
		    }
  	      	else
  	      	   front=rear=new Node2<Y>(el);
		  }
		   Y DeletionFromHead()
		  {
		  	if(front)
		  	{
		  		Node2<Y> *temp=front;
		  	    Y value=front->data;
		  		if(front==rear)
		  		    rear=0;
		  		front=front->next;
		  		delete temp;
		  		return value;
			}
			return NULL;
		  }
		  void Display()
		  {
		  	if(front)
		  	{
			cout<<"\nQueue using Linked List is:";
		  	for(Node2<Y> *current=front;current!=0;current=current->next)
		  	{
		  	 	cout<<current->data<<" ";
			}
			}
			else
			cout<<"\nEmpty Queue\n";
		  }
     		void Enque(Y el)
			{
				addToTail(el);
   			}
   			Y Deque()
   			{
   			Y el;
   			el=DeletionFromHead();
   			return el;
   			}
   			bool isempty()
			{
				if(front==0)
				  return true;
				  return false;
			}
};
int main()
{
	Queue<Node2<int>*> Q;
	Node2<int> *cur=new Node2<int>(2);
	int a;
  	char ch;
	do
  	{
  	cout<<"\nPress \n1)Enqueue \n2)Dequeue \n3)Display \n";
  	cin>>a;
  	switch(a)
  	{
  		case 1: //cout<<"\nEnter element to Enqueue:";
  				//cin>>a;
		  		Q.Enque(cur);
		  		break;
		case 2: Q.Deque();
				break;
		case 3: Q.Display();
				break;
		default:cout<<"\n!!Wrong Choice!!";
	}
  	cout<<"\nPress y/Y to continue:";
  	cin>>ch;
  	}while(ch=='y'||ch=='Y');
}
