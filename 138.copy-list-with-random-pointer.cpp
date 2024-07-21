/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <map>

using namespace std;


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr){
            return nullptr;
        }


        Node* tmp = head;
        Node* nhead = new Node(0);
        Node* prev = nhead;
        Node* tmp2 = nullptr; 
        std::map<Node*, Node*> lmap;

        while (tmp != nullptr){
            tmp2 = new Node(tmp -> val);
            lmap[tmp] = tmp2;
            prev -> next = tmp2;
            prev = tmp2;
            tmp2 = tmp2 -> next;
            tmp = tmp -> next;
        }
        tmp = head;
        tmp2 = nhead -> next;

        while (tmp != nullptr){
            if (tmp -> random != nullptr){
                tmp2 -> random = lmap[tmp -> random];
            }
            tmp = tmp -> next;
            tmp2 = tmp2 -> next;
        }
        return nhead -> next;
    }
};
// @lc code=end

