/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == nullptr){
            return nullptr;
        }
        ListNode* tmp = head;
        int len = 0;

        while(tmp != nullptr){
            ++len;
            tmp = tmp -> next;
        }

        int rotate = k % len;
        if (rotate == 0 ){
            return head;
        }
        int rotate2 = len - rotate;
        int i = 1;

        tmp = head;

        while (i < rotate2){
            tmp = tmp -> next;
            ++i;
        }
        ListNode* nxt = tmp -> next;
        tmp -> next = nullptr;
        tmp = nxt;

        while (tmp -> next != nullptr){
            tmp = tmp -> next;
        }
        tmp -> next = head;
        return nxt;
        // return head;

    }
};
// @lc code=end

