/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        if (piles.size() == 1){
            if (piles[0] % h == 0){
                return piles[0] / h;
            }
            else{
                return piles[0] /h  + 1;
            }
        }
        std::sort(piles.begin(), piles.end());
        int l = 1, r = piles[piles.size() -1], m = 0;
        int ans = 0;
        long long count = 0;
        while(l <= r){
            m = l + (r - l) / 2;
            count = 0;
            for (int i = 0;  i < piles.size(); ++i){
                if (piles[i] % m == 0){
                    count += piles[i] / m ;
                }
                else{
                count = count +  (piles[i] / m) + 1; 

                }
            }
            if (count == h){
                ans = m; 
                r = m -1;
            }
            else if (count < h){
                ans = m;
                r = m -1;
            }
            else{
                l = m + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

