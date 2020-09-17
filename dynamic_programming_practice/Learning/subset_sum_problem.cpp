// find the set having sum k

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

#define cinll(x) ll x;cin>>x;
#define ll long long int 

using namespace std;

//https://leetcode.com/problems/partition-equal-subset-sum/
class Solution {
public:
    vector<int> findansdp(vector<int> &nums,int sum,int n){
        int dp[n+1][sum+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++) dp[i][0] = 1;
        for(int i=1;i<=n;i++){
            for(int  j=1;j<=sum;j++){
                if(nums[i-1]==j) dp[i][j] = 1;
                else if(nums[i-1]>j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j],dp[i-1][j-nums[i-1]]);
            }
        }
        vector<int> ans;
        for(int i=0;i<=sum;i++){
            ans.push_back(dp[n][i]);
        }
        return ans;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++) sum += nums[i];
        if(sum%2==0){
            vector<int> ans = findansdp(nums,sum,nums.size());
            if(ans[sum/2]==1) return true;
            else return false;
        }
        else return false;
    }
};

//bottom -  up dp
vector<ll> findans(vector<ll> &arr,ll n,ll sum){
    ll dp[n+1][sum+1];
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<=n;i++) dp[i][0] = 1;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=sum;j++){
            if(arr[i-1]==j) dp[i][j] = 1;
            if(arr[i-1]>j) dp[i][j] = dp[i-1][j];
            if(arr[i-1]<j) dp[i][j] = max(dp[i-1][j],dp[i-1][j-arr[i-1]]);
        }
    }
    vector<ll> ans(sum+1,0);
    for(ll i=0;i<=sum;i++){
        ans[i] = dp[n][i];
    }
    return ans;
}
int main(){
    cinll(n);
    vector<ll> arr;
    ll sum = 0;
    for(ll i=0;i<n;i++){
        cinll(x);arr.push_back(x);
        sum += x;
    }
    cinll(k);

    vector<ll> ans = findans(arr,n,sum);
    for(ll i=0;i<ans.size();i++){
        //cout<<ans[i]<<" ";
    }
    return 0;
}
