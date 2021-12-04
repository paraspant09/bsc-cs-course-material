#include<iostream>
using namespace std;
class Node
{
	int data;
	Node *next;        //Ask from mam that it is private cannot be used in line 32 and 41
	public:Node(int val,Node *ptr=0)
	      {
	      	data=val;
	      	next=ptr;
		  }
	friend class SLL;
};
class SLL
{
  	Node *head, *tail;
  	public:SLL()
	      {
	      	head=tail=0;
	      }
	      void addToHead(int el)
	      {
/*	      	Node *temp=new Node(el);   Made a node and passing value to it
	      	temp->next=head;           Giving value to its ptr the address of next node and giving head the address of this node
	      	head=temp; */
	      	head=new Node(el,head);
	      	if(!tail)
	      	  tail=head;
		  }
  	      void addToTail(int el)
  	      {
  	      	if(tail)
  	      	{
		    Node *temp=new Node(el);
  	      	tail->next=temp;
			tail=temp;
		    }
  	      	else
  	      	   head=tail=new Node(el);
		  }
		  int count()
		  {
		  	int c=0;
		  	for(Node *current=head;current!=0;current=current->next,c++);
		  	return c;
		  }
		   int DeletionFromHead()
		  {
		  	if(head)
		  	{
		  		Node *temp=head;
		  	    int value=head->data;
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
			cout<<"\nCircular Queue using Linked List is:";
		  	for(Node *current=head;current!=0;current=current->next)
		  	{
		  	 	cout<<current->data<<" ";
			}
			}
			else
			cout<<"\nEmpty Circular Queue\n";
		  }
		  void Clear()
		  {
		  	if(head)
		  	{
		  	Node *temp=head;
		  	for(Node *current=head;current!=0;current=temp)
		  	{
		  		temp=current->next;
		  	 	delete current;
			}
			}
			head=tail=0;
		  }
		   bool	isfull()
			{
				Node *tmp=new Node(0,0);
				if(!tmp)
					return true;
				delete tmp;
				return false;
			}
		  friend class Queue;
};
class Queue{
	Node *front,*rear;
	SLL L;
	public:
	Queue()
	{
		front=rear=0;
	}
	void Enque(int el)
	{
		L.addToTail(el);
		rear=L.tail;
		if(front==0)
			front=rear;
   }
   int Deque()
   {
   	int el=-1;
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
	Queue Q;
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
