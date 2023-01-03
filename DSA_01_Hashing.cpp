//Employee Database using Hashing
#include<iostream>
#include<cstring>
using namespace std;
//creating a structure for Emplyee
struct emp{
 long int id, key;
 string name;
};
//creating Hash Table class
class HT{
public:
int size = 10;
emp table[10];
 HT(){
 for(int i = 0; i < 10; i++){
 table[i].key = -1;
 table[i].id = -1;
 table[i].name = " ";
 }
 }
 void insert();
 void deletes();
 void search();
 void display();
 int hash_function(int key){
 return (key%10);
 }
};
//Insertion in hash Table
void HT::insert(){
 int id;
 string name;
 cout << "ID : ";
 cin >> id;
 cout << "NAME : ";
 cin >> name;cout<<"\n";
 int index = hash_function(id);
 int c = index;
 int count=0;
 while(table[index].key != -1){
 index = (index + 1)%10;
 count++;
 }
 if(count==10){
 cout<<"The Table is full"<<endl;
 
 }
 table[index].id = id;
 table[index].name = name;
 table[index].key = c;
}
//Displaying Hash Table
void HT::display(){
 cout << " KEY " << " ID " <<" NAME " <<endl;
 for(int i=0;i<10;i++){cout<<" ";
 cout << table[i].key << " " << table[i].id <<" "<<table[i].name<< endl;
 }cout<<"\n";
}
void HT::search(){
 int sea,i;cout<<"Enter the ID : ";
 cin>>sea;cout<<"\n";
 for( i=0;i<10;i++){
 if(table[i].id==sea)
 break;
 }cout<<"NAME : "<<table[i].name;cout<<endl;
 cout<<"Key : "<<table[i].key;cout<<endl<<"\n";
 //Deleting element from hash table
}
void HT::deletes(){
 int sea,i;cout<<"Enter the ID : ";
 cin>>sea;cout<<"\n";
 for( i=0;i<10;i++){
 if(table[i].id==sea)
 break;
 }table[i].id=-1;
 table[i].name=" ";
 table[i].key=-1;
}
//Writing main
int main(){
 HT();
 HT s;
 while(true){
 int c;
 cout << "Enter your choice \n" << endl;
 cout << "1: Insert element into the table "<< endl;
 cout << "2: Display the table " << endl;
 cout << "3: search element from the key " << endl;
 cout << "4: Delete element at a key " << endl;
 cout << "0: Exit\n" << endl;
 cout << "choice : ";
 cin >> c;cout<<"\n";
 if(c==0){
 break;
 }
 else{
 switch(c){
 case 1:
 // cout<<"\nEnter the id and name: " << endl;
 s.insert();
 break;
 case 2:
 s.display();
 break;
 case 3:
 //s.deletes();
 s.search();
 break;
 case 4:
 s.deletes();
 break;
 }
 }
 }
 return 0;
}
