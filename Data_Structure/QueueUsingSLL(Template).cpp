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
	template<class T> friend class SLL;
	template<class U> friend class Queue;
};
template <class Y> class SLL
{
  	Node<Y> *head, *tail;
  	public:SLL()
	      {
	      	head=tail=0;
	      }
	      void addToHead(Y el)
	      {
/*	      	Node *temp=new Node(el);   Made a node and passing value to it
	      	temp->next=head;           Giving value to its ptr the address of next node and giving head the address of this node
	      	head=temp; */
	      	head=new Node<Y>(el,head);
	      	if(!tail)
	      	  tail=head;
		  }
  	      void addToTail(Y el)
  	      {
  	      	if(tail)
  	      	{
		    Node<Y> *temp=new Node<Y>(el);
  	      	tail->next=temp;
			tail=temp;
		    }
  	      	else
  	      	   head=tail=new Node<Y>(el);
		  }
		  int count()
		  {
		  	int c=0;
		  	for(Node<Y> *current=head;current!=0;current=current->next,c++);
		  	return c;
		  }
		   Y DeletionFromHead()
		  {
		  	if(head)
		  	{
		  		Node<Y> *temp=head;
		  	    Y value=head->data;
		  		if(head==tail)
		  		    tail=0;
		  		head=head->next;
		  		delete temp;
		  		return value;
			}
			return -1;
		  }
		  void Display()
		  {
		  	if(head)
		  	{
			cout<<"\nQueue using Linked List is:";
		  	for(Node<Y> *current=head;current!=0;current=current->next)
		  	{
		  	 	cout<<current->data<<" ";
			}
			}
			else
			cout<<"\nEmpty  Queue\n";
		  }
		  void Clear()
		  {
		  	if(head)
		  	{
		  	Node<Y> *temp=head;
		  	for(Node<Y> *current=head;current!=0;current=temp)
		  	{
		  		temp=current->next;
		  	 	delete current;
			}
			}
			head=tail=0;
		  }
		   bool	isfull()
			{
				Node<Y> *tmp=new Node<Y>(0,0);
				if(!tmp)
					return true;
				delete tmp;
				return false;
			}
		template<class V>  friend class Queue;
};
template<class Z> class Queue{
	Node<Z> *front,*rear;
	SLL<Z> L;
	public:
	Queue()
	{
		front=rear=0;
	}
	void Enque(Z el)
	{
		L.addToTail(el);
		rear=L.tail;
		if(front==0)
			front=rear;
   }
   Z Deque()
   {
   	Z el=-1;
   	el=L.DeletionFromHead();
   	if(front==rear)           //Single element
   		front=rear=0;
   	else
   		front=L.head;
   	return el;
   }
   void Display()
   {
   	L.Display();
   }
    void Clear()
	{
		L.Clear();
	}
	bool isempty()
	{
		if(front==0)
		  return true;
		return false;
	}
	bool isFull()
	{
		return L.isfull();
	}
};
int main()
{
	Queue<int> Q;
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
					cout<<"\n Queue is empty";
				else
					cout<<"\n Queue is not empty";
				break;
		case 6: if(Q.isFull())
					cout<<"\n Queue is full";
				else
					cout<<"\n Queue is not full";
				break;
		default:cout<<"\n!!Wrong Choice!!";
	}
  	cout<<"\nPress y/Y to continue:";
  	cin>>ch;
  	}while(ch=='y'||ch=='Y');
}
