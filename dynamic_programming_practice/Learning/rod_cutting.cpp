#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define ll long long int 
#define cinll(x) ll x;cin>>x;
#define pb(x) push_back(x)
#define MAX 1e18
using namespace std;
//memoization top-down
ll memo[10000];
ll opp = 0;
ll findans(vector<ll> &cost,ll totallen){
    opp++;
    if(totallen==0) return 0;
    ll ans = 0;
    if(memo[totallen]!=-1) return memo[totallen];
    for(ll len=1;len<=totallen;len++){
        ll profit  = cost[len] + findans(cost,totallen-len);
        ans = max(ans,profit);
    }
    memo[totallen] = ans;
    return ans;
}


//bottom up approach
ll findansdp(vector<ll> cost,ll n){
    ll dp[100000];
    memset(dp,0,sizeof(dp));
    dp[1] = cost[1];
   
    for(ll i=2;i<=n;i++){
        ll ans = 0;
        for(ll j=1;j<=i;j++){
            ans = max(ans,cost[j]+dp[i-j]);
        }
        dp[i] = ans;
    }
    return dp[n];
}

int main(){
    memset(memo,-1,sizeof(memo));
    vector<ll> cost;
    cinll(n);
    cost.pb(0);
    for(ll i=0;i<n;i++){
        cinll(c);
        cost.pb(c);
    }
    cout<<findansdp(cost,n)<<"\n";
    cout<<findans(cost,n)<<" "<<opp;
    return 0;
}