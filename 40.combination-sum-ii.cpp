/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
#include <vector>
#include <set>


void Solve(
    const std::vector<int> & candidates, 
    std::set<std::vector<int>> & solutions,
    std::vector<int> & state,
    int target,
    int crow){
    if (target == 0){
        // std::vector<int> res = state;
        // std::sort(res.begin(), res.end());
        solutions.insert(state); 
        return;
    }
    else if (target < 0){
        return;
    }

    for (int i = crow; i < candidates.size(); ++i){
        if (i > crow && candidates[i] == candidates[i-1]){
            continue;
            }
        state.push_back(candidates[ i]);
        Solve(candidates, solutions,state, target - candidates[i],i + 1);
        state.pop_back();
     
    }
        // state.push_back(candidates[ i]);
        // Solve(candidates, solutions,state, target - candidates[i],i + 1);
        // state.pop_back();

}
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        std::sort(candidates.begin(), candidates.end());
        std::set<std::vector<int>> solutions;
        std::vector<int> state;
        
        Solve(candidates,solutions,state, target, 0);

        return std::vector<std::vector<int>>(solutions.begin(), solutions.end());    }
};
// @lc code=end

