/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_set<int> seen;
        std::unordered_map<int,int> lastseen;

        for (int i = 0; i < nums.size(); ++i){
            if (seen.count(nums[i]) > 0){
                if ( (i - lastseen[nums[i]] ) <= k ){
                    return true;
                }
                else {
                    lastseen[nums[i]] = i;
                }
            }
            else{
                seen.insert(nums[i]); 
                lastseen[nums[i]] = i;
            }
        }
        return false;
        
    }
};
// @lc code=end

