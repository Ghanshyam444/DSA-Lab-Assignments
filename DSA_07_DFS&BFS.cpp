#include <iostream>
using namespace std; 
//defining structure of queue
struct Queue
{ 
 int size; //size of queue
 int front,rear; //front and rear pointers
 int *Q; //pointer to queue structure
}; 
//function to create Queue with it's size 
void create(struct Queue *q,int size) 
{ 
 q->size = size; //giving size to queue
 q->front = 0; //initializing with front as zero
 q->rear = 0; //initializing with rear as zero
 q->Q = new int[size]; //making dynamic queue
} 
//function to enqueue into the queue
void enqueue(struct Queue *q,int x) 
{ 
 if( ( (q->rear + 1) % q->size) == q->front) 
 { 
 cout<<"FULL\n"; 
 } 
 else
 { 
 q->rear = (q->rear + 1)%q->size; 
 q->Q[q->rear] = x; 
 } 
} 
//function to dequeue from queue
int dequeue(struct Queue *q) 
{ 
 int x; 
 if(q->front == q->rear) 
 { 
 cout<<"EMPTY\n"; 
 } 
 else
 { 
 q->front = (q->front + 1)%q->size; 
 x = q->Q[q->front]; 
 } 
 return x; 
} 
//function to check if queue is empty
int isEmpty(struct Queue q) 
{ 
 if(q.front == q.rear) 
 { 
 return 1; 
 } 
 else
 { 
 return 0; 
 } 
 
} 
//function for Breadth First Search
void BFS(int G[][7],int start,int n) 
{ 
 int i = start,u; 
 struct Queue q; 
 create(&q,n); 
 int visited[7] = {0}; //creating a vist array
 cout<<i<<" "; 
 visited[i] = 1; 
 enqueue(&q,i); 
 while (!isEmpty(q)) 
 { 
 u = dequeue(&q); 
 for (int v = 1; v <= n; v++) 
 { 
 if (G[u][v] == 1 && visited[v] == 0) 
 { 
 cout<<v<<" "; 
 visited[v] = 1; 
 enqueue(&q,v); 
 } 
 } 
 } 
} 
//function for Depth First Search
void DFS(int G[][7],int start,int n) 
{ 
 static int visited[7] = {0}; 
 if(visited[start] == 0) 
 { 
 cout<<start<<" "; 
 visited[start] = 1; 
 for (int v = 1; v <= n; v++) 
 { 
 if(G[start][v] == 1 && visited[v] == 0) 
 { 
 DFS(G,v,n); 
 } 
 } 
 } 
} 
//defining main function
int main() 
{ 
    //passing adjacency matrix as graph
int G[7][7]={{0,0,0,0,0,0,0}, 
 {0,0,1,1,0,0,0}, 
 {0,1,0,0,1,0,0}, 
 {0,1,0,0,1,0,0}, 
 {0,0,1,1,0,1,1}, 
 {0,0,0,0,1,0,0}, 
 {0,0,0,0,1,0,0}}; 
cout<<"For given graph\n"; 
cout<<"BFS is\n"; 
BFS(G,3,7); 
cout<<"\nDFS is\n"; 
DFS(G,4,7); 
return 0; 
}