/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-10 22:31:55
 * @LastEditTime : 2022-12-11 15:14:03
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if(root != nullptr)
            st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();
            if(node != nullptr) {   // 不为空，则还没到处理的时候
                st.pop();   // 先pop，防止重复操作
                if(node->right)
                    st.push(node->right);
                if(node->left)
                    st.push(node->left);
                st.push(node);
                st.push(nullptr);
            } else {    // 到处理的时候了
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};
// @lc code=end

