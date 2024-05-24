/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if (!head){
            return false;
        }

        ListNode* curr = head;

        while(curr){
            if (curr -> val > 100000){
                return true;
            } 
            else {
                curr -> val = 100001;
            }
            curr = curr -> next;
        }

        return  false;
        
    }
};
// @lc code=end

