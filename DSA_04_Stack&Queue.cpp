#include <iostream>
using namespace std;
//creating a node
class Node{
public:
int data;
Node* next;
};
//creating a class for Stack operation 
class Stack{
private:
Node* top;
public:
Stack();
~Stack();
void push(int x);
int pop();
int peek(int index);
int isEmpty();
int isFull();
int stackTop();
void menu();
void display();
};
//creating a class for Queue operations
class Queue{
private:
Node* front;
Node* rear;
public:
Queue();
~Queue();
void enqueue(int x);
int dequeue();
bool isEmpty();
void display();
void menu();
};
void Queue:: menu() //declaring menu for Queue operations
{
int c,n,x,m;
do{
cout<<"Enter the operations to perform on Queue\n1] Enqueue\n2] Dequeue \n3] 
Display\n4] Exit";
cin>>c;
switch(c)
{
case 1:
cout<<"Enter the number of inputs to be given"<<endl;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>x;
enqueue(x);
}
break;
case 2:
cout<<"The Popped Element is"<<dequeue();
break;
case 3:
display();
break;
case 4:
break;
}
}while(c!=4);
}
//function to display the stack
void Stack:: display() { 
struct Node* ptr;
if(top==NULL)
cout<<"stack is empty";
else {
ptr = top;
cout<<"Stack elements are: ";
while (ptr != NULL) {
cout<< ptr->data <<" ";
ptr = ptr->next;
}
}
cout<<endl;
}
//making menu for stack operations 
void Stack::menu()
{
int c,n,x,m;
Stack s;
do{
cout<<"Enter the operations to perform on Stack\n1] Push\n2] Pop\n3] 
Display\n4] Peek\n5] Exit\n";
cin>>c;
switch(c)
{
case 1:
cout<<"Enter the number of inputs to be given"<<endl;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>x;
push(x);
}
break;
case 2:
cout<<"The Popped Element is"<<pop();
break;
case 4:
cout<<"Enter the position at which peek is to be performed"<<endl;
cin>>m;
cout<<peek(m)<<endl;
break;
case 3:
display();
break;
case 5:
break;
}
}while(c!=5);
}
//constructor for stack class
Stack::Stack() {
top = NULL;
}
//destructor for stack class
Stack::~Stack() {
Node* p = top;
while (top){
top = top->next;
delete p;
p = top;
}
}
//push function for stack
void Stack::push(int x) {
Node* t = new Node;
if (t == NULL){
cout << "Stack Overflow!" << endl;
} else {
t->data = x;
t->next = top;
top = t;
}
}
//pop function for stack
int Stack::pop() {
Node* p;
int x = -1;
if (top == NULL){
cout << "Stack Underflow!" << endl;
} else {
p = top;
x = p->data;
top = top->next;
delete p;
}
return x;
}
//Checking if the stack is full or not
int Stack::isFull() {
Node* t = new Node;
int r = t ? 1 : 0;
delete t;
return r;
}
//checking if the stack is empty or not
int Stack::isEmpty() {
return top ? 0 : 1;
}
//Displaying the top element of the Stack
int Stack::stackTop() {
if (top){
return top->data;
}
return -1;
}
//peeking in stack from the top of the stack
int Stack::peek(int index) {
if (isEmpty()){
return -1;
} else {
Node* p = top;
for (int i=0; p != NULL && i<index-1; i++){
p = p->next;
}
if (p != NULL){
return p->data;
} else {
return -1;
}
}
}
//constructor for Queue class
Queue::Queue() {
front = NULL;
rear = NULL;
}
//Enqueue operation for Queue
void Queue::enqueue(int x) {
Node* t = new Node;
if (t == NULL){
cout << "Queue Overflow" << endl;
} else {
t->data = x;
t->next = NULL;
if (front == NULL){
front = t;
rear = t;
} else {
rear->next = t;
rear = t;
}
}
}
//Dequeue operation for Queue
int Queue::dequeue() {
int x = -1;
Node* p;
if (isEmpty()){
cout << "Queue Underflow" << endl;
} else {
p = front;
front = front->next;
x = p->data;
delete p;
}
return x;
}
//Checking if the queue is empty
bool Queue::isEmpty() {
if (front == NULL){
return true;
}
return false;
}
//Creating a destructor for Queue
Queue::~Queue() {
Node* p = front;
while (front){
front = front->next;
delete p;
p = front;
}
}
//displaying queue 
void Queue::display() {
Node* p = front;
while (p){
cout << p->data << flush;
p = p->next;
if (p != NULL){
cout << " <- " << flush;
}
}
cout << endl;
}
//writing the main function to perform operations
int main() {
int choice;
Stack st;
Queue q;
do{
cout<<"Enter your choice\n1] Stack \n2] Queue \n3] Exit\n";
cin>>choice;
//menu driven choices for operations on stacks and queue
switch(choice)
{
case 1:
st.menu();
break;
case 2:
q.menu();
break;
case 3:
exit(0);
break;
}
}while(choice!=3);
return 0;
}
