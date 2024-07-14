/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* start = new ListNode(-201,head);
        ListNode* prev_smaller = start;
        ListNode* prev = start;
        ListNode* first_greater = nullptr;
        ListNode* tmp = head;

        while (tmp != nullptr){
            if (tmp -> val < x){
                prev_smaller -> next = tmp;
                prev_smaller = tmp;
                if (first_greater != nullptr){
                    prev -> next = tmp -> next;
                    tmp -> next = first_greater;
                    first_greater = nullptr;

                }
                tmp = tmp -> next;
                
            }
            else {
                if (first_greater == nullptr){
                    first_greater = tmp;
                }
                prev = tmp;
                tmp = tmp -> next;
            }
        }
        return start -> next;
        
    }
};
// @lc code=end

