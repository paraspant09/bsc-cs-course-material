#include<iostream>
using namespace std;
class Node
{
	int data;
	Node *next;       
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
			cout<<"\nStack using Linked List is:";
		  	for(Node *current=head;current!=0;current=current->next)
		  	{
		  	 	cout<<current->data<<" ";
			}
			}
			else
			cout<<"\nEmpty Stack\n";
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
		  friend class Stack;
};
class Stack{
	Node* top;
	SLL L;
	public:
		Stack()
		{	
			top=0;
		}
		void PUSH(int x)
		{
			  L.addToHead(x);
			  top=L.head;
		}
		int POP()
		{
			int a=-1;
			if(top==0)
			{
			   cout<<"Underflow";
		    }
			else
			{
			  a=L.DeletionFromHead();
			  top=L.head;
			}
			return a;
		}
		 void DisplayStack()
		 {
		 	if(top)
		 		L.Display();
		 	else
		 		cout<<"\nEmpty Stack\n";
		 }
		 bool isempty()
		 {
		 	if(top)
		 		return false;
		 	return true;
		 }
		 void clear()
		 {
		 	L.Clear();
		 	top=0;
		 }
};
int main()
{
   int n,a;
  char ch;
  Stack S;
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
		case 4: S.DisplayStack();
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
