/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start

#include <vector>
#include <map>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        int nrow = grid.size();
        int ncol = grid[0].size();
        int x = 0, y = 0, count = 0;
        
        queue<std::pair<int,int>> lq;
        std::vector<std::vector<int>> seen(grid.size(), vector<int>(grid[0].size(),-1));
        for (int i = 0;  i < grid.size(); ++i){
            for (int j = 0;  j < grid[0].size(); ++j){
                if (grid[i][j] == '1' && seen[i][j] < 0){
                    seen[i][j] = 1;
                    ++count;
                    lq.push(std::make_pair(i,j));
                    while (!lq.empty()){
                        for (int m = 0; m < 4; ++m){
                            x = lq.front().first + dirs[m][0];
                            y = lq.front().second + dirs[m][1];

                            if (x < 0 || x >= nrow || y < 0 || y >= ncol){
                                continue;
                            }
                            else if (grid[x][y] == '1' && seen[x][y] < 0){
                                lq.push(std::make_pair(x,y));
                                seen[x][y] = 1;
                            }
                        }
                        lq.pop();
                    }

                }
            }
        }
        return count;
    }
};
// @lc code=end

