/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-10 22:31:55
 * @LastEditTime : 2022-12-10 23:33:26
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
        stack<TreeNode*> st;
        vector<int> result;
        if(root == nullptr)
            return result;
        st.push(root);
        while(!st.empty()) {
            // pop出一个，然后压入它的左右孩子，如果有的话
            TreeNode* cur = st.top();
            st.pop();
            if(cur->right != nullptr)
                st.push(cur->right);
            if(cur->left != nullptr)
                st.push(cur->left);
            result.push_back(cur->val);
        }
        return result;
    }
};
// @lc code=end

