/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if (headA == nullptr || headB == nullptr){
            return nullptr;
        }
        int len_a = 0, len_b =0;

        ListNode* curr_a = headA;
        ListNode* curr_b = headB;
        
        while(curr_a){
            ++len_a;
            curr_a = curr_a -> next;
        }
        while(curr_b){
            ++len_b;
            curr_b = curr_b -> next;
        }
        curr_a = headA;
        curr_b = headB;

        while (len_a > len_b){
            curr_a = curr_a -> next;
            --len_a;
        }
        while (len_b > len_a){
            curr_b = curr_b -> next;
            --len_b;
        }
        while(curr_a){
            if (curr_a == curr_b){
                return curr_a;
            }
            curr_a = curr_a -> next;
            curr_b = curr_b -> next;
        }

        return nullptr;
        
    }
};
// @lc code=end

