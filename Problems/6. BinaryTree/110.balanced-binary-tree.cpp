/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2023-01-12 20:31:05
 * @LastEditTime : 2023-01-12 21:00:05
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    // 这个函数通过栈模拟的后序遍历来找每一个节点的高度（即通过求传入结点为根节点的最大深度，来求高度！）
    // 就是暴力遍历。很低效
    int getDepth(TreeNode* node) {
        stack<TreeNode*> st;
        if(node != nullptr) st.push(node);
        int depth = 0;  // 记录深度
        int result = 0;
        while(!st.empty()) {
            TreeNode* node = st.top();
            if(node != nullptr) {
                // st.pop();
                // st.push(node);
                st.push(nullptr);
                depth++;
                if(node->right) st.push(node->right);
                if(node->left)  st.push(node->left);
            } else {
                st.pop();
                node = st.top();
                st.pop();
                depth--;
            }
            result = result > depth ? result : depth;
        }
        return result;
    }
    bool isBalanced(TreeNode* root) {
        // 迭代法
        stack<TreeNode*> st;
        if(root == nullptr) return true;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if(abs(getDepth(node->left) - getDepth(node->right)) > 1) {
                return false;
            }
            if(node->right) st.push(node->right);
            if(node->left)  st.push(node->left);
        }
        return true;
    }
};
// @lc code=end

/* 递归求深度 来检测平衡二叉树
class Solution {
public:
    int getHeight(TreeNode* node) {
        if(node == nullptr) return 0;
        int leftHeight = getHeight(node->left);
        if(leftHeight == -1)    return -1;
        int rightHeight = getHeight(node->right);
        if(rightHeight == -1)   return -1;
        if(abs(leftHeight - rightHeight) > 1)   return -1;
        return max(rightHeight, leftHeight) + 1;   
    }
    bool isBalanced(TreeNode* root) {
        // 思路就是比较左右子树的高度差，如果刚好差小于等于1，就true
        if(root == nullptr) return true;
            return getHeight(root) == -1 ? false : true;
    }
};
*/