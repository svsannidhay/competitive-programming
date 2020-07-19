#include<iostream>
#define ll long long int
using namespace std;
int main(){
    string s1;
    string s2;
    cin>>s1>>s2;
    for(ll i=0;i<s1.length();i++){
        if(s1[i]!=s2[i]){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    return 0;
}