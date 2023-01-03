//Singly linked list
#include <iostream>
using namespace std;
//Creating a node structure
struct node
{
int data;
node *next;
};
//creating a class linked list
class Linked_list{
node*header = NULL ;
public:
void insertbeginning();
void insertmiddle();
void insertend();
void deletebeginning();
void deleteend();
void deletemiddle();
void print();
void reverse();
};
//inserting node at beginning
void Linked_list::insertbeginning()
{
 int n;
 cout<<"Enter the element to be inserted"<<endl;
 cin>>n;
 node *new_node;
 new_node = new node;
 new_node -> data = n;
 new_node -> next = header;
 header = new_node;
 cout<<"Node is inserted !"<<endl;
}
//inserting node in between
void Linked_list::insertmiddle()
{
 int i,n;
 node *p,*new_node;
 new_node = new node;
 node *store;
 p = header;
 cout<<"Enter the position at which new node is to inserted"<<endl;
 cin>>i;
 cout<<"Enter the data to be stored in the new node"<<endl;
 cin>>n;
 if(i==1)
 {
 insertbeginning();
 }
 else{
for(int j=1;j<i-1;j++)
 {
 p = p -> next;
 }
 new_node->next = p-> next;
 p->next = new_node;
 new_node ->data =n;
 }
}
//inserting node at end
void Linked_list::insertend()
{
 int n;
node *p,*new_node;
 new_node = new node;
 cout<<"Enter the data to be stored at last new node inserted"<<endl;
cin>>n;
 new_node = new node;
 p = header;
 while(p->next != NULL)
 {
 p = p->next;
 }
 p->next = new_node;
 new_node->next = NULL;
 new_node ->data = n;
}
//deleting node at beginning
void Linked_list::deletebeginning()
{
 node *p;
 p = new node;
 p = header;
 header = p->next;
 delete(p);
 cout<<"The first node is hence deleted !"<<endl;
}
//deleting node at end
void Linked_list::deleteend()
{
 
node *p;
 p = header;
 int count = 1;
 while (p->next != NULL)
 {
 count++;
 p = p->next;
 }
 node *newnode;
 newnode = header;
 if (count > 1)
 {
 while (newnode->next->next != NULL)
 {
 newnode = newnode->next;
 }
 delete newnode->next;
 newnode->next = NULL;
 cout << "deleted succesfully!!" << endl;
 }
 else
 deletebeginning();
 
}
//deleting node in between
void Linked_list::deletemiddle()
{
 int n,i,x;
 cout<<"Enter the position at which the node is deleted"<<endl;
 cin>>n;
 node *p,*q;
 p = header;
 q = NULL;
 for( i=0;i<n-1 && p;i++)
 {
 q = p;
 p = p->next ;
 }
 if(p)
 {
 q -> next = p-> next;
 x = p -> data ;
 delete p;
 }
 cout<<"The node hence deleted is "<<x<<endl;
}
//diplaying linked list
void Linked_list::print()
{
 if (header == NULL)
 {
 cout << "no link list in exictance:" << endl;
 }
 else
 {
 node *p;
 p = header;
 cout << "your node structure is:" << endl;
 while (p != NULL)
 {
 cout << p->data << " ";
 p = p->next;
 }
 cout << endl;
 }
}
//writing main
int main()
{
 Linked_list obj;
 do{
 cout<<"Enter the operation to be performed on the linked list"<<endl;
 cout<<"1] Insert at beginning \n2] Insert in between\n3] Insert at end of Linked list\n4] Delete the 
first node\n5] Delete in between\n6] Delete at end\n7]Print the linked list\n8] exit"<<endl;
 
 int n;
 cin>>n;
 switch(n)
 {
 case 1:
 obj.insertbeginning();
 break;
 case 2:
 obj.insertmiddle();
 break;
 case 3:
 obj.insertend();
 break;
 case 4:
 obj.deletebeginning();
 break;
 case 5:
 obj.deletemiddle();
 break;
 case 6:
 obj.deleteend();
 break;
 case 7:
 obj.print();
 break;
 case 8:
 exit(0);
 break;
 default:
 cout<<"Invalid Input !"<<endl;
 }
 }while(1);
}
