#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
#define cinll(x) ll x;cin>>x;
#define MOD 1000000009 
using namespace std;
//TOP - DOWN using memoization
// ll dp[1000001];

// ll fibbonacci(ll n){
//     if(n==0){
//         return 0;
//     }
//     if(n==1){
//         return 1;
//     }
//     if(dp[n]==-1){
//         ll ans = fibbonacci(n-1) + fibbonacci(n-2);
//         dp[n] = ans;
//         return ans;
//     }else{
//         return dp[n];
//     }
// }

// int main(){
//     cinll(n);
//     for(ll i=0;i<1000001;i++){
//         dp[i] = -1;
//     }
//     cout<<fibbonacci(n);
//     return 0;
// }

//BOTTOM - UP 

ll fib(ll n){
    ll dp[1000001] = {};
    dp[0] = 0;
    dp[1] = 1;
    for(ll i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    cinll(n);
    ll ans = fib(n);
    cout<<ans<<" "; 
    return 0;
}