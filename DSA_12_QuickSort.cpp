#include <iostream>
#include <iomanip>
using namespace std; 
int partition(int A[], int low, int high); //partition function
void quick_sort(int A[], int low, int high); //quick sort function
//defining main function
int main() 
{ 
 int i = 0, n, arr[100]; 
 cout << "Enter the number of employees:"; 
 cin >> n; 
 cout << endl; 
 cout << "Enter the salary of " << n << " employees" << endl; 
 for (i = 0; i < n; i++) 
 { 
 cin >> arr[i]; 
 } 
 cout << endl
 << "The array before sorting," << endl; 
 for (i = 0; i < n; i++) //displaying the array before sort
 { 
 cout << arr[i] << " "; 
 } 
 cout << endl; 
 quick_sort(arr, 0, n - 1); //calling quick sort function 
 cout << endl
 << "Top 5 performers are," << endl; 
 int count = 0; 
 for (i = n - 1; i >= 0; i--) 
 { 
 if (count == 5) 
 { 
 break; 
 } 
 cout << arr[i] << " "; 
 count++; 
 } 
 return 0; 
} 
//Quick sort function defination
void quick_sort(int A[], int low, int high) 
{ 
 int part; 
 if (low < high) 
 { 
 part = partition(A, low, high); //calling partition function
 quick_sort(A, low, part - 1); //sorting in first half 
 quick_sort(A, part + 1, high); //sorting in second half 
 } 
} 
//defining partition function 
int partition(int A[], int low, int high) 
{ 
 int i, j, temp; 
 int pivot = A[low]; 
 i = low + 1; 
 j = high; 
 do
 { 
 while (A[i] <= pivot) 
 { 
 i++; 
 } 
 while (A[j] > pivot) 
 { 
 j--; 
 } 
 if (i < j) //swapping function
 { 
 temp = A[i]; 
 A[i] = A[j]; 
 A[j] = temp; 
 } 
 } while (i < j); 
 //final swapping 
 temp = A[low]; 
 A[low] = A[j]; 
 A[j] = temp; 
 return j; 
}