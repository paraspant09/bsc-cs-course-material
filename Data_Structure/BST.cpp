#include<iostream>
using namespace std;
class Node
{
	int data;
	Node *left; 
	Node *right;      
	public:Node(int val,Node *ptr=0,Node *ptr2=0)
	      {
	      	data=val;
	      	left=ptr;
	      	right=ptr2;
		  }
	friend class BST;
};
template <class Y> class Queue
{
  	Node<Y> *front, *rear;
  	public:Queue()
	      {
	      	front=rear=0;
	      }
  	      void addToTail(Y el)
  	      {
  	      	if(rear)
  	      	{
		    Node<Y> *temp=new Node<Y>(el);
  	      	rear->next=temp;
			rear=temp;
		    }
  	      	else
  	      	   front=rear=new Node<Y>(el);
		  }
		   Y DeletionFromHead()
		  {
		  	if(front)
		  	{
		  		Node<Y> *temp=front;
		  	    Y value=front->data;
		  		if(front==rear)
		  		    rear=0;
		  		front=front->next;
		  		delete temp;
		  		return value;
			}
			return NULL;
		  }
		  void Display()
		  {
		  	if(front)
		  	{
			cout<<"\nQueue using Linked List is:";
		  	for(Node<Y> *current=front;current!=0;current=current->next)
		  	{
		  	 	cout<<current->data<<" ";
			}
			}
			else
			cout<<"\nEmpty Queue\n";
		  }
     		void Enque(Y el)
			{
				addToTail(el);
   			}
   			Y Deque()
   			{
   			Y el;
   			el=DeletionFromHead();
   			return el;
   			}
   			bool isempty()
			{
				if(front==0)
				  return true;
				  return false;
			}
};
class BST
{
  	Node *root;
  	public:BST()
	      {
	      	root=0;
	      }
	      void Insertion(int el)
	      {
	      	Node *temp=new Node(el);
	      	if(root)
	      	{
	      		Node *cur=root,*prev;
	      		while(cur)			//find leaves which is prev and just smaller than element to insert
	      		{
	      			prev=cur;
	      	  		if(cur->data >= el)
	      	  			cur=cur->left;
	      	  		else if(cur->data < el)
	      	  			cur=cur->right;
				}
				if(prev->data > el)		//put it in its proper place
					prev->left=temp;
				else
					prev->right=temp;
			}
			else
				root=temp;
		  }
		  void Inorder(Node *cur)
		  {
		  	if(cur)
		  	{
		  		Inorder(cur->left);
		  		cout<<cur->data<<" ";
		  		Inorder(cur->right);
			}
		  }
		  int Traverse(Node *cur,int &ct)
		  {
		  	if(cur)
		  	{
		  		Traverse(cur->left,ct);
		  		ct++;
		  		Traverse(cur->right,ct);
			}
		  }
		  int TraverseForLeaves(Node *cur,int &ct)
		  {
		  	if(cur)
		  	{
		  		TraverseForLeaves(cur->left,ct);
		  		if(!cur->right && !cur->left)	ct++;
		  		TraverseForLeaves(cur->right,ct);
			}
		  }
		  int TraverseForIN(Node *cur,int &ct)
		  {
		  	if(cur)
		  	{
		  		TraverseForIN(cur->left,ct);
		  		if(!(!cur->right && !cur->left))	ct++;
		  		TraverseForIN(cur->right,ct);
			}
		  }
		  int CountAllNodes()
		  {
		  	int count=0;
		  	Traverse(root,count);
		  	return count;
		  }
		  int CountLeaves()
		  {
		  	int count=0;
		  	TraverseForLeaves(root,count);
		  	return count;
		  }
		  int CountIN()
		  {
		  	int count=0;
		  	TraverseForIN(root,count);
		  	return count;
		  }
		  void Preorder(Node *cur)
		  {
		  	if(cur)
		  	{
		  		cout<<cur->data<<" ";
		  		Preorder(cur->left);
		  		Preorder(cur->right);
			}
		  }
		  void Postorder(Node *cur)
		  {
		  	if(cur)
		  	{
		  		Postorder(cur->left);
		  		Postorder(cur->right);
		  		cout<<cur->data<<" ";
			}
		  }
		  bool Search(int el,Node *cur)
		  {
		  	if(!cur)
		  		return false;
		  	if(el<cur->data)
		  		return Search(el,cur->left);
			else if(el>cur->data)
				return Search(el,cur->right);
			else
				return true;
		  }
		  bool SearchBST(int el)
		  {
		  	return Search(el,root);
		  }
		 /* void Only()
		  {
		  	root=new Node(3,new Node(4,new Node(1),new Node(2)),new Node(5));
		  }*/
		  void DisplayPre()
		  {
		  	cout<<"\nPreOrder BST is:";
		  	Preorder(root);
		  	cout<<endl;
		  }
		  void DisplayPost()
		  {
		  	cout<<"\nPostOrder BST is:";
		  	Postorder(root);
		  	cout<<endl;
		  }
		  void DisplayIn()
		  {
		  	cout<<"\nInOrder BST is:";
		  	Inorder(root);
		  	cout<<endl;
		  }
		  int Height(Node *cur)	//LRV where visiting gives the height of the node acc. to the bigger height of node's left and right
		  {
		  	if(cur)
		  	{
		  		int l=Height(cur->left);
		  		int r=Height(cur->right);
		  		if(l >= r)
		  			return l+1;
		  		else
		  			return r+1;
			}
			else
				return 0;
		  }
		  int HeightBST()
		  {
		  	return Height(root);
		  }
		  void Post(Node *cur,Node *&cur2)
		  {
		  	if(cur)
		  	{
		  		cur2=new Node(cur->data);
		  		Post(cur->left,cur2->left);
		  		Post(cur->right,cur2->right);
			}
		  }
		  BST COPY()
		  {
		  	BST ob;
		  	Post(root,ob.root);
		  	return ob;
		  }
		  void PostMirror(Node *cur,Node *&cur2)
		  {
		  	if(cur)
		  	{
		  		cur2=new Node(cur->data);
		  		PostMirror(cur->left,cur2->right);
		  		PostMirror(cur->right,cur2->left);
			}
		  }
		  BST Mirror()
		  {
		  	BST ob;
		  	PostMirror(root,ob.root);
		  	return ob;
		  }
		  void BFT()
		  {
		  	Queue<Node<int>*> Q;
		  	if(root)
		  	{
		  		Node *cur=root;
		  		Queue Q;
		  		Q.Enque(cur);
		  		while(!Q.isempty())
		  		{
		  			cur=Q.Deque();
		  			cout<<cur->data<<" ";
		  			if(cur->left)
		  				Q.Enque(cur->left);
		  			if(cur->right)
		  				Q.Enque(cur->right);
				}
			}
		  }
};
int main()
{
	BST ob,ob2,ob3;
	ob.Insertion(4);
	ob.Insertion(5);
	ob.Insertion(7);
	ob.Insertion(1);
	ob.Insertion(3);
	ob.Insertion(4);
	ob.Insertion(2);
//	ob.Only();
	ob.DisplayPre();
	ob.DisplayPost();
	ob.DisplayIn();
	if(ob.SearchBST(6))
		cout<<"\nFound";
	else
		cout<<"\nNot Found";
	cout<<endl<<"\nLeaves are:"<<ob.CountLeaves();
	cout<<endl<<"\nNo. of Nodes are:"<<ob.CountAllNodes();
	cout<<endl<<"\nNo. of Internal Nodes(Total Nodes-Leaves) are:"<<ob.CountIN();
	cout<<endl<<"\nHeight of BST:"<<ob.HeightBST();
	ob2=ob.COPY();
	
	ob2.DisplayPre();
	ob2.DisplayPost();
	ob2.DisplayIn();
	
	cout<<endl;
	ob3=ob2.Mirror();
	
	ob3.DisplayPre();
	ob3.DisplayPost();
	ob3.DisplayIn();
	
	cout<<"\nLevel By Level Traversal:";
	ob.BFT();
}
