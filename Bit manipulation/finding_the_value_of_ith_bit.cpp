#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<bitset>
#define ll long long int 
#define cinll(x); ll x;cin>>x;

using namespace std;

bool isOdd(ll n){
    return (n&1);
}
ll getBit(ll n,ll i){
    return ((n&(1<<i))>0)?1:0;
}
ll setBit(ll n,ll i){
    return (n|(1<<i));
}
void clearBit(ll &n,ll i){
    ll mask = ~(1<<i);
    n = (n&mask);
}

void updateBit(ll &n,ll i,ll v){
    clearBit(n,i);
    n = n | (v<<i);
}
void clearLastIBits(ll &n,ll i){
    ll mask = (-1<<(i+1));
    n = (n&mask);
}

void clearRangeIJ(ll &n,ll l,ll r){
    ll mask1 = (-1<<(r+1));
    ll mask2 = ((1<<l)-1);
    ll mask = (mask2 | mask1);
    n = (n & mask);
}

int main(){
    cinll(n);
    cinll(i);
    cinll(j);
    clearRangeIJ(n,i,j);
    cout<<n<<"\n";
    return 0; 
}