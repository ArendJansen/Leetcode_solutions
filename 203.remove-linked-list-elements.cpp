/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (head && head -> val == val){
            curr = head;
            head = head -> next;
            delete curr;
        }
        curr = head;
        prev = head;
        while (curr){
            if (curr -> val == val){
                prev -> next = curr -> next;
                delete curr;
                curr = prev -> next;
            }
            else {
                prev = curr;
                curr = curr -> next;
            }
        }
        return head;
    }
        
};
// @lc code=end

