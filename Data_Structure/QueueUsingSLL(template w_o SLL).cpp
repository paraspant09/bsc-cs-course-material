#include<iostream>
using namespace std;
template <class X> class Node
{
	X data;
	Node<X> *next;        
	public:Node(X val,Node<X> *ptr=0)
	      {
	      	data=val;
	      	next=ptr;
		  }
	template<class U> friend class Queue;
};
template <class Y> class Queue
{
  	Node<Y> *front, *rear;
  	public:Queue()
	      {
	      	front=rear=0;
	      }
  	      void addToTail(Y el)
  	      {
  	      	if(rear)
  	      	{
		    Node<Y> *temp=new Node<Y>(el);
  	      	rear->next=temp;
			rear=temp;
		    }
  	      	else
  	      	   front=rear=new Node<Y>(el);
		  }
		   Y DeletionFromHead()
		  {
		  	if(front)
		  	{
		  		Node<Y> *temp=front;
		  	    Y value=front->data;
		  		if(front==rear)
		  		    rear=0;
		  		front=front->next;
		  		delete temp;
		  		return value;
			}
			return -1;
		  }
		  void Display()
		  {
		  	if(front)
		  	{
			cout<<"\nQueue using Linked List is:";
		  	for(Node<Y> *current=front;current!=0;current=current->next)
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
};
int main()
{
	Queue<int> Q;
	int a;
  	char ch;
	do
  	{
  	cout<<"\nPress \n1)Enqueue \n2)Dequeue \n3)Display \n";
  	cin>>a;
  	switch(a)
  	{
  		case 1: cout<<"\nEnter element to Enqueue:";
  				cin>>a;
		  		Q.Enque(a);
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
