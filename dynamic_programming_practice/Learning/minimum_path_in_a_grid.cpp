//finding the minimum cost path to reach m,n from 1,1 by using only 
//down and right moves  
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

#define ll long long int 
#define MAX 1e18
#define cinll(x) ll x;cin>>x;
#define pb(x) push_back(x);

using namespace std;

ll grid[1000][1000];
ll opp = 0;
//top - down approach using memoization
//time complexity O(n^2)
ll memo[1000][1000];
ll solvememo(ll m,ll n){
    opp++;
    if(m<0||n<0) return MAX;
    if(memo[m][n]!=-1) return memo[m][n];
    ll upcost = solvememo(m-1,n);
    ll leftcost = solvememo(m,n-1);
    if(min(upcost,leftcost)==MAX) leftcost = upcost = 0;
    ll cost = grid[m][n] +  min(upcost,leftcost);
    memo[m][n] = cost;
    return cost;
} 
//bottom up dp
ll solvedp(ll m,ll n){
    ll dp[1000][1000];
    memset(dp,-1,sizeof(dp));
    dp[0][0] = grid[0][0];
    for(ll i=1;i<n;i++) dp[0][i] = dp[0][i-1] + grid[0][i];
    for(ll i=1;i<m;i++) dp[i][0] = dp[i-1][0] + grid[i][0];
    for(ll i=1;i<m;i++){
        for(ll j=1;j<n;j++){
            dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}

int main(){
    cinll(m);cinll(n);
    memset(grid,-1,sizeof(grid));
    memset(memo,-1,sizeof(memo));
    for(ll i=0;i<m;i++){
        for(ll j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    cout<<solvememo(m-1,n-1)<<"  "<<solvedp(m,n);
    return 0;
} 