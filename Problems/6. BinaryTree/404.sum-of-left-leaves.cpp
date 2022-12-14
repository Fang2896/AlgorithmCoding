/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-14 16:24:49
 * @LastEditTime : 2022-12-14 16:32:25
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> st;
        if(root == nullptr)
            return 0;
        st.push(root);
        int result = 0;
        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if(node->left && !node->left->left && !node->left->right)
                result += node->left->val;
            if(node->right)
                st.push(node->right);
            if(node->left)
                st.push(node->left);
        }
        return result;
    }
};
// @lc code=end

/* 递归法
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr)
            return 0;
        if(root->left == nullptr && root->right == nullptr)
            return 0;
        int leftValue = sumOfLeftLeaves(root->left);
        // 如果左子树就是一个左叶子？ 这是一个特殊情况！
        if(root->left && !root->left->left && !root->left->right)
            leftValue = root->left->val;
        int rightValue = sumOfLeftLeaves(root->right);
        int sum = leftValue + rightValue;
        return sum;
    }
};

*/
