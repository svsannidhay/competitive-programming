/*
Given two strings A and B . You can perform some operations of them 
1> Insertion :- you can insert any character at any position 
2> deletion :- you can delete any character 
3> replacement :- you can replace a charater by another character 
You need to find the minimum no of operations required to make 
A equals B. 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define ll long long int 
#define cinll(x) ll x;cin>>x;
#define pb(x) push_back(x);

using namespace std;

//top-down memoization
ll memo[1000][1000];
ll solvememo(string s1,string s2,ll p1,ll p2){
    if(p1>=s1.length()&&p2>=s2.length()) return 0;
    if(p1>=s1.length()) return s2.length()-(p2);
    if(p2>=s2.length()) return s1.length()-(p1);
    if(memo[p1][p2]!=-1) return memo[p1][p2];
    if(s1[p1]==s2[p2]) return solvememo(s1,s2,p1+1,p2+1);
    ll insertion = 1 + solvememo(s1,s2,p1,p2+1);
    ll deletion = 1 + solvememo(s1,s2,p1+1,p2);
    ll replacement = 1 + solvememo(s1,s2,p1+1,p2+1);
    memo[p1][p2] = min(insertion,min(deletion,replacement));
    return memo[p1][p2];
}

//bottom - up pure dp
ll solvedp(string s1,string s2){
    ll dp[s1.length()+1][s2.length()+1];
    dp[0][0] = 0;
    for(ll i=1;i<=s1.length();i++) dp[i][0] = 1 + dp[i-1][0];
    for(ll i=1;i<=s2.length();i++) dp[0][i] = 1 + dp[0][i-1];
    for(ll i=1;i<=s1.length();i++){
        for(ll j=1;j<=s2.length();j++){
            if(s1[i]==s2[j]) dp[i][j] = dp[i-1][j-1];
            else{
                ll insertion  = 1 + dp[i][j-1];
                ll deletion = 1 + dp[i-1][j];
                ll replacement = 1 + dp[i-1][j-1];
                dp[i][j] = min(insertion,min(deletion,replacement));
            }
        }
    }
    return dp[s1.length()][s2.length()];
}

int main(){
    memset(memo,-1,sizeof(memo));
    string s1,s2;
    cin>>s1;cin>>s2;
    cout<<solvememo(s1,s2,0,0)<<" "<<solvedp(s1,s2);
    return 0;
}