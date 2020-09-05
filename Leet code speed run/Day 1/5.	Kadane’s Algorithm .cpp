https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>dp[i-1]+nums[i]) dp.push_back(nums[i]);
            else dp.push_back(dp[i-1]+nums[i]);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};