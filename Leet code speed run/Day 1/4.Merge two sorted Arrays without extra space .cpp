//https://leetcode.com/problems/merge-sorted-array/submissions/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int first = 0;
        int second = 0;
        while(first<m&&second<n){
            if(nums1[first]<=nums2[second]){
                ans.push_back(nums1[first]);
                first++;
            }else{
                ans.push_back(nums2[second]);
                second++;
            }
        }
        while(first<m){
            ans.push_back(nums1[first]);
            first++;
        }
        while(second<n){
            ans.push_back(nums2[second]);
            second++;
        }
        nums1 = ans;
    }
};