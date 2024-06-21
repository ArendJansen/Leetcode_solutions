/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
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
    void helper(TreeNode* root, int lr, int count, int & max){
        if (root == nullptr){
            return;
        }


        max = count > max ? count : max;
        // helper(root -> left,0,0,max);
        // helper(root -> right,0,0,max);

        // if (count == 0){
        //     helper(root -> right,1,count + 1, max);
        //     helper(root -> left, 0 ,count + 1, max);
        //     helper(root -> right,1,count , max);
        //     helper(root -> left, 0 ,count, max);
        //     return;
        // }

        if (lr == 0){
            helper(root -> right, 1, count + 1, max);
            helper(root -> left,0,1,max);
            

        }
        else{
            helper(root -> left, 0, count + 1, max);
            helper(root -> right,1,1,max);

        }


    }
    // void dfs(TreeNode* root, int & max){

    //     if (root == nullptr){
    //         return;
    //     }
    //     helper(root,0,0,max);
    //     dfs(root -> left,max);
    //     dfs(root -> right,max);

    // }
    int longestZigZag(TreeNode* root) {

        int max = 0;
        helper(root,0,0,max);
        helper(root,1,0,max);
        return max;

        
    }
};
// @lc code=end

