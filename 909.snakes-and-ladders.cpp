/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */

// @lc code=start

#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:

    int snakesAndLadders(vector<vector<int>>& board) {
        int nfinal = board.size() * board.size() - 1;
        std::queue<int> lq;
        std::reverse(board.begin(), board.end());
        std::set<int> seen;
        lq.push(0);
        int low = 0, high = 0, count = 0, tmp = 0, row = 0, col = 0, size = 0;
        while(!lq.empty()){
            size = lq.size();
            for (int i = 0;  i < size; ++i){
                tmp = lq.front();
                lq.pop();

                if (seen.count(tmp) > 0){
                    continue;
                }
                seen.insert(tmp);
                if (tmp == nfinal){
                    return count;
                }
                low = tmp + 1;
                high = std::min(tmp+6,nfinal);
                for (int j = low; j <= high; ++j){
                    row = j / board.size();
                    if (row % 2 == 0){
                        col = j % board.size();
                    }
                    else{
                        col = board.size() - 1 - j % board.size();
                    }

                    if (board[row][col] != -1){
                        lq.push(board[row][col] -1 );
                    }
                    else{
                        lq.push(j);
                    }

                }


            }
            ++count;
        }

        return -1;
    }
};
// @lc code=end

