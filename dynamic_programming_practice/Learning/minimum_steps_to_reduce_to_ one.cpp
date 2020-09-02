//Problem statement
/*
    Given a  number you need to return minimum number of operations
    required to reduce this number to 1
    operation are of three types 
    ->division by 3 if divisible
    ->division by 2 if divisible 
    ->reduce by 1
    brute force compexity :- O(3^n)

*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define ll long long int 
#define cinll(x) ll x; cin>>x;
#define MAX 1e18
#define pb(x) push_back(x)
using namespace std;

//memoized solution top-down 
ll memo[100005];
ll solvememo(ll n){
    if(n==1) return 0;
    if(memo[n]!=-1) return memo[n];
    ll div3 = MAX;ll div2 = MAX;ll minus1 = MAX;
    if(n%3==0) div3 = 1 + solvememo(n/3);
    if(n%2==0) div2 = 1 + solvememo(n/2);
    minus1 = 1 + solvememo(n-1);
    memo[n] = min(div3,min(div2,minus1));
    return memo[n];
}   

//bottom up solution pure dp
ll solvedp(ll n){
    ll dp[100005];
    memset(dp,-1,sizeof(dp));
    dp[1] = 0;dp[2] = 1;dp[3] = 1;
    for(ll i=4;i<=n;i++){
        ll div3 = MAX;ll div2 = MAX;ll minus1 = MAX;
        if(i%3==0) div3 = 1 + dp[i/3];
        if(i%2==0) div2 = 1 + dp[i/2];
        minus1 = 1 + dp[i-1];
        dp[i] = min(div3,min(div2,minus1));
    }
    return dp[n];
}

int main(){
    memset(memo,-1,sizeof(memo));
    cinll(n);
    cout<<solvememo(n)<<" "<<solvedp(n)<<"\n";
    return 0;
}
