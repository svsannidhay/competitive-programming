//https://leetcode.com/problems/single-number/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

#define ll long long int 
#define cinll(x); ll x;cin>>x;

using namespace std;

int main(){
    cinll(n)
    vector<ll> arr;
    for(ll i=0;i<n;i++){
        cinll(x);arr.push_back(x);
    } 
    ll ans = arr[0];
    for(ll i=1;i<n;i++) ans^= arr[i];
    cout<<ans<<" ";
    return 0;
}