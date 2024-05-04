/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> res(nums1.size(),-1);
        for (int i = 0; i < nums1.size(); ++i){
            int val = -1;
            bool set = false;
            for (int j = 0; j < nums2.size(); ++j){
                if (nums1[i] == nums2[j]){
                    val = nums2[j];
                    set = true;
                }
                else if (set && nums2[j] > val){
                    set = false;
                    res[i] = nums2[j];
                }
            }
        }
        return res;
    }
};
// @lc code=end

