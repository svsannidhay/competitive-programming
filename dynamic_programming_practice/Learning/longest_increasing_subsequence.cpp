#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

#define ll long long int
#define cinll(x) ll x;cin>>x;
#define MAX 1e18
#define pb(x) push_back(x)

using namespace std;

//bottom-up pure dp
//time complexity O(n^2)
ll LIS(vector<ll> arr,ll n){
    ll dp[100005];
    for(ll i=0;i<n;i++) dp[i] = 1;
    ll ans = 1;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<i;j++){
            if(arr[j]<=arr[i]) dp[i]  = max(dp[i],1+dp[j]);
        }
        ans = max(ans,dp[i]);
    }
    for(ll i=0;i<n;i++) cout<<dp[i]<<" ";
    cout<<"\n";
    return ans;
}

int main(){
    cinll(n);
    vector<ll> arr;
    for(ll i=0;i<n;i++){
        cinll(x);arr.pb(x);
    }
    cout<<LIS(arr,n);
    return 0;
}
