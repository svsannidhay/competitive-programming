https://leetcode.com/problems/find-the-duplicate-number/submissions/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> findans;
        int ans;
        for(int i=0;i<nums.size();i++){
            findans.insert(nums[i]);
            if(findans.size()!=i+1){
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};