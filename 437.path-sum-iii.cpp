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
    void helper(TreeNode * root, long long targetsum, int & total){
        if (root == nullptr){
            return;
        }

        pathSum2(root, targetsum, total);

        helper(root -> left, targetsum ,total);
        helper(root -> right, targetsum , total);
        // helper(root -> left, originals ,originals, total);
        // helper(root -> right, originals , originals, total);
    }
    void pathSum2(TreeNode* root, long long targetsum, int & total){
        if (root == nullptr){
            return;
        }
        pathSum2(root -> left, targetsum - root -> val, total);
        pathSum2(root -> right, targetsum - root -> val, total);
        if (targetsum - root -> val == 0){
            ++total;
        }

    }
    int pathSum(TreeNode* root, int targetSum) {
        int total = 0;
        helper(root, targetSum, total);

        return total;
    }
};
// @lc code=end

