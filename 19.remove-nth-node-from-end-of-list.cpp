/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *tmp = head;
        ListNode *prev = nullptr;
        int len = 0;

        while (tmp != nullptr){
            ++len;
            tmp = tmp -> next;
        }
        tmp = head;
        int rem = len - n + 1;

        if (rem == 1){
            if (head -> next == nullptr){
                return nullptr;
            }
            else {
                return head -> next;
            }
        }

        int curr = 1;

        while (curr < rem){
            prev = tmp;
            tmp = tmp -> next;
            ++curr;
        }

        if (tmp -> next == nullptr){
            prev -> next = nullptr;
        }
        else {
            prev -> next = tmp -> next;
        }

        return head;

        
    }
};
// @lc code=end

