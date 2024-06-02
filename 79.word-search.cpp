/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
#include <string>
#include <vector>

void Solve(
    std::vector<std::vector<char>> & board,
    const std::string & word,
    std::string & curr,
    int i,
    int j,
    int curr_letr,
    int & count
    ){

    if (count > 0){
        return;
    }
    if (curr == word){
        ++count;
        return;
    }

    else if (curr_letr >= word.size() ){    
        return;
    }

    if (board[i][j] == word[curr_letr]){
        curr += word[curr_letr];
        char tmp = word[curr_letr];
        board[i][j] = '0';
        ++curr_letr;

        if (curr == word){
            ++count;
            return;
        }
        if (i > 0){
            Solve(board,word,curr,i-1,j,curr_letr,count);
        }
        if (i <board.size() -1){
            Solve(board,word,curr,i+1,j,curr_letr,count);
        }
         if (j > 0){
            Solve(board,word,curr,i,j-1,curr_letr,count);
        }       
        if (j <board[0].size() -1 ){
            Solve(board,word,curr,i,j+1,curr_letr,count);
        }
        curr.pop_back();
        board[i][j] = tmp;

    }
    

}

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        int count = 0;
        std::string curr;
        if (word.length() == 0){
            return true;
        }
        for (int i = 0;  i < board.size(); ++i) {
            for (int j = 0;  j < board[0].size(); ++j) {
                if (board[i][j] == word[0]){
                    Solve(board,word,curr,i,j,0,count);
                }
            }
        }
        if (count > 0){
            return true;
        }
        return false;
    }
};
// @lc code=end

