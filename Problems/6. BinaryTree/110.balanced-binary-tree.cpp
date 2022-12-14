/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-13 19:26:31
 * @LastEditTime : 2022-12-14 15:25:48
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
    // 通过栈模拟的后序遍历找每一个节点的高度，通过求传入节点为
    // 根节点的最大深度来求的高度
    int getDepth(TreeNode* cur) {
        stack<TreeNode*> st;
        if(cur != nullptr) 
            st.push(cur);
        int depth = 0;
        int result = 0;
        while(!st.empty()) {
            TreeNode* node = st.top();
            if(node != nullptr) {
                st.pop();
                st.push(node);
                st.push(nullptr);
                depth++;
                if(node->right)
                    st.push(node->right);
                if(node->left)
                    st.push(node->left);
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
    // 再用栈来模拟后序遍历
    // 遍历每一个节点的时候，再去判断左右孩子的高度是否符合
    bool isBalanced(TreeNode* root) {
        stack<TreeNode*> st;
        if(root == nullptr)
            return true;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if(abs(getDepth(node->left) - getDepth(node->right)) > 1) 
                return false;
            if(node->right)
                st.push(node->right);
            if(node->left)
                st.push(node->left);
        }
        return true;
    }
};
// @lc code=end

/* 后序遍历求递归方法
class Solution {
public:
    // -1则不是平衡二叉树，否则返回当前结点为根的高度
    int getHeight(TreeNode* node) {
        if(node == nullptr)
            return 0;
        // 开始判断
        int leftHeight = getHeight(node->left);
        if(leftHeight == -1)
            return -1;
        int rightHeight = getHeight(node->right);
        if(rightHeight == -1)
            return -1;
        
        int result;
        if(abs(leftHeight - rightHeight) > 1)
            result = -1;
        else
            result = 1 + max(leftHeight, rightHeight);
        return result;
    }
    bool isBalanced(TreeNode* root) {
        // 求高度，则用后序遍历
        return getHeight(root) == -1 ? false : true;

    }
};

*/