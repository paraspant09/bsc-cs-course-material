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
	int comp,swap;
  	Node *head, *tail;
  	public:SLL()
	      {
	      	head=tail=0;
	      	comp=swap=0;
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
		  int Display()
		  {
		  	int c=0;
		  	for(Node *current=head;current!=0;current=current->next)
		  	   cout<<current->data<<" ";
		  	cout<<"\n";
		  }
     void SS()
   {
   	 Node *temp,*temp2;
	 for(temp=head;temp->next!=0;temp=temp->next)
	 {
	 	Node *min=temp;
	 	for(temp2=temp->next;temp2!=0;temp2=temp2->next)                 //Array will be started sorting from begining after each iteration
	   {
	   	if(temp2->data < min->data)           //Find min. index
	    {
			min=temp2;
	    }
	    comp++;
	   }
	   if(temp!=min)
	   { 	int a=temp->data;
	  		    temp->data=min->data;
	  		    min->data=a;
	     swap++;
       }
     }
    }
    void Testing()
    {
    	cout<<"\nNo. of comparisons :"<<comp;
    	cout<<"\nNo. of swaps :"<<swap;
	}
};
int main()
{
	SLL L;
	int a;
	cout<<"Enter the unsorted Linked list(Press 0 for ending)\n";
	cin>>a;
	while(a)
	{
	   L.addToTail(a);
	   cin>>a;
    } 
    cout<<"\nUnsorted Linked List:";
	L.Display();
	L.SS();
	cout<<"\nSorted Linked List:";
	L.Display();
	L.Testing();
}
