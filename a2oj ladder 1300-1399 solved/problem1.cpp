#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#define ll long long int
using namespace std;
int main(){
    ll n;
    cin>>n;
    ll indexmax = 0;
    ll valmax = 0;
    ll indexmin = 0;
    ll valmin = INT_MAX;
    for(ll i=0;i<n;i++){
        ll x;cin>>x;
        if(x>valmax){
            indexmax = i;
            valmax = x;
        }
        if(x<=valmin){
            indexmin = i;
            valmin = x;
        }
    }
    ll ans = 0;
    ans += indexmax;
    ans += (n-indexmin-1);
    //cout<<indexmax<<" "<<indexmin<<"\n";
    if(indexmax>indexmin){
        ans--;
    }
    cout<<ans<<"\n";
    return 0;
}

