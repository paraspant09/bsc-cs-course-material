#include<iostream>
#include<stack>
using namespace std;

// node structure
typedef struct tree_node {
   int value;
   struct tree_node *left, *right;
}node;

// create a new node
node *getNewNode(int value) {
   node *new_node = new node;
   new_node->value = value;
   new_node->left = NULL;
   new_node->right = NULL;
   return new_node;
}

// create the tree
node *createTree() {
   node *root = getNewNode(31);
   root->left = getNewNode(16);
   root->right = getNewNode(52);
   root->left->left = getNewNode(7);
   root->left->right = getNewNode(24);
   root->left->right->left = getNewNode(19);
   root->left->right->right = getNewNode(29);
   return root;
}

// inorder traversal of a tree
void inorderTraversal(node *ptr) {
   if(ptr == NULL)
      return;
   else {
      inorderTraversal(ptr->left);
      cout<<ptr->value<<"\t";
      inorderTraversal(ptr->right);
   }
}

void inorderIterative(node *ptr) {
    if (!ptr) return;
    stack<node *> st;
    do {
        while (ptr) {
            st.push(ptr);
            ptr = ptr->left;
        }
        ptr = st.top(); st.pop();
        cout << ptr->value << " ";
        ptr = ptr->right;
    } while (ptr || !st.empty());
}

// preorder traversal of a tree
void preorderTraversal(node *ptr) {
   if(ptr == NULL)
      return;
   else {
      cout<<ptr->value<<"\t";
      preorderTraversal(ptr->left);
      preorderTraversal(ptr->right);
   }
}

void preorderIterative(node *ptr) {
    if (!ptr) return;
    stack<node *> st;
    st.push(ptr);
    while (!st.empty()) {
        ptr = st.top(); st.pop();
        cout << ptr->value << " ";
        if (ptr->right) st.push(ptr->right);
        if (ptr->left) st.push(ptr->left);
    }
}

// postorder traversal of a tree
void postorderTraversal(node *ptr) {
   if(ptr == NULL)
      return;
   else {
      postorderTraversal(ptr->left);
      postorderTraversal(ptr->right);
      cout<<ptr->value<<"\t";
   }
}

void postorderIterative(node *ptr) {
    if (!ptr) return;
    stack<node *> st1, st2;
    st1.push(ptr);
    while (!st1.empty()) {
        ptr = st1.top(); st1.pop();
        st2.push(ptr);
        if (ptr->left) st1.push(ptr->left);
        if (ptr->right) st1.push(ptr->right);
    }
    while (!st2.empty()) {
        ptr = st2.top(); st2.pop();
        cout << ptr->value << " ";
    }
}

// main
int main() {
   node *root = createTree();
   cout<<"\nInorder traversal :-\n";
   inorderTraversal(root);
   cout << endl;
   inorderIterative(root);
   cout<<"\n\nPreorder traversal :- \n";
   preorderTraversal(root);
   cout << endl;
   preorderIterative(root);
   cout<<"\n\nPostorder traversal :- \n";
   postorderTraversal(root);
   cout << endl;
   postorderIterative(root);
   cout<<endl;
   return 0;
}
