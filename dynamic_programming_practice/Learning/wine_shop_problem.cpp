/*
    you are given the price of n wine bottles and cost of bottle 
    increases to year no * initial cost 
    you can sell bottle only from front and rear of the list
    and in one year you can sell only one bottle per year 
    Find the maximum profit you can make 
    ex :- 
    year 1 :-     1 4 2 3   sell 1 profit = 1
    year 2 :-       8 4 6   sell 3 profit = 3.2
    year 3 :-        12 6   sell 2 proft =   2.3
    yer 4  :-        16     sell 4 proft = 4.4
    => profit = 1 + 6 + 6 + 16 = 29


*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

#define ll long long int
#define cinll(x) ll x;cin>>x;
#define pb(x) push_back(x);

using namespace std;

//memoization top-down dp
//time complexity brute force O(2^n)
//time complexity top-down O(n^2) 
ll memo[1000][1000];     //n^2 dynamic states
ll solvememo(vector<ll> &bottles,ll be,ll en,ll year){
    if(be>en) return 0;
    if(be==en){
        memo[be][be] = year*bottles[be];
        return memo[be][be];
    }    
    if(memo[be][en]!=-1) return memo[be][en];
    ll start = year*bottles[be] + solvememo(bottles,be+1,en,year+1);
    ll end = year*bottles[en] + solvememo(bottles,be,en-1,year+1);
    memo[be][en] = max(start,end);
    return memo[be][en];
}
//bottom- up dp
ll solvedp(vector<ll> bottles,ll n){
    ll dp[1000][1000];
    memset(dp,-1,sizeof(dp));
    ll year = n;
    for(ll i=0;i<n;i++) dp[i][i] = year*bottles[i];
    year--;
    for(ll len=2;len<=n;len++){
        for(ll start = 0;start<=n-len;start++){
            ll end = start + len - 1;
            dp[start][end] = max(
                (bottles[start]*year + dp[start+1][end]),
                (dp[start][end-1] + bottles[end]*year)
                );
        }
        year--;
    }
    return dp[0][n-1];   
}

int main(){
    cinll(n);
    memset(memo,-1,sizeof(memo));
    vector<ll> bottles;
    for(ll i=0;i<n;i++){
        cinll(x);bottles.pb(x);
    } 
    cout<<solvememo(bottles,0,n-1,1)<<"\n"<<solvedp(bottles,n)<<"\n";
    return 0;
}
