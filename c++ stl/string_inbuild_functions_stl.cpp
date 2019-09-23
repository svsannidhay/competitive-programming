#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    string str = "aaaaabbbbbb"; 
    sort(str.begin(), str.end()); 
  
    // Using unique() method 
    auto res = unique(str.begin(), str.end());    
  
    cout << string(str.begin(), res) 
         << endl;
    string string1,string2;
    string1 = "abcdef";
    string2 = "Iojdsbajhb";
    string string3;
    if( lexicographical_compare(string1.begin(), string1.end(), string2.begin(), string2.end()))
    {
        //cout<<string1;
        string3 = string1;
    }
    else{
        //cout<<string2;
        string3 = string2;
    }    
    cout<<string3;   //lexicographically smallest string;
} 
