/*
 * @lc app=leetcode id=2215 lang=cpp
 *
 * [2215] Find the Difference of Two Arrays
 */

// @lc code=start

#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> r1;
        set<int> r2;
        vector<vector<int>> res(2,vector<int>());
        
        for (int i = 0;  i < nums1.size(); ++i){
            r1.insert(nums1[i]);
        }
        for (int i = 0;  i < nums2.size(); ++i){
            r2.insert(nums2[i]);
        }
        for (int i = 0;  i < nums1.size(); ++i){
            r2.erase(nums1[i]);
        }
        for (int i = 0;  i < nums2.size(); ++i){
            r1.erase(nums2[i]);
        }
        res[0] = std::vector<int>(r1.begin(),r1.end());
        res[1] = std::vector<int>(r2.begin(),r2.end());
                
        return res;
    }
};
// @lc code=end

