/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        if (nums.empty()){
            return nullptr;
        }

        TreeNode* root = new TreeNode();
        int mid = (nums.size() -1) / 2;

        // std::cout << mid << "\n";

        root -> val = nums[mid];
        std::vector<int> lvec(nums.begin(), nums.begin() + mid);
        std::vector<int> rvec(nums.begin() + mid + 1, nums.end());
    
        root -> left = sortedArrayToBST(lvec);
        root -> right = sortedArrayToBST(rvec);

        return root;

    }
};
// @lc code=end

