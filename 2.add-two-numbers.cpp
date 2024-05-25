/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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

ListNode* helper(ListNode* l1, ListNode* l2, int carry){
    ListNode* res = new ListNode;
    int sum = 0;
    if (l1 && l2){
        sum = l1 -> val + l2 -> val + carry;
        if (sum > 9){
            res -> val = sum % 10;
            res -> next = helper(l1 -> next, l2 -> next, 1);
        }
        else {
            res -> val = sum;
            res -> next = helper(l1 -> next, l2 -> next, 0);
        }
    }
    else if (l1){    
        sum = l1 -> val + carry;
        if (sum > 9){
            res -> val = sum % 10;
            res -> next = helper(l1 -> next, l2, 1);
        }
        else {
            res -> val = sum;
            res -> next = helper(l1 -> next, l2, 0);
        }
    }
    else if (l2){    
        sum = l2 -> val + carry;
        if (sum > 9){
            res -> val = sum % 10;
            res -> next = helper(l1, l2 -> next, 1);
        }
        else {
            res -> val = sum;
            res -> next = helper(l1, l2 -> next, 0);
        }
    }
    else if (carry > 0){
        res -> val = carry;
        res -> next = helper(l1,l2,0);
    }
    else {
        return nullptr;
    }  
    return res;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* res = helper(l1, l2, 0);
        return res;
    }
};
// @lc code=end

