#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define ll long long int 
#define cinll(x) ll x;cin>>x;
#define MAX 1e18
#define pb(x) push_back(x)
using namespace std;
//Complexity O(n^2) as no of dynamics present are n^2 
//using memoization top-down 
ll memo[1000][1000];
ll grid[1000][1000];
ll opp = 0;

ll minTravleCost(ll i,ll j){
    opp++;
    if(i<0||j<0) return MAX;
    if(memo[i][j]!=-1) return memo[i][j];
    ll upcost = minTravleCost(i-1,j);
    ll leftcost = minTravleCost(i,j-1);
    if(min(upcost,leftcost)==MAX) upcost = leftcost = 0;
    ll cost = grid[i][j] +  min(upcost,leftcost);
    memo[i][j] = cost;
    return cost;
}

//bottom-up dp
ll mintravelCostdp(ll n){
    ll dp[1000][1000];
    memset(dp,-1,sizeof(dp));
    dp[0][0] = grid[0][0];
    for(ll i=1;i<n;i++) dp[0][i] = dp[0][i-1] + grid[0][i]; 
    for(ll i=1;i<n;i++) dp[i][0] = dp[i-1][0] + grid[i][0];

    for(ll i=1;i<n;i++){
        for(ll j =1;j<n;j++){
            dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n-1][n-1];
}

int main(){
    cinll(n);
    memset(memo,-1,sizeof(memo));
    memset(grid,-1,sizeof(grid));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    //cout<<minTravleCost(n-1,n-1)<<" "<<opp;
    cout<<mintravelCostdp(n);
    return 0;
}