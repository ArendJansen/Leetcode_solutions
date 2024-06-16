/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int,int> map;
        unordered_set<int> set;

        for (int i = 0;  i < arr.size(); ++i){
            ++map[arr[i]];
        }

        for (auto it = map.begin(); it != map.end(); ++it){
            if (set.count(it -> second) != 0 ){
                return false;
            }
            set.insert(it -> second);
        }

        return true;
    }
};
// @lc code=end

