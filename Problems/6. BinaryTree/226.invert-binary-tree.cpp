/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-11 22:20:11
 * @LastEditTime : 2022-12-11 22:45:44
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
    TreeNode* invertTree(TreeNode* root) {
        // 注意中序的情况！ 最后一次依然要翻转左子树！
        // 但如果统一代码，是可以正常用中序的！
        // 统一代码版本
        if(root == nullptr) 
            return root;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();
            if(node != nullptr) {
                st.pop();
                if(node->right) st.push(node->right);
                st.push(node);
                st.push(nullptr);
                if(node->left) st.push(node->left);
            } else {
                st.pop();
                node = st.top();
                st.pop();
                swap(node->left, node->right);
            }
        }
        return root;

        // 递归版本
        /*
        if(root == nullptr)
            return root;
        invertTree(root->left);
        swap(root->left, root->right);
        invertTree(root->left);
        return root;
        */
    }
};
// @lc code=end

/* 前序遍历, 后序遍历直接改一下就行
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
*/