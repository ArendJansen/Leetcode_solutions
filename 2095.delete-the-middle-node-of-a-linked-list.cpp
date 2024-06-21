/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr){
            return nullptr;
        }

        ListNode* tmp  = head;

        int len = 0;
        
        while (tmp != nullptr){
            ++len;
            tmp = tmp -> next;
        }
        int middle = len /2;

        if (middle == 0){
            tmp = head -> next;
            delete head;
            return tmp;
        }
        int left = middle -1;
        ListNode* tmp2 = head;
        tmp = head;

        while (middle > 0){
            tmp = tmp -> next;
            --middle;
        }
        while (left > 0){
            tmp2 = tmp2 -> next;
            --left;
        }
        tmp2 -> next = tmp -> next;
        delete tmp;

        return head;
    }
};
// @lc code=end

