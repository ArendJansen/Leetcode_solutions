/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr){
            return head;
        }
        ListNode* tmp = head;
        ListNode* tmp2 = head;
        int len = 0;
        while (tmp != nullptr){
            ++len;
            tmp = tmp -> next;
        }
        if (len == 2){
            return head;
        }
        while (tmp2 -> next != nullptr ){
            tmp2 = tmp2 -> next;
        }
        tmp = head;
        ListNode* prev = head;
        for (int i = 1; i <= len; ++i){
            if (i % 2 == 0){
                prev -> next = tmp -> next;
                tmp2 -> next = tmp;
                tmp2 = tmp2 -> next;
                tmp = tmp -> next;
                tmp2 -> next = nullptr;
            }
            else{
                tmp = tmp -> next;
                if (i != 1){
                    prev = prev -> next;
                }
            }
        }

        return head;
    }
};
// @lc code=end

