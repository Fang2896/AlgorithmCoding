/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2023-01-10 20:52:34
 * @LastEditTime : 2023-01-10 21:35:01
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if(root == nullptr) return result;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();
            if(node != nullptr) {
                st.pop();   // 当前结点弹出避免重复操作
                if(node->right) st.push(node->right);

                st.push(node);
                st.push(nullptr);   // 我们需要处理中结点，所以加入null作为标记
                
                if(node->left) st.push(node->left);
            } else {    // 说明要开始处理了
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
/* iterative version
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr != nullptr || !st.empty()) {
            if(curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            } else {
                curr = st.top();
                st.pop();
                result.push_back(curr->val);
                curr = curr->right;
            }
        }
        return result;
    }
};
*/


/* Recursive Version
class Solution {
public:
    void traverse(TreeNode* curr, vector<int>& vec) {
        if(curr == nullptr)
            return;
        traverse(curr->left, vec);
        vec.push_back(curr->val);
        traverse(curr->right, vec);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
};
*/