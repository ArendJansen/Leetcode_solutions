/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start

#include <vector>
#include <algorithm>
using namespace std;

int Solve(
    vector<vector<int>>& dungeon,
    vector<vector<int>>& cache,
    int i, 
    int j){

    if (cache[i][j] != 500000){
        return cache[i][j];
    }
    int res; 
    // if (i == dungeon.size() -1 && j == dungeon[0].size() -1){
    //     res = cache[i][j];
    // }
    if (j == dungeon[0].size() - 1){
        res = std::max(-dungeon[i][j] + Solve(dungeon,cache,i+1,j),1);
    }
    else if (i == dungeon.size() - 1){
        res = std::max(-dungeon[i][j] + Solve(dungeon,cache,i,j+1),1);
    }
    else {
        res = std::max(-dungeon[i][j] + std::min(Solve(dungeon,cache,i,j+1),Solve(dungeon,cache,i+1,j)),1);
    }
    cache[i][j] = res;
    return res;
}
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        vector<vector<int>> cache(dungeon.size(),vector<int>(dungeon[0].size(),500000));
        cache[dungeon.size()-1][dungeon[0].size() -1] = 
            std::max(-dungeon[dungeon.size()-1][dungeon[0].size() -1] + 1, 1);
        return Solve(dungeon,cache,0,0);
        
    }
};
// @lc code=end

