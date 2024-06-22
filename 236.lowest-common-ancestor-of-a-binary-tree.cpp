/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasNode(TreeNode* root, int p){
        if (root ==  nullptr){
            return false;
        }
        if (root -> val == p){
            return true;
        }
        return hasNode(root -> left,p) || hasNode(root -> right, p);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root -> val == p -> val || root -> val == q -> val){
            return root;
        }
        bool p_left = hasNode(root -> left, p -> val);
        bool q_left = hasNode(root -> left, q -> val);
        bool p_right = hasNode(root -> right, p -> val);
        bool q_right = hasNode(root -> right, q -> val);

        if (p_left && q_right || q_left && p_right){
            return root;
        }
        else if (p_left && q_left){
            return lowestCommonAncestor(root -> left ,p ,q);
        }
        return lowestCommonAncestor(root -> right ,p ,q);

    }
};
// @lc code=end

