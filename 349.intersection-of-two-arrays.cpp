/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
#include <unordered_map>
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int,int> nmap;
        std::vector<int> res;

        for (int i =0; i < nums1.size(); ++i){
            ++nmap[nums1[i]];
        }
        for (int i =0; i < nums2.size(); ++i){
            if (nmap.find(nums2[i]) != nmap.end() &&
                nmap[nums2[i]] != 0){
                    res.push_back(nums2[i]);
                    nmap[nums2[i]] = 0;
                }
        }
        return res;
    }
};
// @lc code=end

