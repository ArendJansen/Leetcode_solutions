/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
bool is_symetric(TreeNode* p, TreeNode* q){

    bool ltrue;
    bool rtrue;

    if (q == nullptr && p == nullptr){
        return true;
    }
    if (q == nullptr || p == nullptr){
        return false;
    }

    if (p -> val != q -> val){
        return false;
    }

    ltrue = is_symetric(p -> left, q -> right);
    rtrue = is_symetric(p -> right, q -> left);

    if (ltrue == false || rtrue == false){
        return false;
    }
    return true;
}
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr){return true;}

        return is_symetric(root -> left, root -> right);
    }
};

// @lc code=end

