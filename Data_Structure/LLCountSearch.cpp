#include<iostream>
using namespace std;
class Node
{
	int data,count;
	Node *next;        //Ask from mam that it is private cannot be used in line 32 and 41
	public:Node(int val,Node *ptr=0)
	      {
	      	data=val;
	      	next=ptr;
	      	count=1;
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
		  	Node *current,*prev;
		  	for(current=head,prev=head;current!=0;prev=current,current=current->next)
		  	{
		  		if(current->data==el)
		  		{
		  			current->count++;
		  			
		  			if(current==head)
		  				return true;
				  	//DecreasingOrderWithCount();
				  	Node *temp,*tempPrev;
				  	for(temp=head,tempPrev=head;temp!=current;tempPrev=temp,temp=temp->next)
				  	{
				  		if(temp->count < current->count)
				  		{
				  			if(current==tail)
				  				tail=prev;
				  			if(temp==head)
				  			{
				  				prev->next=current->next;
				  				current->next=temp;
				  				head=current;
				  				return true;
							}
				  			tempPrev->next=current;
				  			prev->next=current->next;
				  			current->next=temp;
				  			return true;
						}
					}
					return true;
		  		}
			}
			//AddToEndWithCount1();
			addToTail(el);
			return false;
		  }
		  int Feq()
		  {
		  	cout<<"\nLinked List's Count is:";
		  	for(Node *current=head;current!=0;current=current->next)
		  	{
		  	 	cout<<current->count<<" ";
			}
		  }
};
int main()
{
	SLL L;
	int el;
	char ch;
	L.addToHead(5);
	L.addToTail(2);
	L.addToHead(1);
	L.addToTail(3);
	L.addToHead(4);
	L.Display();
	L.Feq();
	cout<<"\nNo. of nodes in LL:"<<L.count();
	do{
	cout<<"\nEnter Element to be searched:";
	cin>>el;
	if(L.Search(el))
		cout<<"\nNode Found";
	else
		cout<<"\nNode Not Found";
	L.Display();
	L.Feq();
	cout<<"\nPress y/Y to continue";
	cin>>ch;
	}while(ch=='Y'||ch=='y');
}
