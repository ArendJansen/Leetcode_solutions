/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if (head == nullptr || k == 1){
            return head;
        }

        int count = 0;
        ListNode* tmp = head;

        while (tmp != nullptr && count < k){
            ++count;
            tmp = tmp -> next;
        }
        if (count < k){
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        int i = 0;
        while (i < k){
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            ++i;
        }
        i = 1;
        curr = prev;

        while (i < k){
            ++i;
            curr = curr -> next;
        }

        if (tmp  != nullptr){
            curr -> next = reverseKGroup(tmp ,k);
        }

        return prev;


    }
};
// @lc code=end

