/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        bool ltrue;
        bool rtrue;

        if (p == nullptr && q == nullptr){
            return true;
        }
        if (p == nullptr && q != nullptr){
            return false;
        }
        if (p != nullptr && q == nullptr){
            return false;
        }


        if (p -> val != q -> val){
            return false;
        }
        if (p -> val == q -> val){
            ltrue = isSameTree(p -> left, q -> left);
            rtrue = isSameTree(p -> right, q -> right);
        }
        if (ltrue == false || rtrue == false){
            return false;
        }
        return true;
    }
};
// @lc code=end

