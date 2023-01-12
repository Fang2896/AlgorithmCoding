/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2023-01-11 22:04:36
 * @LastEditTime : 2023-01-11 22:38:43
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftDepth = 0, rightDepth = 0;
        while(left) {   // 求左子树深度
            left = left->left;
            leftDepth++;
        }
        while(right) {
            right = right->right;
            rightDepth++;
        }
        if(leftDepth == rightDepth) {
            return (2 << leftDepth) - 1;    // 用完全二叉树公式
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
// @lc code=end


/* O(n)的做法，直接递归
class Solution {
public:
    int getNodeSum(TreeNode* node) {
        if(node == nullptr) return 0;
        int leftSum = getNodeSum(node->left);
        int rightSum = getNodeSum(node->right);
        return leftSum + rightSum + 1;
    }
    int countNodes(TreeNode* root) {
        return getNodeSum(root);
    }
};

*/