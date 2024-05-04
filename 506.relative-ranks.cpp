/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

// @lc code=start
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        std::vector<std::string> res(score.size(),"");
        std::vector<std::pair<int,int>> n;

        for (int i = 0; i < score.size(); ++i){
            n.push_back(std::make_pair(-score[i],i));
        }
        std::sort(n.begin(), n.end());

        for (int i = 0; i < n.size(); ++i){
            if(i > 2){
                res[n[i].second] = std::to_string(i + 1);
            } else if (i == 0){
               res[n[i].second] = "Gold Medal";
            } else if (i == 1){
               res[n[i].second] = "Silver Medal";
            } else if (i == 2){
                res[n[i].second] = "Bronze Medal";
            }
        }

        return res;
    


    }
};
// @lc code=end

