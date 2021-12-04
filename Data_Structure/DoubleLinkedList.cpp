#include<iostream>
using namespace std;
class Node
{
	int data;
	Node *next;       
	Node *prev;
	public:Node(int val,Node *ptr=0,Node *temp=0)
	      {
	      	data=val;
	      	next=ptr;
	      	prev=temp;
		  }
	friend class DLL;
};
class DLL
{
  	Node *head, *tail;
  	public:DLL()
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
	      	else
	      		head->next->prev=head;
		  }
  	      void addToTail(int el)
  	      {
  	      	if(tail)
  	      	{
		    tail->next=new Node(el,0,tail);
			tail=tail->next;
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
		  		    head=tail=0;
		  		else
		  			head->next->prev=0;
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
		  		Node *temp=tail;
		  	    int value=tail->data;
		  		if(head==tail)
				   head=tail=0;
				else
		  	    {
					tail=tail->prev;
					tail->next=0;
				}
		  		delete temp;
		  		return value;
			}
			return -1;
		  }
		  void Display()
		  {
		  	cout<<"\nLinked List is:";
		  	for(Node *current=head;current!=0;current=current->next)
		  	{
		  	 	cout<<current->data<<" ";
			}
		  }
		    bool Search(int el)
		  {
		  	if(head)
			{
			for(Node *current=head;current!=0;current=current->next)
		  	{
		  		if(current->data==el)
		  			return true;
			}
			}
			return false;
		  }
		   void Reverse()
		  {
		  	Node  *cur,*end;
		  	if(head)
			{
				for(cur=head,end=tail;;cur=cur->next,end=end->prev)
		  		{
					int value=cur->data;
					cur->data=end->data;
					end->data=value;
					if(cur==end || cur->next==end) break;
				}
			}
		  }
};
int main()
{
	DLL L;
	int a;
	cout<<"Enter the Linked list(Press 0 for ending)\n";
	cin>>a;
	while(a)
	{
	   L.addToTail(a);
	   cin>>a;
    } 
	char ch;
	do
	{
		cout<<"\nPress \n1)To display LL \n2)Add to head \n3)Add to tail \n4)Count";
		cout<<"\n5)To delete head\n6)To delete tail\n";
		cout<<"7)To Search an element \n8)To Reverse List \n";
		cin>>a;
		switch(a)
		{
			case 1: if(L.count())
						L.Display();
					else  cout<<"\nEmpty Linked List";
					break;
			case 2:	cout<<"\nEnter value of node to be added:";
					cin>>a;
					L.addToHead(a);
					break;
			case 3:	cout<<"\nEnter value of node to be added:";
					cin>>a;
					L.addToTail(a);
					break;
			case 4:	cout<<"\nNumber of nodes in Linked List:"<<L.count();
					break;
			case 5: a=L.DeletionFromHead();
					if(a==-1)
						cout<<"\nEmpty linked List";
					break;
			case 6: a=L.DeletionFromTail();
					if(a==-1)
						cout<<"\nEmpty linked List";
					break;
			case 7: cout<<"\nEnter value of node to be searched:";
					cin>>a;
					if(L.Search(a))
						cout<<"\nElement Found\n";
					else
						cout<<"\nElement Not Found\n";
					break;
			case 8:	if(L.count())
						L.Reverse();
					else  cout<<"\nEmpty Linked List";
					break;
			default:cout<<"\n!!Wrong Choice!!";
		}
		cout<<"\nPress y/Y to continue:";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
}
