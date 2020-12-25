#include<iostream>
#include<vector>
#include<cstring>

#define ll long long int
#define pb(x) push_back(x); 
#define cinll(x) ll x;cin>>x;

using namespace std; 

//memoized solution 
ll memo[1000][1000];
ll solve_memo(ll n,vector<ll> &p,vector<ll> &w,ll i,ll wt){ 
    if(wt<=0||i>=n) return 0;
    if(memo[i][wt]!=-1) return memo[i][wt];
    memo[i][wt] = solve_memo(n, p, w, i + 1, wt);
    if(wt-w[i]>=0){
        memo[i][wt] = max(p[i] + solve_memo(n, p, w, i + 1, wt - w[i]),memo[i][wt]);
    }    
    return memo[i][wt];
}
//dp solution
ll solvedp(ll n,vector<ll> &p,vector<ll> &w,ll wt){
    ll dp[n+1][wt+1];
    memset(dp,0,sizeof(dp));
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=wt;j++){
            dp[i][j] = dp[i-1][j];
            if(j-w[i-1]>=0){
                
                dp[i][j] = max(dp[i][j],dp[i-1][j-w[i-1]]+p[i-1]);
            }
            
        }
        
    }
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=wt;j++){
            cout<<dp[i][j]<<" "; 
        }
        cout<<"\n";
    }
    return dp[n][wt];
}

int main(){
    cinll(n);cinll(wt);
    vector<ll> p;
    for(ll i=0;i<n;i++){
        cinll(x);
        p.pb(x);
    }
    vector<ll> w;
    for(ll i=0;i<n;i++){
        cinll(x);
        w.pb(x);
    }
    memset(memo,-1,sizeof(memo));
    cout<<solve_memo(n,p,w,0,wt)<<"\n";
    cout<<solvedp(n,p,w,wt);
    return 0;
}