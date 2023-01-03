//writing a program for doubly linked list operations
#include<iostream>
using namespace std;
// Constructing Node
struct node{
int data;
struct node *next,*prev;
};
// Creating Class for Doubly Linked List
class Doubly_Linked_List{
struct node *head,*end,*t,*new_node;
public :
Doubly_Linked_List(){ //Defining a constructor
head=0;
end=0;
}
// Creating New Node
void create_node(){
new_node= new struct node;
cout<<"Enter the data : ";
cin>>new_node->data;
new_node->next=0;
new_node->prev=0;
}
// Creationg Doubly Linked List
void create_list(){
int choice=1;
while(choice==1){ 
create_node();
if(head==0){
head=end=new_node;
}else{
new_node->prev=end;
end->next=new_node;
end=new_node;
}
cout<<"Do you want to add (1-Yes 2-No) : ";
cin>>choice;
}
}
// Displaying Doubly Linked List
void display(){
t=head;
while(t != 0){ //traversing the linked list
cout<<t->data<<" ";
t=t->next;
}
}
// Function for inserting data at beginning
void insert_at_begining(){
create_node();
head->prev=new_node;
new_node->next=head;
head=new_node;
}
// Function for inserting data at end
void insert_at_end(){
create_node();
end->next=new_node;
new_node->prev=end;
end=new_node;
}
// Function for inserting data after given postion
void insert_after_data(int x){
int flag=0;
t=head;
while(t != 0){ //traversing in the linked list
if(x== t->data){ //checking the conditions
flag=1;
break;
}
t=t->next; 
}
if(flag==1){
create_node(); //creating node
if(end->data == x){
insert_at_end(); //inserting at end;
}else{
new_node->prev=t;
new_node->next=t->next;
t->next->prev=new_node;
t->next=new_node;
}
}else{ //condtition if key is not present;
cout<<"Data not present"<<endl; 
}
}
// Function for inserting data before given postion
void insert_before_data(int x){
int flag=0;
t=head;
while(t != 0){
if(x== t->data){ //checiking the conditions 
flag=1;
break;
}
t=t->next; //traversing condition
}
if(flag==1){
create_node(); //creating a node
if(head->data==x){
insert_at_begining(); //inserting at beginning
}else{
new_node->next=t;
new_node->prev=t->prev;
t->prev->next=new_node;
t->prev=new_node;
}
}else{
cout<<"Data not present"<<endl;
}
}
// Function for Deleting data from beginning
void delete_At_begining(){
head=t;
head=head->next;
head->prev=0;
delete t;
cout<<"Entered Data deleted successfully"<<endl;
}
// Function for Deleting data from end
void delete_at_end(){
end=t;
end=end->prev;
end->next=0;
delete t;
cout<<"Entered Data deleted successfully"<<endl;
}
// Function for deleting data
void delete_data(int x){
int flag;
t=head;
while(t != 0){
if(x== t->data){
flag=1;
break;
}
t=t->next;
}
if(flag==1){
if(t==head){
delete_At_begining();
}else if(t==end){
delete_at_end();
cout<<"Entered Data deleted successfully"<<endl;
}else{
t->next->prev=t->prev;
t->prev->next=t->next;
delete t;
cout<<"Entered Data deleted successfully"<<endl;
}
}else{
cout<<"Data not present"<<endl;
}
}
//function for searching a key in the linked list
void search()
{
int flag = 1,key;
cout<<"Enter the element you wish to search\n";
cin>>key;
struct node *p;
p = head;
while (p != NULL) //traversing the linked list
{
if(key == p->data) //condition for element to be found
{
cout<<"Element Found\n";
flag = 0;
break;
}
p=p->next; 
}
if (flag)
{
cout<<"Element Not Found\n";
}
}
};
//defining and calling functions from main;
int main(){
int data , choice=1;
Doubly_Linked_List number;
while(choice == 1){
int menu;
 //displaying the menu
cout<<"** 1.Create Doubly linked list**"<<endl;
cout<<"** 2.Display whole linked list**"<<endl;
cout<<"** 3.Insert at begining**"<<endl;
cout<<"** 4.Insert at end**"<<endl;
cout<<"** 5.Insert after Data**"<<endl;
cout<<"** 6.Insert before Data**"<<endl;
cout<<"** 7.Delete Data**"<<endl;
cout<<"** 8.Search Element**"<<endl;
cout<<"Enter choice : ";
cin>>menu;
 //Creating a menu for operations on linked list
switch(menu){
case 1: //Create Doubly linked list
number.create_list();
break;
case 2: //Display whole linked list
number.display();
break;
case 3: //Insert at beginning
number.insert_at_begining();
break;
case 4: //Insert at end
number.insert_at_end();
break;
case 5: //Insert after any data
cout<<"Enter number in linked list : ";
cin>>data;
number.insert_after_data(data);
break;
case 6: //Insert before data
cout<<"Enter number in linked list : ";
cin>>data;
number.insert_before_data(data);
break;
case 7: //delete data;
cout<<"Enter the number you want to delete : ";
cin>>data;
number.delete_data(data);
break;
case 8: //Searching an data element in the linked list
number.search();
break;
default:
cout<<"Enter valid option"<<endl;
break;
}
 cout<<"Do you want to go to main menu (1-Yes 2-No) : ";
cin>>choice;
 }
return 0;
}
