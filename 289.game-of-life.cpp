/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
#include <vector>
using namespace std;


class Solution {
public:
    int pos_neigh(vector<vector<int>> & board, int i, int j){
        int rows = board.size(), cols = board[0].size();
        int count = 0;
        for (int x = i - 1; x <= i + 1; ++x){
            for (int y = j -1;  y <= j + 1; ++y){
                if (x < 0 || x >= rows || y < 0 || y >= cols || x == i && y == j){
                    continue;
                }
                else if (board[x][y] == 1){
                    ++count;
                }
            }
        }
        return count;

        // vector<vector<int>> offsets = {{0,1},{1,0},{0,-1},{-1,0}}
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> res = board;

        int count = 0;

        for (int i = 0;  i < board.size(); ++i){
            for (int j =0; j < board[0].size(); ++j){
                board[i][j] = 0;
                count = pos_neigh(res,i,j);
                if (res[i][j] == 1 && count  > 1 && count < 4){
                    board[i][j] = 1;
                }
                else if (res[i][j] == 0 && count == 3){
                    board[i][j] = 1;
                }
            }
        }

    }
};
// @lc code=end

