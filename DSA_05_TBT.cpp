//program to implement Threaded Binary Tree
#include <iostream>
using namespace std; 
//defining node structure
typedef struct node
{ 
public:
 int data; //data member
 int l_th; //left thread to check if it points to ancestor or child
 int r_th; //right thread to check if it points to ancestor or child
 node *left, *right;  //pointer to point to left and right child
} node; 
node *root, *dummy; //defining root node and dummy node
//class for Threaded Binary Tree
class TBT
{ 
public:
 TBT() //constructor for threaded binary tree
 { 
 root = NULL; 
 dummy = new node; //initializing dummy node with root
 dummy->left = dummy->right = NULL;  //defining left and right pointers 
 dummy->l_th = dummy->r_th = 0; //initializing left and right thread
 } 
 void insert(); //function for insertion
 void inOrder(); //function for inorder traversal
}; 
void TBT ::insert() //defining insert function
{ 
 node *nn; 
 nn = new node; //creating new node
 cout << "enter data : "; 
 //intializing new node 
 cin >> nn->data; 
 nn->l_th = nn->r_th = 0; 
 nn->left = nn->right = NULL; 
 if (root == NULL) //if tbt is empty
 { 
 root = nn; 
 root->left = root->right = dummy; //initializing root and dummy node
 dummy->left = root; 
 return; 
 } 
 else //if tbt not empty
 { 
 node *t, *p; 
 t = root; 
 p = NULL; 
 //finding the correct position for insertion
 while (t != NULL) //traversal till end
 { 
 p = t; 
 if (nn->data < t->data) 
 { 
 if (t->l_th == 1) 
 { 
 t = t->left; 
 } 
 else
 t = NULL; 
 } 
 else
 { 
 if (t->r_th == 1) 
 { 
 t = t->right; 
 } 
 else
 t = NULL; 
 } 
 } 
 if (nn->data < p->data) 
 { 
 nn->left = p->left; 
 nn->right = p; 
 p->l_th = 1; 
 p->left = nn; 
 } 
 else
 { 
 nn->right = p->right; 
 nn->left = p; 
 p->right = nn; 
 p->r_th = 1; 
 } 
 return; 
 } 
} 
//defining function for inorder traversal
void TBT ::inOrder() 
{ 
 node *t; 
 t = root; 
 while (1) 
 { 
 while (t->l_th == 1) //checking if node points to child 
 { 
 t = t->left; 
 } 
 cout << t->data << " "; 
 while (t->r_th == 0) //checking if node points to ancestor
 { 
 if (t->right == dummy) 
 { 
 return; 
 } 
 else
 { 
 t = t->right; 
 cout << t->data << " "; 
 } 
 } 
 t = t->right; 
 } 
} 
//defining main function
int main() 
{ 
 TBT t; 
 int choice; 
 do
 { //writing the menu
 cout << "********MENU************\n"; 
 cout << "1.create\n"; 
 cout << "2.display assend\n"; 
 cout << "3.exit\n"; 
 cout << "************************\n"; 
 cin >> choice; 
 switch (choice) 
 { 
 case 1: //option for insertion
 t.insert(); 
 break; 
 case 2: //option for inorder traversal
 cout << "Inorder Data "; 
 t.inOrder(); 
 break; 
 case 3: 
 exit(0); 
 default: 
 cout << "wrong choice"; 
 break; 
 } 
 cout << "\n"; 
 } while (1); 
 return 0; 
} 