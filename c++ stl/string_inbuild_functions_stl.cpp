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
//EXAMPLE:-
/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
//bool lexicographical_compare(iter1 beg1, iter1 end1, iter2 beg2, iter2 end2)
using namespace std; 
  
// Compares two strings by checking if  
// which of the two concatenations causes 
// lexicographically smaller string. 
bool compare(string a, string b) 
{ 
    return (a+b < b+a); 
} 
  
string lexSmallest(string a[], int n) 
{ 
    // Sort strings using above compare() 
    sort(a, a+n, compare); 
  
    // Concatenating sorted strings 
    string answer = ""; 
    for (int i = 0; i < n; i++) 
        answer += a[i]; 
  
    return answer; 
} 
   
// Driver code 
int main() 
{   
    int n1,n2,n3;
    fio;
    string str1,str2,str3;
    cin>>n1>>n2>>n3;
    cin>>str1;
    cin>>str2;
    cin>>str3;
    string s[1];
    s[0] = str2;
    //s[1] = str2;
    //s[1] = str3;
    int n = sizeof(s)/sizeof(s[0]);
    
    string string1,string2,string3;
    string1.append(str1);
    string1.append(str3);
    string2.append(str1);
    string2.append(lexSmallest(s, n));
    string2.append(str3);
    /*
    vector<char> first;
    for(int i=0;i<string1.length();i++){
        first.push_back(string1[i]);
    }
    vector<char> second;
    for(int i=0;i<string2.length();i++){
        second.push_back(string2[i]);
    }
    */
    
    if( lexicographical_compare(string1.begin(), string1.end(), string2.begin(), string2.end()))
    {
        //cout<<string1;
        string3 = string1;
    }
    else{
        //cout<<string2;
        string3 = string2;
    }
    //sort(str2.begin(),str2.end());
    //cout<<str2;
    sort(str2.begin(), str2.end()); 
  
    // Using unique() method 
    auto res = unique(str2.begin(), str2.end());
    //cout<<str2<<"\n";
    /*
    for(auto i=str2.begin();i!=(res-2);i++){
        string string4;
        string4.append(str1);
        char c = *i;
        char d = *i+1;
        char e = *i+2;
        string4 += c;
        string4 += d;
        string4 += e;
        string4.append(str3);
        /*
        vector<char> first;
        for(int i=0;i<string4.length();i++){
            first.push_back(string4[i]);
        }
        vector<char> second;
        for(int i=0;i<string3.length();i++){
        second.push_back(string3[i]);
        }
        */
      /*
        if( lexicographical_compare(string4.begin(), string4.end(), string3.begin(), string3.end()))
        {
            //cout<<string1;
            string3 = string4;
        }
        else{
            //cout<<string2;
            string3 = string3;
        }
    
        
    }
    */
    for(auto i=str2.begin();i!=(res-1);i++){
        string string4;
        string4.append(str1);
        char c = *i;
        char d = *(i+1);
        string4 += c;
        string4 += d;
        string4.append(str3);
        /*
        vector<char> first;
        for(int i=0;i<string4.length();i++){
            first.push_back(string4[i]);
        }
        vector<char> second;
        for(int i=0;i<string3.length();i++){
        second.push_back(string3[i]);
        }
        */
        
        if( lexicographical_compare(string4.begin(), string4.end(), string3.begin(), string3.end()))
        {
            //cout<<string1;
            string3 = string4;
        }
        else{
            //cout<<string2;
            string3 = string3;
        }
    
        
    }
    for(auto i=str2.begin();i!=res;i++){
        string string4;
        string4.append(str1);
        char c = *i;
        string4 += c;
        string4.append(str3);
        /*
        vector<char> first;
        for(int i=0;i<string4.length();i++){
            first.push_back(string4[i]);
        }
        vector<char> second;
        for(int i=0;i<string3.length();i++){
        second.push_back(string3[i]);
        }
        */
        
        if( lexicographical_compare(string4.begin(), string4.end(), string3.begin(), string3.end()))
        {
            //cout<<string1;
            string3 = string4;
        }
        else{
            //cout<<string2;
            string3 = string3;
        }
    
        
    }
    
    
    
    
    
    
    
    //cout << lexSmallest(s, n);
    //cout<<str1<<str3;
    cout<<string3;
    return 0; 
} 
