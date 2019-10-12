Skip to content
Search or jump to…

Pull requests
Issues
Marketplace
Explore
 
@svsannidhay 
0
00svsannidhay/competitive-programming
 Code Issues 3 Pull requests 0 Projects 0 Wiki Security Insights Settings
competitive-programming/c++ stl/stack_stl.cpp
@svsannidhay svsannidhay Create stack_stl.cpp
d5dc0f3 14 minutes ago
101 lines (85 sloc)  1.93 KB
  
#include <iostream> 
#include <stack> 
using namespace std; 
  
void showstack(stack <int> s) 
{ 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
} 
  
int main () 
{ 
    stack <int> s; 
    s.push(10); 
    s.push(30); 
    s.push(20); 
    s.push(5); 
    s.push(1); 
  
    cout << "The stack is : "; 
    showstack(s); 
  
    cout << "\ns.size() : " << s.size(); 
    cout << "\ns.top() : " << s.top(); 
  
  
    cout << "\ns.pop() : "; 
    s.pop(); 
    showstack(s); 
  
    return 0; 
} 
#include <stack> 
#include <iostream> 
using namespace std; 
  
int main() 
{ 
        // stack container declaration 
    stack<int> mystack1; 
    stack<int> mystack2; 
      
       // pushing elements into first stack 
    mystack1.push(1); 
    mystack1.push(2); 
    mystack1.push(3); 
    mystack1.push(4); 
      
       // pushing elements into 2nd stack 
    mystack2.push(3); 
    mystack2.push(5); 
    mystack2.push(7); 
    mystack2.push(9); 
  
        // using swap() function to swap elements of stacks 
    mystack1.swap(mystack2); 
  
        // printing the first stack 
    cout<<"mystack1 = "; 
     while (!mystack1.empty()) { 
        cout<<mystack1.top()<<" "; 
        mystack1.pop(); 
    } 
  
        // printing the second stack 
    cout<<endl<<"mystack2 = "; 
    while (!mystack2.empty()) { 
        cout<<mystack2.top()<<" "; 
        mystack2.pop(); 
    } 
    return 0; 
} 
// CPP program to illustrate 
// Implementation of emplace() function 
#include <iostream> 
#include <stack> 
using namespace std; 
  
int main() { 
  stack<int> mystack; 
  mystack.emplace(1); 
  mystack.emplace(2); 
  mystack.emplace(3); 
  mystack.emplace(4); 
  mystack.emplace(5); 
  mystack.emplace(6); 
  // stack becomes 1, 2, 3, 4, 5, 6 
  
  // printing the stack 
  cout << "mystack = "; 
  while (!mystack.empty()) { 
    cout << mystack.top() << " "; 
    mystack.pop(); 
  } 
  return 0; 
} 
© 2019 GitHub, Inc.
Terms
Privacy
Security
Status
Help
Contact GitHub
Pricing
API
Training
Blog
About
