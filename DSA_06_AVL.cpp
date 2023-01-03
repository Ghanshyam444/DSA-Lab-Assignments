#include <iostream>
using namespace std; 
//defining node structure
typedef struct node
{ 
int data; //data member
int height; //height
node *left; //left pointer
node *right; //right pointer
} node; 
node *root = NULL; //initializing root node
//defining a class tree
class tree
{ 
public:
int getheight(node *n) //function returning height of tree
{ 
if (n == NULL) //if emty tree
return 0; 
return n->height; 
} 
int max(int a, int b) //find maximum of two values 
{ 
return (a > b) ? a : b; 
} 
//function for creating a node
node *createnode(int data) 
{ 
node *nn = new node; //making new node
nn->data = data; //giving data
nn->left = NULL; 
nn->right = NULL; 
nn->height = 1; //initializing height as one
return nn; 
} 
int getbalancefactor(node *n) //function to get balance factor
{ 
if (n == NULL) //if tree is empty
return 0; 
return (getheight(n->left) - getheight(n->right)); //calculation of 
balance factor
} 
//Right - Right Rotation
node *rightrotate(node *y) 
{ 
node *x = y->left; //pointing to left subtree
node *t2 = x->right; //pointing to right subtree
x->right = y; 
y->left = t2; 
y->height = max(getheight(y->right), getheight(y->left)); //getting max 
height of left subtree
x->height = max(getheight(x->right), getheight(x->left)); //getting max 
height of right subtree
return x; 
} 
//Left - Left Rotation
node *leftrotate(node *x) 
{ 
node *y = x->right; //pointing to right subtree
node *t2 = y->left; //pointing to left subtree
y->left = x; 
x->right = t2; 
y->height = max(getheight(y->right), getheight(y->left)); //getting max 
height of left subtree
x->height = max(getheight(x->right), getheight(x->left)); //getting max 
height of right subtree
return y; 
} 
//Creating a new node with node pointer and data
node *create(node *node, int data) 
{ 
if (node == NULL) //if tree is empty
return createnode(data); 
if (data < node->data) 
node->left = create(node->left, data); 
else if (data > node->data) 
node->right = create(node->right, data); 
else // Equal keys not allowed
return node; 
int bf = getbalancefactor(node); 
if (bf > 1 && data < node->left->data) 
return rightrotate(node); 
// Right Right Case
if (bf < -1 && data > node->right->data) 
return leftrotate(node); 
// Left Right Case
if (bf > 1 && data > node->left->data) 
{ 
node->left = leftrotate(node->left); 
return rightrotate(node); 
} 
// Right Left Case
if (bf < -1 && data < node->right->data) 
{ 
node->right = rightrotate(node->right); 
return leftrotate(node); 
} 
return node; 
} 
//function for inorder traversal
void inorder(node *root) 
{ 
if (root != NULL) //if root isn't equal to null
{ 
inorder(root->left); //printing left child
cout << root->data << " "; //printing data
inorder(root->right); //printing right child
} 
} 
//function to display tree 
void display() 
{ 
int ch; 
node *temp = root; 
cout << "DISPLAYING ELEMENTS IN ASCENDING ORDER(inorder traversal):"; 
inorder(temp); 
} 
//function to search into the tree
void search() 
{ 
int d; 
cout << "ENTER DATA TO BE SEARCHED:"; 
cin >> d; 
node *temp = root, *parent; 
while (temp != NULL) 
{ 
if (temp->data == d) 
{ 
break; 
} 
else
{ 
parent = temp; 
if (d < temp->data) 
{ 
temp = temp->left; 
} 
else
{ 
temp = temp->right; 
} 
} 
} 
if (temp == NULL) 
{ 
cout << "ELEMENT NOT FOUND\n"; 
} 
else
{ 
cout << "ELEMENT FOUND\n"; 
} 
} 
}; 
//defining main function 
int main() 
{ 
int ch, data; 
tree t; 
while (1) 
{ 
cout <<
"\nENTER:\n1.CREATE\n2.DISPLAY\n3.SEARCH\n4.EXIT\nCHOICE:"; 
cin >> ch; 
switch (ch) 
{ 
case 1: 
cout << "ENTER NODE VALUE:"; 
cin >> data; 
root = t.create(root, data); 
break; 
case 2: 
t.display(); 
break; 
case 3: 
t.search(); 
break; 
case 4: 
return 0; 
default: 
cout << "INVALID INPUT!!!!"; 
break; 
} 
} 
}