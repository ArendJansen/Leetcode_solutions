/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start

void Solve(std::vector<std::vector<int>> & sol, std::vector<int> & nums){

    if (nums.size() == 0){return;}
    sol.push_back(nums);

    for (int i = 0; i < nums.size(); ++i){
        std::vector<int> tmp = nums;
        tmp.erase(tmp.begin() + i);
        Solve(sol, tmp);
    }

}
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        std::vector<std::vector<int>> sol;
        Solve(sol, nums);

        return sol;
        
    }
};
// @lc code=end

