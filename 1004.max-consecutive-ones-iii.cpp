/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int flipped =0, count = 0, max =0, r =0;
        std::queue<int> pos;

        while (r < nums.size()){
            if(nums[r] == 1){
                ++count;
            }
            else if (flipped < k){
                ++count;
                pos.push(r);
                ++flipped;
            }
            else if (flipped == k){
                count = 0;
                if (k > 0){
                    count = r - pos.front();
                    pos.pop();
                    pos.push(r);
                }

            }
            max = count > max ? count : max;
            ++r;
        }
        return max;
        
    }
};
// @lc code=end

