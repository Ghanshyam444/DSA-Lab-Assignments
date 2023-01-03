// # Assignment-8
// # Prim's Algorithm
// # MST Implementation
#include <iostream> 
using namespace std; 
#define V 5
 // Vertices
// # Minimum weight
int minValue(int Value[], bool Set[]) 
{ 
 long long int min = __INT64_MAX__; 
 int min_index; 
 for (int v = 0; v < V; v++) 
 if (Set[v] == false && Value[v] < min) 
 min = Value[v], min_index = v; 
 return min_index; 
} 
// # Print MST
int printMST(int parent[], int Graph[V][V]) 
{ 
 int wt = 0; 
 cout << " Edge | Weight\n"; 
 cout << "------------------\n"; 
 for (int i = 1; i < V; i++) 
 { 
 cout << " " << parent[i] << " - " << i << " | " <<
Graph[i][parent[i]] << " \n"; 
 wt = wt + Graph[i][parent[i]]; 
 } 
 return wt; 
} 
// # Prims Algorithm
void primMST(int Graph[V][V]) 
{ 
 int parent[V]; 
 int Value[V]; 
 bool Set[V]; 
 for (int i = 0; i < V; i++) 
 Value[i] = INT_MAX, Set[i] = false; 
 Value[0] = 0; 
 parent[0] = -1; // First node is always root of MST
 for (int count = 0; count < V - 1; count++) 
 { 
 int u = minValue(Value, Set); 
 Set[u] = true; 
 for (int v = 0; v < V; v++) 
 if (Graph[u][v] && Set[v] == false && Graph[u][v] <
Value[v]) 
 parent[v] = u, Value[v] = Graph[u][v]; 
 } 
 int wt = printMST(parent, Graph); 
 cout << "\n# Vertices = " << V << "\n\n# Edges = " << (V - 1) <<
"\n"; 
 cout << "\n# Minimum weight/ Cost  of ST: " << wt << endl; 
} 
// # Main Function 
int main() 
{ 
 // # Graph
 int Graph[V][V] = {{0, 2, 0, 6, 0}, 
 {2, 0, 3, 8, 5}, 
 {0, 3, 0, 0, 7}, 
 {6, 8, 0, 0, 9}, 
 {0, 5, 7, 9, 0}}; 
 cout << "\n# MST Implementation #" << endl; 
 cout << "\n# MST:\n\n "; 
 primMST(Graph); 
 cout << "\n"; 
 return 0; 
} 