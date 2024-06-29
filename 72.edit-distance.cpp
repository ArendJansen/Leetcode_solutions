/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int dp(
        std::string word1,
        std::string word2,
        int i,
        int j,
        std::vector<std::vector<int>> & cache){

            if (j == word2.length()){
                return cache[i][j] = word1.length() - i;
            }

            if(i == word1.length()){
                return cache[i][j] = word2.length() - j;
            }

            if (cache[i][j] != -1){
                return cache[i][j];
            }

            if (word1[i] == word2[j]){
                return cache[i][j] = dp(word1,word2,i+1,j+1,cache);
            }

            int replace = 1 + dp(word1,word2,i+1,j+1,cache);
            int del = 1 + dp(word1,word2,i+1,j,cache);
            int insert = 1 + dp(word1,word2,i,j+1,cache);

            return cache[i][j] = std::min(replace, std::min(del,insert));

        }
    int minDistance(string word1, string word2) {
        // std::vector<std::vector<std::vector<int>>> cache(word1.length(), vector<vector<int>>(word2.length()));
        std::vector<std::vector<int>> cache(word1.length() + 1,std::vector<int>(word2.length() + 1,-1));
        return dp(word1,word2,0,0,cache);
    }
};
// @lc code=end

