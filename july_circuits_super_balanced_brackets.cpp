//problem statement:- https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/superbalancedbracket-75edd495/
#include<iostream>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
int main(){
    int t;
    fio;
    cin>>t;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        int count=0;
        for(int i=(s.length()/2)-1;i>=0;i--){
            if(s[i]=='('){
                count++;
            }
        }
        cout<<count*2;
        cout<<"\n";
    }
}
