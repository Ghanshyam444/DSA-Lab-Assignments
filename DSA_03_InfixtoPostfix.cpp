#include <iostream>
using namespace std;
// Writing code for checking precedence
int chechpresidence(char a)
{
if (a == '+' || a == '-')
{
return 1; //giving lowest priority
}
else if (a == '*' || a == '/')
{
return 2; //giving decent priority
}
else if (a == '^')
{
return 3; //giving highest priority
}
else
{
return -1;
}
}
// Defining a class Stack including stack operations
class stack
{
public:
int top = -1;
string st;
stack()
{}
void push(char exp)
{
top++;
st[top]=exp;
}
void pop()
{
st[top]='\0';
top--;
}
int empty()
{
if(st[0]=='\0')
return 0;
else
return 1;
}
friend void infix_postfix(string ); //defining a friend function to access 
variables
};
// Function for converting infix to postfix
void infix_postfix(string str)
{
stack s;
string result;
for (int i = 0; i < str.length(); i++)
{
char c = str[i];
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
&& c <= '9'))
result += c;
else if (c == '(')
{
s.push('(');
}
else if(c==')')
{
while(s.st[s.top]!='(')
{
result+=s.st[s.top];
s.pop();
}
s.pop();
}
else
{
while(s.empty()
&&(chechpresidence(str[i])<=chechpresidence(s.st[s.top]))) //checking 
conditions
{
result+=s.st[s.top];
s.pop();
}
s.push(c);
}
}
while(s.empty()) //traversing in stack
{
result+=s.st[s.top];
s.pop();
}
cout<<"Postfix expression is: "<<result<<endl;
}
int main()
{
string exp;
cout<<"enter the infix expression to be converted:"<<endl;
cin>>exp;
infix_postfix(exp);
return 0;
}
