#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int 
#define cinll(x) ll x;cin>>x;
#define MAX 1e18
using namespace std;

//Top - down using memoization

// ll dp[1000001];

// ll reduceno(ll n){
//     if(n==1){
//         return 0;
//     }
//     if(dp[n]!=-1){
//         return dp[n];
//     }
//     ll q1 = MAX;ll q2 = MAX;ll q3 = MAX;
//     if(n%3 == 0) q1 = 1 + reduceno(n/3);
//     if(n%2==0) q2 = 1 + reduceno(n/2);
//     q3 = 1 + reduceno(n-1);
//     ll ans = min(q1,min(q2,q3));
//     dp[n] = ans;
//     return ans;
// }

// int main(){
//     //cinll(n);
//     for(ll i=0;i<=1000001;i++){
//         dp[i] = -1;
//     }
//     ll n;cin>>n;
//     ll ans = reduceno(n);
//     cout<<ans<<" ";
//     return 0;
// }

//Bottom - up

ll reduceno(ll n){
    ll dp[1000001];
    dp[0] = 0;dp[1] = 0;
    dp[2] = 1;dp[3] = 1;

    for(ll i=4;i<=n;i++){
        ll q1 = MAX;
        ll q2 = MAX;
        ll q3 = MAX;
        if(i%3==0) q1 = 1 + dp[i/3];
        if(i%2==0) q2 = 1 + dp[i/2];
        q3 = 1 + dp[i-1];
        dp[i] = min(q1,min(q2,q3));
    }
    return dp[n];
}

int main(){
    cinll(n);
    ll ans = reduceno(n);
    cout<<ans<<" ";
    return 0;
}
