/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <vector>

using namespace std;

class Solution {
public:
    int pairSum(ListNode* head) {
        std::vector<int> nums;
        while (head != nullptr){
            nums.push_back(head->val);
            head = head -> next;
        }
        int max = 0, i = 0, j = nums.size() -1;

        while (i < j){

            max = std::max(max,nums[i] + nums[j]);
            ++i;
            --j;
        }

        return max;

    }
};
// @lc code=end

