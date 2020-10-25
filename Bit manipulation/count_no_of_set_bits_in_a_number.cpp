#include<iostream>
#include<vector>
#include<bitset>

#define ll long long int 
#define cinll(x) ll x;cin>>x;

using namespace std;

//M1 :- complexity :- O(logN)
ll countSetBits(ll n){
    ll ans = 0;
    while(n>0){
        ans += (n&1);
        n = n>>1;
    }
    return ans;
}
//M2 :- complexity : O(no of set bits)
ll countSetBitsFast(ll n){
    ll ans = 0;
    while(n>0){
        n = n&(n-1); //removes last set bit
        ans++;
    }
    return ans;
}
int main(){
    cinll(n);
    cout<<countSetBits(n)<<" "<<countSetBitsFast(n)<<" ";
    cout<<__builtin_popcount(n)<<"\n";
    return 0;
}