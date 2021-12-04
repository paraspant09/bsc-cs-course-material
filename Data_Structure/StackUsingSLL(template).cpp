#include<iostream>
using namespace std;
template <class X> class Node3
{
	X data;
	Node3<X> *next;        
	public:Node3(X val,Node3<X> *ptr=0)
	      {
	      	data=val;
	      	next=ptr;
		  }
	template<class U> friend class Stack;
};
template <class Y> class Stack
{
  	Node3<Y> *top;
  	public:Stack()
	      {
	      	top=0;
	      }
	      void addToHead(Y el)
	      {
	       top=new Node3<Y>(el,top);
		  }
		  int count()
		  {
		  	int c=0;
		  	for(Node3<Y> *current=top;current!=0;current=current->next,c++);
		  	return c;
		  }
		   Y DeletionFromHead()
		  {
		  	if(top)
		  	{
		  		Node3<Y> *temp=top;
		  	    Y value=top->data;
		  		top=top->next;
		  		delete temp;
		  		return value;
			}
			return NULL;
		  }
		  void Display()
		  {
		  	Node3<Y> *current;
			cout<<"\nStack using Linked List is:";
		  	for(current=top;current!=0;current=current->next)
		  	{
		  	 	cout<<current->data->data<<" ";
			}
		  }
		  void Clear()
		  {
		  	if(top)
		  	{
		  	Node3<Y> *temp=top;
		  	for(Node3<Y> *current=top;current!=0;current=temp)
		  	{
		  		temp=current->next;
		  	 	delete current;
			}
			}
			top=0;
		  }
		  void PUSH(Y x)
		{
			  addToHead(x);
		}
		Y POP()
		{
			Y a;
			if(top==0)
			{
			   cout<<"Underflow";
			   return NULL;
		    }
			else
			{
			  a=DeletionFromHead();
			  return a;
			}
		}
		 void DisplayStack()
		 {
		 	if(top!=NULL)
		 		Display();
		 	else
		 		cout<<"\nEmpty Stack\n";
		 }
		 bool isempty()
		 {
		 	if(top!=NULL)
		 		return false;
		 	return true;
		 }
		 void clear()
		 {
		 	Clear();
		 	top=0;
		 }
};
int main()
{
   int n,a;
  char ch;
  Stack<Node3<int>*> S;
  Node3<int> *cur;
  do
  {
  	cout<<"\nPress \n1)Push \n2)POP \n3)Clear \n4)Display \n5)isEmpty \n";
  	cin>>a;
  	switch(a)
  	{
  		case 1: cout<<"\nEnter element to PUSH:";
  				cin>>a;
  				cur=new Node3<int>(a);
		  		S.PUSH(cur);
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
