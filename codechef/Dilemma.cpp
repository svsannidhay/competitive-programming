//problem statement :- https://www.codechef.com/problems/CHEFDIL
//easy one again (game theory)
// always go for the generalisation in  case of game theory
#include<iostream>
#include<string>
#include<vector>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main(){
    int t;
    cin>>t;
    for(long long int i=1;i<=t;i++){
        string s;
        cin>>s;
        int count1 = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                count1++;
            }
        }
        if(count1%2==0){
            cout<<"LOSE"<<"\n";
        }
        else{
            cout<<"WIN"<<"\n";
        }
        
        
    }
}
