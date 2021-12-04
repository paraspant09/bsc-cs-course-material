#include<iostream>
using namespace std;
#define COUNT 10  
class Node{
	public:
	int data;
	Node *left;
	Node *right;
	Node *parent;
	int color;	//0 black and 1 red
	Node(Node *lt,Node *rt,Node *prnt,int clr,int dta){
		left=lt;
		right=rt;
		parent=prnt;
		color=clr;
		data=dta;
	}
};
class RBTree{
	private:Node* root;
	public: void LeftRotate(Node *X){
				Node *Y=X->right;
				if(Y){
					if(Y->left){
						Y->left->parent=X;
						X->right=Y->left;
					}
					else{
						X->right=0;
					}
					if(X != root){
						if(X->parent->right == X)
							X->parent->right=Y;
						else
							X->parent->left=Y;
							
						Y->parent=X->parent;
					}
					else{
						root=Y;
						Y->parent=0;
					}
					Y->left=X;
					X->parent=Y;
				}
			}
			void RightRotate(Node *X){
				Node *Y=X->left;
				if(Y){
					if(Y->right){
						Y->right->parent=X;
						X->left=Y->right;
					}
					else{
						X->left=0;
					}
					if(X != root){
						if(X->parent->right == X)
							X->parent->right=Y;
						else
							X->parent->left=Y;
							
						Y->parent=X->parent;
					}
					else{
						root=Y;
						Y->parent=0;
					}
					Y->right=X;
					X->parent=Y;
				}
			}
			void RBTreeInsertionFixUp(Node *X){
				if(X->parent->color == 0)
					return;
				else{
					Node *Grandparent,*Uncle;
					Grandparent=X->parent->parent;
					if(Grandparent->right == X->parent)
						Uncle=Grandparent->left;
					else
						Uncle=Grandparent->right;
					
					if(!Uncle || Uncle->color == 0)		//black
					{
						Grandparent->color=1;
						
						if(Grandparent->left == X->parent){
							if(X->parent->left == X){
								X->parent->color=0;
								RightRotate(Grandparent);
							}
							else
							{
								X->color=0;
								LeftRotate(X->parent);
								RightRotate(Grandparent);
							}
						}
						else
						{
							if(X->parent->right == X){
								X->parent->color=0;
								LeftRotate(Grandparent);
							}
							else
							{
								X->color=0;
								RightRotate(X->parent);
								LeftRotate(Grandparent);
							}
						}
					}
					else		//red
					{
						X->parent->color=0;
						Uncle->color=0;
						if(Grandparent != root){
							Grandparent->color=1;
							RBTreeInsertionFixUp(Grandparent);
						}
					}
				}
			}
			void RBInsertion(int el){
				if(root){
					Node *temp=root,*prev;
					while(temp){
						prev=temp;
						if(el < temp->data)
							temp=temp->left;
						else
							temp=temp->right;
					}
					Node *newNode=new Node(0,0,prev,1,el);
					if(el < prev->data)
						prev->left=newNode; //red color
					else
						prev->right=newNode;
						
					RBTreeInsertionFixUp(newNode);
				}
				else
					root=new Node(0,0,0,0,el); //black color
			}
			
			Node* Find(int el){
				if(root){
					Node *temp=root;
					while(temp){
						if(el < temp->data)
							temp=temp->left;
						else if(el > temp->data)
							temp=temp->right;
						else
							break;
					}
					if(temp)
						return temp;
				}
				return 0;
			}
			void LeafDelete(Node *p){
				if(p->parent->right==p)
					p->parent->right=0;
				else
					p->parent->left=0;
				delete p;
			}
			void RBTreeDeletionFixUp(Node *p,int i){
				if(p==root)	return;		//Case2
				if(p->color == 1 && i==0){		//Case1
					LeafDelete(p);
					return;
				}
				else
				{
					Node *Sib;
					if(p->parent->right==p)
						Sib=p->parent->left;
					else
						Sib=p->parent->right;
					
					if(Sib){
						if(Sib->color==0){
							if(	!Sib->left || Sib->left->color==0)
							{
								if(	!Sib->right || Sib->right->color==0)
								{
									Sib->color=1;
									if(p->parent->color == 1){			//Case3
										p->parent->color=0;
									}
									else
										RBTreeDeletionFixUp(p->parent,1);
								}
								else if(Sib->right && p->parent->right==p){		//Case5
									swap(Sib->color,Sib->right->color);
									LeftRotate(Sib);
								}
							}
							else if(!Sib->right || Sib->right->color==0){		//Case5
								if(Sib->left && p->parent->left==p){
									swap(Sib->color,Sib->left->color);
									RightRotate(Sib);
								}
							}
							//Case-6
							Node *newSib;
							if(p->parent->right && p->parent->right==p)
								newSib=p->parent->left;
							else
								newSib=p->parent->right;
								
							if(newSib && newSib->color==0){
								if(p->parent->right==p){
									if(p->parent->left->left && p->parent->left->left->color==1){
										swap(p->parent->color,p->parent->left->color);
										p->parent->left->left->color=0;
										RightRotate(p->parent);
									}
								}
								else if(p->parent->right->right && p->parent->right->right->color==1){
									swap(p->parent->color,p->parent->right->color);
									p->parent->right->right->color=0;
									LeftRotate(p->parent);
								}
							}
						}
						else{	//Case4
							swap(p->parent->color,Sib->color);
							if(p->parent->right==p)
								RightRotate(p->parent);
							else
								LeftRotate(p->parent);
							RBTreeDeletionFixUp(p,1);
						}
					}
				}
				if(i==0)	LeafDelete(p);
			}
			Node* Predecessor(Node *p){
				Node *q=p->left;
				while(q->right){
					q=q->right;
				}
				return q;
			}
			void Delete(Node *p){
				if(!p->left){
					if(!p->right){
						if(p==root){
							root=0;
						}
						else{
							RBTreeDeletionFixUp(p,0);
						}
					}
					else{
						p->data=p->right->data;
						Delete(p->right);
					}
				}
				else{
					Node *temp=Predecessor(p);
					p->data=temp->data;
					Delete(temp);
				}
			}
			void RBDeletion(int el){
				Node *Todelete=Find(el);
				if(Todelete)
					Delete(Todelete);
				else
					cout<<"\n"<<el<<" Not Found.\n";
			}
			void Print(Node *temp,int space){
				if(temp){
					space += COUNT;  
					Print(temp->right,space);
					// Print current node after space count  
					cout<<endl;  
    				for (int i = COUNT; i < space; i++)  
     				   cout<<" ";
					cout<<"("<<temp->data<<" "<<temp->color<<")";
					Print(temp->left,space);
					//space count increase by 10 for everytime there is a left or(+) right call before visiting that node
					//adding the previous space count
					//while visiting that node print apporpriate spaces
				}
			}
			void PrintTree(){
				cout<<endl;
				Print(root,0);
				cout<<"\n-----------------------------------------------------";
			}
};
int main(){
	RBTree ob;
	ob.RBInsertion(15);
	ob.PrintTree();
	ob.RBInsertion(30);
	ob.PrintTree();
	ob.RBInsertion(65);
	ob.PrintTree();
	ob.RBInsertion(35);
	ob.PrintTree();
	ob.RBInsertion(50);
	ob.PrintTree();
	ob.RBInsertion(70);
	ob.PrintTree();
	ob.RBInsertion(55);
	ob.PrintTree();
	ob.RBInsertion(68);
	ob.PrintTree();
	ob.RBInsertion(80);
	ob.PrintTree();
	ob.RBInsertion(90);
	ob.PrintTree();
	cout<<"\n\nDELETION\n\n";
	ob.RBDeletion(55);
	ob.PrintTree();
	ob.RBDeletion(30);
	ob.PrintTree();
	ob.RBDeletion(90);
	ob.PrintTree();
	ob.RBDeletion(80);
	ob.PrintTree();
	ob.RBDeletion(50);
	ob.PrintTree();
	ob.RBDeletion(35);
	ob.PrintTree();
	ob.RBDeletion(15);
	ob.PrintTree();
	ob.RBDeletion(65);
	ob.PrintTree();
}
