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
    void BS()
   {
   	 int i,c=0;
   	 Node *temp,*temp2;
   	 int cnt=count();
	 for(temp=head;temp!=0;temp=temp->next)
	 {
	    c=0;
	    i=0;
	   for(temp2=head;i<cnt-1;temp2=temp2->next)
	   {
	  	if(temp2->data > temp2->next->data)
	  	 {
	  		int a=temp2->data;
	  		    temp2->data=temp2->next->data;
	  		    temp2->next->data=a;
	  		c++;
	  		swap++;
		 }
		  comp++;
		  i++;
	   }
	    cnt--;
	 	 if(c==0)
		   break;
      }
    }
    void Testing()
    {
    	cout<<"\nNo. of comparisons :"<<comp;
    	cout<<"\nNo. of swaps :"<<swap;
	}
	void Concatenate(SLL L)
	{
		tail->next=L.head;
		L.head=L.tail=0;
	}
	void operator +(SLL L)
	{
		Concatenate(L);
	}
};
int main()
{
	SLL L,L1;
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
	L.BS();
	cout<<"\nSorted Linked List:";
	L.Display();
	cout<<"Enter the unsorted Linked list(Press 0 for ending)\n";
	cin>>a;
	while(a)
	{
	   L1.addToTail(a);
	   cin>>a;
    } 
    cout<<"\nUnsorted Linked List:";
	L1.Display();
	L1.BS();
	cout<<"\nSorted Linked List:";
	L1.Display();
	cout<<"\nConcatenated Linked List Of Two Linked Lists is:";
//	L.Concatenate(L1);
	L+L1;
	L.Display();
}
