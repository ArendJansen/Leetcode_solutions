/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
#include <string>
#include <map>
#include <utility>
using namespace std;

class Solution {
public:
    int dp(
        const std::string & text1,
        const std::string & text2,
        int i,
        int j,
        std::map<std::pair<int,int>, int> & cache){
            std::pair<int,int> pair = std::make_pair(i,j);

            if (cache.count(pair) > 0 ){
                return cache[pair];
            }
            if (i == text1.length() || j  == text2.length()){
                return cache[pair] = 0;
            }

            if (text1[i] == text2[j]){
                return cache[pair] = 1 + std::max(dp(text1,text2,i+1,j+1,cache),dp(text1,text2,i+1,j+1, cache));
            }

            return cache[pair] = std::max(dp(text1,text2,i+1,j, cache),dp(text1,text2,i,j+1, cache));
    }
    int longestCommonSubsequence(string text1, string text2) {
        std::map<std::pair<int,int>, int> cache;
        return dp(text1,text2,0,0,cache);
    }
};
// @lc code=end

