/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res =0;
        int nrow = grid.size();
        int ncol = grid[0].size();
        for (int i =0; i < grid.size(); ++i){
            for (int j =0; j < grid[i].size(); ++j){
                if (grid[i][j] == 1){
                    int sides = 4;
                    if (i != 0 && grid[i-1][j] == 1){
                        --sides;
                    }
                    if (i != nrow - 1 && grid[i+1][j] == 1){
                        --sides;
                    }
                    if (j != 0 && grid[i][j-1] ==1){
                        --sides;
                    }
                    if (j != ncol -1 && grid[i][j+1] == 1){
                        --sides;
                    }
                    res += sides;
                }
            }
        }
        return res;
    }
};
// @lc code=end

