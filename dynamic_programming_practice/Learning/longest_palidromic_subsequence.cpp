#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define ll long long int
#define cinll(x) ll x;cin>>x;
#define pb(x) push_back(x)
using  namespace std;

//time complexity O(n^2)
//bottom up
ll ansdp(string s){
    ll dp[1000][1000];
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<s.length();i++){
        dp[i][i] = 1;
    }
    ll len = 2;
    for(ll i=0;i<s.length();i++){
        if(s[i]==s[i+len-1]) dp[i][i+len-1] = 2;
        else dp[i][i+1] = 1;
    }
    for(ll len=3;len<=s.length();len++){
        for(ll i=0;i<s.length()-len+1;i++){
            if(s[i]==s[i+len-1]) dp[i][i+len-1] =  2 + dp[i+1][i+len-2];
            else dp[i][i+len-1] = max(dp[i][i+len-2],dp[i+1][i+len-1]);
        }
    }
    for(ll i=0;i<s.length();i++){
        for(ll j=0;j<s.length();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    string s;
    cin>>s;
    ansdp(s);
    return 0;
} 