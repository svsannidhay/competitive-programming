#include<iostream>
#include<vector>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull unsigned long long int
#define ll long long int
using namespace std;
int main(){
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll s;
        cin>>s;
        ll w1,w2,w3;
        cin>>w1>>w2>>w3;
        ll moves = 0;
        if(w1+w2+w3 <= s){
            moves = 1;
        }
        else{
            if((w1+w2 <= s)||(w2 +w3 <= s)){
                moves = 2;
            }
            else{
                moves = 3;
            }
        }
        cout<<moves<<"\n";
    }
    return 0;
}
