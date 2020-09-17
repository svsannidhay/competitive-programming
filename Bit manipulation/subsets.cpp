//https://leetcode.com/problems/subsets/submissions/
class Solution {
public:
    int getBit(int n,int i){
        int mask = 1<<i;
        int bit = 0;
        if((n&mask)>0) bit = 1;
        return bit;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i=1;i<=pow(2,nums.size());i++){
            vector<int> subset;
            for(int j=0;j<nums.size();j++){
                if((i&(1<<j))>0) subset.push_back(nums[j]);
            } 
            ans.push_back(subset);
        }
        return ans;
    }
};