/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        std::unordered_map<std::string,std::vector<std::string>> lmap;
        std::vector<std::vector<std::string>> res;
        for (int i = 0; i < strs.size(); ++i){
            std::string tmp = strs[i];
            std::sort(tmp.begin(), tmp.end());
            lmap[tmp].push_back(strs[i]);
        }

        for (const auto& pair : lmap) {
            res.push_back(pair.second);
        }
        return res;
    }
};
// @lc code=end

