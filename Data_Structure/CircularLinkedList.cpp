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
	friend class CLL;
};
class CLL
{
  	Node *tail;				//Only Tail in circular linked List
  	public:CLL()
	      {
	      	tail=0;
	      }
  	      void addToTail(int el)
  	      {
  	      	if(tail)
  	      	{
		    tail->next=new Node(el,tail->next);	//Becoz tail->next points to head of the Linked List
  	      	tail=tail->next;
		    }
  	      	else
  	      	{
			    tail=new Node(el);
			    tail->next=tail;
			}
		  }
		   int DeletionFromTail()
		  {
		  	if(tail)
		  	{
		  		Node *temp=tail,*current;
		  	    int value=tail->data;
		  		if(tail->next==tail)
		  		{
				   tail=0;
				   delete temp;
				   return value;
				}
		  		for(current=tail->next;current->next!=tail;current=current->next);
		  	    current->next=tail->next;
				tail=current;
		  		delete temp;
		  		return value;
			}
			return -1;
		  }
		  int count()
		  {
		  	int c=0;
		  	if(tail)
		  	{
		  		Node *current=tail;
		  		do
		  		{
		  			c++;
		  			current=current->next;
				}while(current!=tail);
			}
		  	//	for(Node *current=tail->next;current!=tail;current=current->next,c++);
		  	return c;
		  }
		  void Display()
		  {
		  	if(tail)
		  	{
		 	Node *current=tail->next; 	
		  	cout<<"\nLinked List is:";
		  	do
		  	{
		  	 	cout<<current->data<<" ";
		  	 	current=current->next;
			}while(current!=tail->next);
			}
		  }
		  bool Search(int el)
		  {
		  	if(tail)
		  	{
		 	Node *current=tail; 	
		  	do
		  	{
		  	 	if(current->data == el)	return true;
		  	 	current=current->next;
			}while(current!=tail);
			}
			return false;
		  }
};
int main()
{
	CLL L;
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
		cout<<"\nPress \n1)To display LL\n2)Add to tail \n3)Count";
		cout<<"\n4)To delete tail\n";
		cout<<"5)To Search an element \n";
		cin>>a;
		switch(a)
		{
			case 1: if(L.count())
						L.Display();
					else  cout<<"\nEmpty Linked List";
					break;
			case 2:	cout<<"\nEnter value of node to be added:";
					cin>>a;
					L.addToTail(a);
					break;
			case 3:	cout<<"\nNumber of nodes in Linked List:"<<L.count();
					break;
			case 4: a=L.DeletionFromTail();
					if(a==-1)
						cout<<"\nEmpty linked List";
					break;
			case 5: cout<<"\nEnter value of node to be searched:";
					cin>>a;
					if(L.Search(a))
						cout<<"\nElement Found\n";
					else
						cout<<"\nElement Not Found\n";
					break;
			default:cout<<"\n!!Wrong Choice!!";
		}
		cout<<"\nPress y/Y to continue:";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
}
