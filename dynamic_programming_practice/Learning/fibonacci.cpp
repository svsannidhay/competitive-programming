//Find the nth fibonacci number in Linear time
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define ll long long int 
#define cinll(x) ll x;cin>>x;
#define pb(x) push_back(x)

using namespace std;

//memoized solution top-down approach
//time complexity before memoization O(2^n)
//time complexity after memoization O(n)
ll memo[100005];
ll fibonaccimemo(ll n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(memo[n]!=-1) return memo[n];
    memo[n]  = fibonaccimemo(n-1) + fibonaccimemo(n-2);
    return memo[n];
}

//bottom - up dynamic programming solution 
//time complexity O(n)
ll fibonaccidp(ll n){
    ll dp[100005];
    dp[0] = 0;dp[1] = 1;
    for(ll i=2;i<=n;i++) dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

int main(){
    cinll(n);
    memset(memo,-1,sizeof(memo));
    cout<<fibonaccimemo(n)<<" "<<fibonaccidp(n);
    return 0;
}