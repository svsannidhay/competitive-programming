#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define ll long long int 
#define pb(x) push_back(x) 
#define cinll(x) ll x;cin>>x;
using namespace std;

//memoization (top - down)
ll cnt = 0;
ll memo[100][100];
ll maxProfit(vector<ll> bottles,ll be,ll en,ll year){
    cnt++;
    if(be>en){
        return 0;
    }
    if(memo[be][en] != -1){
        return memo[be][en];
    }
    ll q1 = bottles[be] * year + maxProfit(bottles,be+1,en,year+1);
    ll q2 = bottles[en] * year + maxProfit(bottles,be,en-1,year+1);
    memo[be][en] = max(q1,q2);
    return max(q1,q2);
}

//dp bottom up
ll maxProfitdp(vector<ll> bottles,ll n){
    ll dp[100][100];
    ll year = n;
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<n;i++){
        dp[i][i] = year * bottles[i];
    }
    year--;
    for(ll len =2;len<=n;len++){
        ll strt = 0;
        ll end = n-len;
        while(strt<=end){
            ll endwindow = strt + len -1;
            dp[strt][endwindow] = max(
                (bottles[strt]*year + dp[strt+1][endwindow] ),
                ( bottles[endwindow]*year + dp[strt][endwindow-1])
            );
            strt++;
        }
        year--;
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";  
        }
        cout<<"\n";
    }
    return dp[0][n-1];
}

int main(){
    cinll(n);
    vector<ll> bottles;
    for(ll i=0;i<n;i++){
        cinll(prices);
        bottles.pb(prices);
    }
    memset(memo,-1,sizeof(memo));
    ll ans = maxProfit(bottles,0,n-1,1);
    cout<<ans<<" "<<cnt; 
    cout<<"DP \n"<<maxProfitdp(bottles,n);
    return 0;
}

