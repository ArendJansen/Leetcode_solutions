/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
#include <map>
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        std::map<int,int> lmap;
        ListNode* tmp = head;

        if (head == nullptr || head -> next == nullptr){
            return head;
        }

        while (tmp != nullptr){
            ++lmap[tmp -> val];
            tmp = tmp -> next;
        }
        ListNode* start = new ListNode(-101, head);
        ListNode* prev = start;
        tmp = head;

        while (tmp != nullptr){
            if (lmap[tmp -> val] > 1){
                prev -> next = nullptr;
                tmp = tmp -> next;
            }
            else {
                prev -> next = tmp;
                prev =tmp;
                tmp = tmp -> next;
            }
        }

        return start -> next;

    }
};
// @lc code=end

