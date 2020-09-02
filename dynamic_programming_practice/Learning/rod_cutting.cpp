// You are given a rod of length n and cost selling each length from 
// 1 to n . Your task is find the maximum profit you can make by 
// partitioning and selling the rod.
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

#define ll long long int 
#define cinll(x) ll x;cin>>x;
#define pb(x) push_back(x);
#define MAX 1e18

using namespace std;

//top - down using memoization 
// time complexity brute force O(n^n);
// time complexity dp O(n^2)
ll memo[100000];
ll solvememo(vector<ll> cost,ll len){
    if(len<=0) return 0;
    if(memo[len]!=-1) return memo[len];
    ll ans = 0;
    for(ll i = 1;i<=len;i++){
        ans = max(ans,cost[i]+solvememo(cost,len-i));
    }    
    memo[len] = ans;
    return ans;
}
//bottom-up
ll solvedp(vector<ll> cost,ll n){
    ll dp[1005];
    memset(dp,0,sizeof(dp));
    for(ll len=1;len<=n;len++){
        for(ll cut = 1;cut<=len;cut++){
            dp[len] = max(dp[len],cost[cut] + dp[len-cut]);
        }
    }
    return dp[n];
}

int main(){
    cinll(n);
    memset(memo,-1,sizeof(memo));
    vector<ll> cost;cost.pb(0);
    for(ll i=1;i<=n;i++){
        cinll(x);cost.pb(x);
    }
    cout<<solvememo(cost,n)<<" "<<solvedp(cost,n)<<"\n";
    return 0;
}