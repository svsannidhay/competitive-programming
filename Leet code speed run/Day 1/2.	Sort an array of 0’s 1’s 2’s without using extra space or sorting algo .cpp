//https://leetcode.com/problems/sort-colors/submissions/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> mapit;
        for(int i=0;i<nums.size();i++) mapit[nums[i]]++;
        nums.clear();
        for(auto it=mapit.begin();it!=mapit.end();it++){
            for(int i=0;i<it->second;i++){
                nums.push_back(it->first);      
            } 
        }
    }
};