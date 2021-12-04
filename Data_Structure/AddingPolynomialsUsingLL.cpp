/*Store a polynomial and evaluate it*/
#include<iostream>
#include<math.h>
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
	friend class polynomial;
};
class SLL
{
  	public:	Node *head, *tail;
	  		SLL()
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
};
class polynomial{
int n;
SLL L;
public:
void poly_input()
{
    cout<<"\nEnter highest degree of polynomial\n";
	cin>>n;
	n++;
	
	int a;
	for(int i=0;i<n;i++)
	{
	  cout<<"\nEnter coefficient of x^"<<i<<" ";
	  cin>>a;
	  L.addToHead(a);
	  cout<<"\n";
    }
}
void poly_output()
{
	Node *current;
	int i;
	cout<<"\nPolynomial is:\nP(x)=";
	for(current=L.head,i=n-1;current!=0;current=current->next,i--)
	{
		if(i!=0)
		{
	   	  if(current->data>0)
		 {
		   if(i!=n-1) cout<<"+";
	       if(current->data!=1) cout<<current->data;
		   cout<<"x^"<<i;
	     }
	      else if(current->data<0)
	     {
	       cout<<"-";
		   if(current->data!=-1) cout<<-current->data;
		   cout<<"x^"<<i;
	     }
	    }
	    else
	    {
        if(current->data>0)
	       cout<<"+"<<current->data;
	    else if(current->data<0)
	       cout<<current->data;
	    }
    }
}
void ADD_Poly(polynomial p1,polynomial p2)
{
	int i,small;
	Node *current,*curr2;
	if(p1.n>=p2.n)
	{
		n=p1.n;
		small=p2.n;
		current=p1.L.head;
	}
	else 
	{
		n=p2.n;
		small=p1.n;
		current=p2.L.head;
	}
	for(i=n;current!=0;current=current->next,i--)
	{
		if(i==small)
		{
			if(small==p1.n)
				curr2=p1.L.head;
			else
				curr2=p2.L.head;
		}
		if(i<=small)
		{
			L.addToTail(current->data+curr2->data);
			curr2=curr2->next;
		}
		else
			L.addToTail(current->data);
	}
}
};
int main()
{
	polynomial ob1,ob2,ob3;
	cout<<"\nEnter Polynomial 1,";
	ob1.poly_input();
	ob1.poly_output();
	cout<<"\nEnter Polynomial 2,";
	ob2.poly_input();
	ob2.poly_output();
	cout<<"\n\n\t\tAdding 2 Polynomials,";
	ob3.ADD_Poly(ob1,ob2);
	ob3.poly_output();
}
