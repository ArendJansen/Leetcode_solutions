/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start

void Solve(std::set<std::vector<int>> & sol, std::vector<int> & nums){

    if (nums.size() == 0){return;}
    sol.insert(nums);

    for (int i = 0; i < nums.size(); ++i){
        std::vector<int> tmp = nums;
        tmp.erase(tmp.begin() + i);
        Solve(sol, tmp);
    }

}
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::set<std::vector<int>> sol;
        sol.insert(std::vector<int>());
        Solve(sol, nums);

        return std::vector<std::vector<int>>(sol.begin(),sol.end());   
        
    }
};
// @lc code=end

