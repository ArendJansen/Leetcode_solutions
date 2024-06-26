/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr){
            return 0;
        }
        int depth = 1;

        int max_child_depth = 0;

        for (Node * child: root -> children){
            if (child != nullptr){
                max_child_depth = std::max(max_child_depth, maxDepth(child));
            }
        }

        return depth + max_child_depth;


    }
};
// @lc code=end

