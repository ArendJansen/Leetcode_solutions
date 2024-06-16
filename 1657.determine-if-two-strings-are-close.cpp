/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool closeStrings(string word1, string word2) {

        if (word1.length() != word2.length()){
            return false;
        }
        unordered_map<char,int> lmap;
        unordered_map<char,int> rmap;
        for (char x : word1){
            ++lmap[x];
        }
        for (char x : word2){
            ++rmap[x];
        }
        for (auto it = lmap.begin(); it != lmap.end(); ++it){
            if (rmap.count(it -> first) <= 0){
                return false;
            }
        }

        bool x = false;

        for (auto it = lmap.begin(); it != lmap.end(); ++it){
            x =true;
            for (auto it2 = rmap.begin(); it2 != rmap.end(); ++it2){
                if (it -> second == it2 -> second){
                    it -> second = 0;
                    it2 -> second = 0;
                    x = false;
                    break;
                }
            }
            if (x){return false;}
        }
        return true;
    }
};
// @lc code=end

