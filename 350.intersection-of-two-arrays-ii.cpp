/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
#include <vector>
#include <unordered_map>
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int,int> nmap;
        std::vector<int> res;

        for (int i =0; i < nums1.size(); ++i){
            ++nmap[nums1[i]];
        }
        for (int i =0; i < nums2.size(); ++i){
            if (nmap.find(nums2[i]) != nmap.end() &&
                nmap[nums2[i]] != 0){
                    res.push_back(nums2[i]);
                    --nmap[nums2[i]];
                }
        }
        return res;
    }
};
// @lc code=end

