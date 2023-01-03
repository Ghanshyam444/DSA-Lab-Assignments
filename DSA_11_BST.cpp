#include <iostream>
#include <iomanip>
using namespace std; 
//defining structure of tnode
struct tnode
{ 
 int data; //data member of tnode
 tnode *left = NULL, *right = NULL; //initializing pointers
}; 
//class for Binary Search Tree
class tree
{ 
public:
 tnode *root = NULL; //initializing root node
 void create(); //function for creation
 void search(); //function for search
 void display_ascend(); //display in ascending order
 void inorder(tnode *q); //inorder traversal
 tnode *deletenode(tnode *root, int key) //delete node funcion
 { 
 tnode *temp; 
 if (root == NULL) //if tree is empty
 { 
 cout << "NO key exists" << endl; 
 return NULL; 
 } 
 else if (key < root->data) 
 { 
 root->left = deletenode(root->left, key); 
 } 
 else if (root->data < key) 
 { 
 root->right = deletenode(root->right, key); 
 } 
 else
 { 
 if (root->left == NULL && root->right == NULL) //if it is leaf node
 { 
 temp = root; 
 root = NULL; 
 delete temp; 
 } 
 else if (root->right == NULL) //no right child
 { 
 temp = root; 
 root = root->left; 
 temp->left = NULL; 
 delete temp; 
 } 
 else if (root->left == NULL) //no left child
 { 
 temp = root; 
 root = root->right; 
 temp->left = NULL; 
 delete temp; 
 } 
 else
 { 
 temp = root; 
 temp = temp->right; 
 while (temp->left != NULL) 
 { 
 temp = temp->left; 
 } 
 root->data = temp->data; 
 root->right = deletenode(root->right, temp->data); 
 } 
 return root; 
 } 
 } 
}; 
void tree::create() //defining function for creation of Binary Search Tree
{ 
 tnode *nn = new tnode; //creating new node
 tnode *cn, *parent; //declaring pointers
 cn = root; 
 cout << "enter data in tree:" << endl; 
 cin >> nn->data; 
 if (cn == NULL) //if tree is empty
 { 
 root = nn; 
 } 
 else
 { 
 while (cn != NULL) //traversal till last leaf node
 { 
 parent = cn; 
 if (cn->data > nn->data) 
 { 
 cn = cn->left; 
 } 
 else
 { 
 cn = cn->right; 
 } 
 } 
 if (parent->data > nn->data) 
 { 
 parent->left = nn; 
 } 
 else
 { 
 parent->right = nn; 
 } 
 } 
} 
void tree::display_ascend() //display in ascending order 
{ 
 tnode *cn = root; 
 if (cn == NULL) 
 { 
 cout << "binary tree is not in existance" << endl; 
 } 
 else
 { 
 inorder(cn); 
 } 
 cout << endl; 
} 
void tree::inorder(tnode *root) //inorder traversal of tree
{ 
 tnode *cn = root; 
 if (cn != NULL) 
 { 
 inorder(cn->left); 
 cout << cn->data << " "; 
 inorder(cn->right); 
 } 
} 
//searching in the Binary Search Tree
void tree::search() 
{ 
 tnode *cn = root; 
 int m; 
 cout << "enter data to search:" << endl; 
 cin >> m; 
 while (cn != NULL) 
 { 
 if (cn->data == m) 
 { 
 cout << "record found" << endl; 
 break; 
 } 
 else if (cn->left != NULL || cn->right != NULL) 
 { 
 if (cn->data > m) 
 { 
 cn = cn->left; 
 } 
 else
 { 
 cn = cn->right; 
 } 
 } 
 else
 { 
 cn = NULL; 
 } 
 } 
 if (cn == NULL) 
 { 
 cout << "record not found" << endl; 
 } 
} 
//defining main function
int main() 
{ 
 tree t; 
 int choice, key, ch; 
 while (1) 
 { 
 cout << endl
 << "menu" << endl
 << "1)insert" << endl //insertion option
 << "2)search" << endl //searching option
 << "3)display" << endl //display option
 << "4)delete node" << endl //deletion option
 << "5)exit" << endl; //exit option
 cin >> choice; 
 cout << endl; 
 switch (choice) 
 { 
 case 1: 
 do
 { 
 t.create(); 
 cout << "Enter 1 to add more elements, else 0" << endl; 
 cin >> ch; 
 } while (ch == 1); 
 break; 
 case 2: 
 t.search(); 
 break; 
 case 3: 
 t.display_ascend(); 
 break; 
 case 4: 
 cout << "enter the key to delete:" << endl; 
 cin >> key; 
 t.deletenode(t.root, key); 
 break; 
 case 5: 
 return 0; 
 break; 
 default: 
 cout << "wrong choice" << endl; 
 break; 
 } 
 } 
 return 0; 
} 
