/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        std::vector<int> results;
        
        if (root == nullptr) return results;
        results.push_back(root -> val);
        
        std::vector<int> lval = preorderTraversal(root -> left);
        for (std::size_t i = 0; i < lval.size(); ++i) {
            results.push_back(lval[i]);
        }
        std::vector<int> rval = preorderTraversal(root -> right);
        for (std::size_t i = 0; i < rval.size(); ++i) {
            results.push_back(rval[i]);
        }
        
        return results;
                                 
    }
};
// @lc code=end

