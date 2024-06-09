/*
 * @lc app=leetcode id=807 lang=cpp
 *
 * [807] Max Increase to Keep City Skyline
 */

// @lc code=start
#include <vector>
using namespace std;

int rowMax(int j , const vector<vector<int>>& grid ){

    int max = 0;
    for (int i = 0;  i < grid.size(); ++i){
        max = grid[i][j] > max ? grid[i][j] : max;
    }

    return max;

}

int colMax(int i , const vector<vector<int>>& grid ){

    int max = 0;
    for (int j = 0;  j < grid.size(); ++j){
        max = grid[i][j] > max ? grid[i][j] : max;
    }

    return max;
    
}
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        int tot =0;
        int rowmax, colmax;
        for (int i = 0;  i < grid.size(); ++i){
            for (int j = 0;  j < grid[0].size(); ++j){
                rowmax = rowMax(j, grid);
                colmax = colMax(i, grid);
                tot += std::min(rowmax,colmax) - grid[i][j];
            }
        }

        return tot;
    }
};
// @lc code=end

