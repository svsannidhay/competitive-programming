/*
PROBLEM STATEMENT :-

You are given 2 32-bit numbers , N and M , and two positions i and j. Write a method to set all bits between i and j in N equal to M (M becomes a substring of N located at i ending at j)

*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>

#define ll long long int 
#define cinll(x) ll x;cin>>x;
using namespace std;

void solve(ll &n,ll m,ll i,ll j){
    // clearing all the bits in n from i to j
    ll mask = ((-1<<(j+1)) | ((1<<i)-1));
    n = (n & mask);
    m = m<<i;
    bitset<64> mk(m);
    n = n | m;
}

int main(){
    cinll(n);cinll(m);cinll(i);cinll(j);
    solve(n,m,i,j);
    cout<<n;
    return 0;
}