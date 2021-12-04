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
	friend class OLL;
};
class OLL
{
  	Node *head, *tail;
  	public:OLL()
	      {
	      	head=tail=0;
	      }
	      void Insertion(int el)
	      {
	      	if(!head)
	      		head=new Node(el,0);
	      	else
	      	{
	      		if(head==tail)
	      		{
	      			if(head->data >= el)
					  	head=new Node(el,head);
					else
					{
						head->next=new Node(el,0);
						tail=head->next;
					}
				}
				else
				{
					Node *current,*prev,*temp;
	      			for(prev=current=head;current!=0;prev=current,current=current->next)
	      			{
	      				temp=current;
	      				if(current->data >= el)
						 	break;	
					}
					if(temp==tail && !current)
					{
						prev->next=new Node(el,0);
						tail=prev->next;
					}
					else if(current!=head)
						prev->next=new Node(el,temp);
					else
						head=new Node(el,temp);
				}
			}
	      	if(!tail)
	      	  tail=head;
	  /*    	cout<<endl<<head->data<<"	"<<tail->data<<endl;
	      	Display();*/
		  }
  	      
		   void Display()
		  {
		  	cout<<"\nLinked List is:";
		  	for(Node *current=head;current!=0;current=current->next)
		  	{
		  	 	cout<<current->data<<" ";
			}
		  }
		  int count()
		  {
		  	int c=0;
		  	if(head) for(Node *current=head;current!=0;current=current->next,c++);
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
		  int DeleteParticularNode(int el)
		  {
		  	Node *current,*prev;
		  	if(head)
		  	{
		  		if(head==tail)
		  		{
		  			if(head->data==el)
		  			{
		  				return DeletionFromHead();
					}
					else
						return -1;
				}
				else if(head->data==el)			//if more than 1 node but element is on head;
					return DeletionFromHead();
				else
				{
					for(prev=head,current=head;current!=0;prev=current,current=current->next)
					{
						int val=current->data;
						if(val==el)
						{
							prev->next=current->next;
							if(current==tail)		//if no node after current node which we are deleting then tail need to be previous node
								tail=prev;
							delete current;
							return val;
						}
					}
				}
			}
			return -1;
		  }
		  Node* MergeRecur(Node* ptr1,Node* ptr2)
		  {
		  	if(!ptr1)
		  		return ptr2;
		  	else if(!ptr2)
		  		return ptr1;
		  	else if(ptr1->data <= ptr2->data)
		  	{
		  		ptr1->next=MergeRecur(ptr1->next,ptr2);
		  		return ptr1;
			}
			else 
			{
				ptr2->next=MergeRecur(ptr1,ptr2->next);
				return ptr2;
			}
		  }
		  void Cover(OLL L)
		  {
		  	Node *max;
		  	if(tail->data > L.tail->data)
		  		max=tail;
		  	else
		  		max=L.tail;
		  	MergeRecur(head,L.head);
		  	if(head->data > L.head->data)
		  		head=L.head;
		  	tail=max;
		  }
		  void Remove()
		  {
			head=tail=0;
		  }
};
int main()
{
/*	OLL ob;
	ob.Insertion(1);
	ob.Insertion(3);
	ob.Insertion(5);
	ob.Insertion(7);
	ob.Insertion(4);
	ob.Insertion(2);
	ob.Insertion(8);
	ob.Insertion(6);
	ob.Display();*/
	OLL L,L1;
	int a;
	cout<<"Enter the Linked list(Press 0 for ending)\n";
	cin>>a;
	while(a)
	{
	   L.Insertion(a);
	   cin>>a;
    } 
	char ch;
	do
	{
		cout<<"\nPress \n1)To display LL \n2)Insertion \n3)Count";
		cout<<"\n4)To delete head\n5)To delete tail\n6)To delete Particular node\n";
		cout<<"7)Merge with Recursion\n";
		cin>>a;
		switch(a)
		{
			case 1: if(L.count())
						L.Display();
					else  cout<<"\nEmpty Linked List";
					break;
			case 2:	cout<<"\nEnter value of node to be inserted:";
					cin>>a;
					L.Insertion(a);
					break;
			case 3:	cout<<"\nNumber of nodes in Linked List:"<<L.count();
					break;
			case 4: a=L.DeletionFromHead();
					if(a==-1)
						cout<<"\nEmpty linked List";
					break;
			case 5: a=L.DeletionFromTail();
					if(a==-1)
						cout<<"\nEmpty linked List";
					break;
			case 6: cout<<"\nEnter value of node to be deleted:";
					cin>>a;
					a=L.DeleteParticularNode(a);
					if(a==-1)
						cout<<"\nNode not exist\n";
					else
						cout<<"\nDeleted element is :"<<a;
					break;
			case 7:cout<<"Enter the Ordered Linked list to be Merged(Press 0 for ending)\n";
					cin>>a;
					while(a)
					{
					   L1.Insertion(a);
					   cin>>a;
   					} 
   					L1.Display();
   					if(L1.count())
					{
				//		L1.BS();
						if(L.count())
   						{
						//	L.BS();
							L.Cover(L1);
						}
   						else
   						{
   						L=L1;	
						}
						cout<<"\nMerged ";
						L.Display();
					}
					else if(L.count())
					{
					//	L.BS();
						cout<<"\nMerged ";
						L.Display();
					}
					else  cout<<"\nBoth are Empty Linked Lists";
					L1.Remove();
					break;			
			default:cout<<"\n!!Wrong Choice!!";
		}
		cout<<"\nPress y/Y to continue:";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
}
