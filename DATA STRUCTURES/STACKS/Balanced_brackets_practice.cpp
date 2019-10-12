//problem statement:- https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/balanced-brackets-3-4fc590c6/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define MOD 1000000007
using namespace std;
int main(){
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
        stack<char> s;
        string str;
        cin>>str;
        for(int i=0;i<str.length();i++){
            if(char(str[i])=='('||char(str[i])=='['||char(str[i])=='{'){
                s.push(str[i]);
            }
            if(s.size()>=1){
                if(char(str[i])==')'){
                    if(s.top()=='('){
                        s.pop();
                    }
                }
                if(char(str[i])==']'){
                    if(s.top()=='['){
                        s.pop();
                    }
                }
                if(char(str[i])=='}'){
                    if(s.top()=='{'){
                        s.pop();
                    }
                }
            }
            
        }
        if(s.size()==0){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
    
    return 0;
}
