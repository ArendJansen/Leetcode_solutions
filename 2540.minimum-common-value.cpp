/*
 * @lc app=leetcode id=2540 lang=cpp
 *
 * [2540] Minimum Common Value
 */

// @lc code=start
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        int l = 0, r = 0;

        while (l < nums1.size() && r < nums2.size()){
            if (nums1[l] == nums2[r]){
                return nums1[l];
            }
            else if (nums1[l] > nums2[r]){
                ++r;
            }
            else {++l;}
        }
        return -1;

        // std::unordered_set<int> tset;

        // for (size_t i = 0; i < nums1.size(); i++)
        // {
        //     tset.insert(nums1[i]);
        // }
        
        // for (size_t i = 0; i < nums2.size(); i++)
        // {
        //     if (tset.count(nums2[i]) > 0){
        //         return nums2[i];
        //     }
        // }
        // return -1;
        
        
    }
};
// @lc code=end

