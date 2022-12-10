/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-10 22:35:55
 * @LastEditTime : 2022-12-11 00:16:52
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        // 与前序遍历类似，先反转前序遍历顺序->中右左->翻转result数组->左右中
        vector<int> result;
        if(root == nullptr)
            return result;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            result.push_back(cur->val);
            if(cur->left)
                st.push(cur->left);
            if(cur->right)
                st.push(cur->right);
        }
        reverse(result.begin(), result.end());
        return result;
    } 
};
// @lc code=end

