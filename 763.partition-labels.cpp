/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int i = 0, j, j2;
        vector<int> sol;
        unordered_set<char> seen;

        while(i < s.length()){
            char x = s[i];
            seen.insert(x);
            j = s.length() -1;

            while (j > i){
                if (s[j] == x){
                    break;
                }
                --j;
            }

            for (int p = i + 1; p <= j; ++p){
                seen.insert(s[p]);
            }
            j2 = s.length() -1;
            
            while (true){
                j2 = s.length() -1;
                while (j2 > j){
                    if (seen.count(s[j2]) > 0){
                        break;
                    }
                    --j2;
                }
                if (j == j2){
                    break;
                }
                for (int p = j +1; p <= j2; ++p){
                    seen.insert(s[p]);
                }
                j = j2;                
            }
            sol.push_back(j - i + 1);
            i = j + 1;
            // seen.clear();
        
        }

        return sol;
    }
};
// @lc code=end

