/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2023-01-11 21:24:33
 * @LastEditTime : 2023-01-11 22:02:53
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int getDepth(TreeNode* root) {
        int result = 0;
        if(root == nullptr) return result;
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        if(root->right == nullptr && root->left != nullptr) {
            return 1 + leftDepth;
        }
        if(root->right != nullptr && root->left == nullptr) {
            return 1 + rightDepth;
        }
        return 1 + min(rightDepth, leftDepth);
    }
    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};
// @lc code=end

