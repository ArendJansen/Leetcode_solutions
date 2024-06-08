/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
using namespace std;

#include <vector>

bool isSolved(const vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            if (board[i][j] == '.') {
                return false;
            }
        }
    }
    return true;
}

bool canPlace(vector<vector<char>> & board, int p , int q){

    for (int i = 0;  i < board.size(); ++i){
        if (board[i][q] == board[p][q] && i != p){
            return false;
        }
    }
    for (int i = 0;  i < board.size(); ++i){
        if (board[p][i] == board[p][q] && i != q){
            return false;
        }
    }

    int pp = (p / 3) * 3 , qq = (q / 3) * 3;

    for (int i = pp;  i <= pp + 2; ++i){
        for (int j = qq; j <= qq + 2; ++j){
            if (board[i][j] == board[p][q] && i != p && j != q){
                return false;
            }
        }
    }

    return true;
}

void Solve(
    vector<vector<char>> & board, 
    int i, 
    int j, 
    const vector<char> & vchars){
    
    if (j == board.size()){
        j = 0;
        ++i;
    } 
    if (i == board.size()){
        return;
    }

    if (board[i][j] == '.'){
        for (char x : vchars){
            board[i][j] = x;
            if (canPlace(board, i, j)){
                Solve(board,i,j+1, vchars);
                if (isSolved(board)){
                    return;
                }
            }
            board[i][j] = '.';
        }
    }
    else {
        Solve(board,i,j+1, vchars);
    }

}

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        std::vector<char> vec_chars = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        Solve(board,0,0,vec_chars);
    }
};
// @lc code=end

