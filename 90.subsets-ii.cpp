/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
#include <vector>
#include<set>
using namespace std;

void Solve(
    vector<int> & nums,
    set<vector<int>> & solutions){
        if (nums.size() == 0){
            return;
        }

        int curr = -11;
        solutions.insert(nums);

        for (int i = 0;  i < nums.size(); ++i){
            if (nums[i] != curr){
                vector<int> copy = nums;
                curr = nums[i];
                copy.erase(copy.begin() + i);
                Solve(copy,solutions);
            }
        }


}
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        std::sort(nums.begin(), nums.end());
        set<vector<int>> solutions;
        solutions.insert(vector<int>());
        Solve(nums,solutions);
        return vector<vector<int>>(solutions.begin(), solutions.end());
    }
};

// @lc code=end
