#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define ll long long int 
#define cinll(x) ll x;cin>>x;
#define pb(x) push_back(x);
using namespace std;

//bottom - up approach 
ll findans(string s1,string s2){
    ll dp[s1.length()+1][s2.length()+1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 0;
    for(ll i=1;i<=s2.length();i++)  dp[0][i] = dp[0][i-1] + 1;
    for(ll i=1;i<=s1.length();i++)  dp[i][0] = dp[i-1][0] + 1;

    for(ll i=1;i<=s1.length();i++){
        for(ll j=1;j<=s2.length();j++){
            ll replacement = 1 + dp[i-1][j-1];
            ll insertion = 1 + dp[i-1][j];
            ll deletion = 1 + dp[i][j-1];
            dp[i][j] = min(replacement,min(insertion,deletion));
            if(s1[i-1]==s2[j-1]) dp[i][j]--;
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
    string s1,s2;
    cin>>s1;
    cin>>s2;
    cout<<findans(s1,s2);
    return 0;
}