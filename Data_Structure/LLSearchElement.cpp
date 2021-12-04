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
		  void Display()
		  {
		  	cout<<"\nLinked List is:";
		  	for(Node *current=head;current!=0;current=current->next)
		  	{
		  	 	cout<<current->data<<" ";
			}
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
		  int DeletionFromTail()
		  {
		  	if(tail)
		  	{
		  		Node *temp=tail,*current;
		  	    int value=tail->data;
		  		if(head==tail)
		  		{
				   head=tail=0;
				   delete temp;
				   return value;
				}
		  		for(current=head;current->next!=tail;current=current->next);
		  	    tail=current;
		  	    tail->next=0;
		  		delete temp;
		  		return value;
			}
			return -1;
		  }
		  bool Search(int el)
		  {
		  	for(Node *current=head;current!=0;current=current->next)
		  	{
		  		if(current->data==el)
		  			return true;
			}
			return false;
		  }
};
int main()
{
	SLL L;
	int el;
	L.addToHead(2);
	L.addToTail(3);
	L.addToHead(4);
	L.Display();
	cout<<"\nNo. of nodes in LL:"<<L.count();
	cout<<"\nEnter Element to be searched:";
	cin>>el;
	if(L.Search(el))
		cout<<"\nNode Found";
	else
		cout<<"\nNode Not Found";
}
