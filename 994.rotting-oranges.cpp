/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
#include <vector>
#include <utility>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        std::queue<std::pair<int,int>> que;
        std::set<std::pair<int,int>> set;

        int fresh_count = 0;

        for (int i = 0;  i < grid.size(); ++i){
            for (int j = 0;  j < grid[0].size(); ++j){
                if (grid[i][j] == 1){
                    ++fresh_count;
                    set.insert(std::make_pair(i,j));
                }
                else if (grid[i][j] == 2){
                    que.push(std::make_pair(i,j));
                }
            }
        }

        if (fresh_count == 0){return 0;}

        vector<vector<int>> offsets={{0,1},{1,0},{0,-1},{-1,0}};


        while(!que.empty()){

            int l = que.size();
             ++count;
            for (int k = 0; k < l; ++k){
                for (int m = 0; m < 4; ++m){
                    int x = que.front().first + offsets[m][0];
                    int y = que.front().second + offsets[m][1];

                    if (x < 0 || y < 0 || x >= rows || y >= cols){
                        continue;
                    }
                    if (set.count(std::make_pair(x,y)) > 0){
                        set.erase(std::make_pair(x,y));
                        // grid[x][y] = 2;
                        que.push(std::make_pair(x,y));
                    }
                }
                que.pop();                

            }
            if (set.size() == 0){
                return count;
            }
        }

        return -1;
    }
};
// @lc code=end

