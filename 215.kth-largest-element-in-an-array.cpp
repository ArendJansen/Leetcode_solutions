/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int> q;

        for (int i : nums){
            q.push(i);
        }

        while (k > 1){
            q.pop();
            --k;
        }
        return q.top();
        
    }
};
// @lc code=end

