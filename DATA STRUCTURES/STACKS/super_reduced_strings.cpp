//problem statement:- https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/super-reduced-strings-303701dd/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define MOD 1000000007
using namespace std;
int main(){
    string s;
    fio;
    cin>>s;
    
    stack<char> c;
    char text = s[s.length()-1];
    c.push(text);
    for(ll i=s.length()-2;i>=0;i--){
        if(c.empty()==false){
            if(c.top()==s[i]){
                c.pop();
            }
            else{
                c.push(s[i]);
            }
        }
        else{
            c.push(s[i]);
        }
    }
    if(c.size()==0){
        cout<<"Empty String";
    }
    while(!c.empty()){
        cout<<c.top();
        c.pop();
    }
    
    return 0;
}
