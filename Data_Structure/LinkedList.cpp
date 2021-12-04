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
		  	if(head) for(Node *current=head;current!=0;current=current->next,c++);
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
		  	Node  *cur,*end=0,*temp;
		  	if(head)
			{
			for(cur=head;;cur=cur->next)
		  	{
		  		for(temp=head;temp->next!=end;temp=temp->next);
				int value=cur->data;
					cur->data=temp->data;
					temp->data=value;
				if(cur==temp || cur->next==temp) break;
				end=temp;
			}
			}
		  }
		 	 void Concatenate(SLL L)
			{
				tail->next=L.head;
				tail=L.tail;
				L.head=L.tail=0;
			}
			void operator +(SLL L)
			{
				Concatenate(L);
			}
			 void BS()
   			{
   			 int i,j,c=0;
   			 Node *temp,*temp2;
   			 int cnt=count();
			 for(temp=head;temp!=0;temp=temp->next)
			 {
			    c=0;
			    i=0;
	 		  for(temp2=head;i<cnt-j-1;temp2=temp2->next)
	 		  {
	  			if(temp2->data > temp2->next->data)
	  			 {
	  				int a=temp2->data;
	  				    temp2->data=temp2->next->data;
	  				    temp2->next->data=a;
	  				c++;
				 }
				  i++;
	  		 }
	  		 j++;
	  		  cnt--;
	 			 if(c==0)
				   break;
     		 }
    		}
  		  SLL DeleteEvenPos()
		  {
		  	SLL L;
		  	int i=1;
		  	Node *current,*temp;
		  	for(current=head;current!=0;i++)
			{
				temp=current;
				if(i%2!=0)
				{
					L.addToTail(current->data);
				}
				current=current->next;
				delete temp;
			}
			return L;
		  }
		  int countEvenPos()
		  {
		  	int i,count=0;
		  	for(Node *current=head;current!=0;current=current->next,i++)
				if(i%2==0)	count++;
		  	return count;
		  }
		  int countEvenVal()
		  {
		  	int count=0;
		  	for(Node *current=head;current!=0;current=current->next)
				if(current->data%2==0)	count++;
		  	return count;
		  }
		  SLL DeleteAllOccurances(int el)
		  {
		  	SLL L;
		  	Node *current,*temp;
		  	for(current=head;current!=0;)
			{
				temp=current;
				if(current->data != el)
					L.addToTail(current->data);
				current=current->next;
				delete temp;
			}
			return L;
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
		  void Cover(SLL L)
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
};
int main()
{
	SLL L,L1;
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
		cout<<"\n5)To delete head\n6)To delete tail\n7)To delete Particular node\n";
		cout<<"8)To Search an element \n9)To Reverse List \n10)To concatenate another Linked List\n";
		cout<<"11)To Sort Linked List\n12)To delete even Pos Nodes\n13)To count even pos nodes\n";
		cout<<"14)To count even value nodes\n15)Delete all occurances of given value\n16)Merge with Recursion\n";
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
			case 7: cout<<"\nEnter value of node to be deleted:";
					cin>>a;
					a=L.DeleteParticularNode(a);
					if(a==-1)
						cout<<"\nNode not exist\n";
					else
						cout<<"\nDeleted element is :"<<a;
					break;
			case 8: cout<<"\nEnter value of node to be searched:";
					cin>>a;
					if(L.Search(a))
						cout<<"\nElement Found\n";
					else
						cout<<"\nElement Not Found\n";
					break;
			case 9:	if(L.count())
						L.Reverse();
					else  cout<<"\nEmpty Linked List";
					break;
			case 10:cout<<"Enter the Linked list to be concatenated(Press 0 for ending)\n";
					cin>>a;
					while(a)
					{
					   L1.addToTail(a);
					   cin>>a;
   					 } 
   					if(L.count()||L1.count())
						L+L1;
					else  cout<<"\nBoth are Empty Linked Lists";
					break;
			case 11:if(L.count())
						L.BS();
					else  cout<<"\nEmpty Linked List";
					break;
			case 12:if(L.count())
						L=L.DeleteEvenPos();
					else  cout<<"\nEmpty Linked List";
					break;
			case 13:if(L.count())
						cout<<"\nNumber of even position nodes in Linked List:"<<L.countEvenPos();
					else  cout<<"\nEmpty Linked List";
					break;		
			case 14:if(L.count())
						cout<<"\nNumber of even value nodes in Linked List:"<<L.countEvenVal();
					else  cout<<"\nEmpty Linked List";
					break;
			case 15:if(L.count())
					{
						cout<<"\nEnter value of node whose all occurances has to be deleted:";
						cin>>a;
						L=L.DeleteAllOccurances(a);
					}
					else  cout<<"\nEmpty Linked List";
					break;	
			case 16:cout<<"Enter the Linked list to be Merged(Press 0 for ending)\n";
					cin>>a;
					while(a)
					{
					   L1.addToTail(a);
					   cin>>a;
   					 } 
   					if(L1.count())
					{
						L1.BS();
						if(L.count())
   						{
							L.BS();
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
						L.BS();
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
