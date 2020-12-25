#include<iostream>
#include<vector>
#include<cstring>

#define ll long long int
#define cinll(x) ll x;cin>>x;
#define cins(s) string s;cin>>s;

using namespace std;

ll memo[1000][1000];

ll lcs_memo(string &s1,string &s2,ll i,ll j){
    if(i>=s1.length()||j>s2.length()) return 0;
    if(memo[i][j]!=-1) return memo[i][j];
    if(s1[i]==s2[j]){
        memo[i][j] = 1 + lcs_memo(s1,s2,i+1,j+1);
        return memo[i][j];
    }
    memo[i][j] = max(lcs_memo(s1,s2,i+1,j),lcs_memo(s1,s2,i,j+1));
    return memo[i][j];
}

ll lcs_dp(string &s1,string &s2){
    ll dp[1000][1000];
    memset(dp,0,sizeof(dp));
    for(ll i=1;i<=s1.length();i++){
        for(ll j=1;j<=s2.length();j++){
            if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    for(ll i=0;i<=s1.length();i++){
        for(ll j=0;j<=s2.length();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return dp[s1.length()][s2.length()];
}

int main(){
    cins(s1);cins(s2);
    memset(memo,-1,sizeof(memo));
    cout<<lcs_memo(s1, s2,0,0)<<"\n";
    cout<<lcs_dp(s1,s2);
    return 0;
}    