#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

#define ll long long int 
#define cinll(x); ll x;cin>>x;

using namespace std;

ll getBit(ll n,ll i){
    ll mask = 1<<i;
    ll bit = 0;
    if((n&mask)>0) bit = 1;
    return bit;
}

ll setBit(ll n,ll i){
    ll mask = (1<<i);
    ll ans = n|mask;
    return ans;
}

int main(){
    cinll(n);
    cinll(i);
    //cout<<getBit(n,i);
    n = setBit(n,i);
    cout<<n;
    return 0;
}