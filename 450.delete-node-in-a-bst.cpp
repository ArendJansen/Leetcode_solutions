/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {

        TreeNode* prev = root;
        TreeNode* fin = root;

        if (root == nullptr){
            return nullptr;
        }

        if (root -> val == key){
            if (root -> left == nullptr && root -> right == nullptr){
                return nullptr;
            }
            if (root -> right == nullptr){
                fin = root -> left;
            }
            else if (root -> left == nullptr){
                fin = root -> right;
            }
            else {
                fin = root -> right;
                TreeNode* curr = fin;
                while (curr -> left != nullptr){
                    curr = curr -> left;
                }
                curr -> left = root -> left;
            }
            return fin;
        }

        while (root != nullptr){
            std::cout << root -> val << "\n";
            std::cout << prev -> val << "\n\n";

            if (root -> val == key){
                if (prev -> val > root -> val){
                    if (root -> right == nullptr){
                        prev -> left = root -> left;
                        break;
                    }
                    else {
                        prev -> left = root -> right;
                        TreeNode * curr = root -> right;
                        
                        while (curr -> left != nullptr){
                            curr = curr -> left;
                        }
                        curr -> left = root -> left;
                        break;
                        
                    }
                }
                else if (prev -> val < root -> val){
                    if (root -> left == nullptr){
                        prev -> right = root -> right;
                        break;
                    }
                    else {
                        prev -> right = root -> left;
                        TreeNode * curr = root -> left;
                        while (curr -> right != nullptr){
                            curr = curr -> right;
                        }
                        curr -> right = root -> right;
                        break;
                        
                    }                    
                }

            }
            else if (root -> val > key){
                prev = root;
                root = root -> left;
            }
            else {
                prev = root;
                root = root -> right;
            }
        }

        return fin;
    }
};
// @lc code=end

