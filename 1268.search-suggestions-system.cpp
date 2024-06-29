/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 */

// @lc code=start
#include <vector>
#include <string> 

using namespace std;


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        std::sort(products.begin(), products.end());
        std::vector<std::vector<std::string>> res(searchWord.length(), vector<string>());
        vector<int> common(products.size(),0);
        int sim = 0, j = 0, x =0;
        for (int i = 0;  i < products.size(); ++i){
            sim = 0;
            x = std::min(products[i].length(), searchWord.length());
            j = 0;
            while (j < x){
                if (products[i][j] != searchWord[j]){
                    break;
                }
                ++sim;
                ++j;
            }
            common[i] = sim;
        }   

        for (int i = 0;  i < searchWord.length(); ++i){
            x = 0;
            for (int j = 0;  j < common.size(); ++j){
                if (common[j] >= i + 1 && x < 3){
                    res[i].push_back(products[j]);
                    ++x;
                }
            }           
        } 

        return res;
    }
};
// @lc code=end

