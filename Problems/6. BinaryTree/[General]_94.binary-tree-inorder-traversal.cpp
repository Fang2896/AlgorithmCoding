/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-10 22:41:52
 * @LastEditTime : 2022-12-11 15:01:04
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
    /*
    中序中，用栈的时候无法同时解决访问结点和处理结点不一致的情况！
    那么我们就将访问的结点放入栈中，把要处理的结点也放入栈中，但是要做标记
    标记就是：将要处理的结点放入栈之后，紧接着放入一个空指针作为标记
    */
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if(root != nullptr)
            st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();
            if(node != nullptr) {
                st.pop();           // 将该结点弹出，避免重复操作，下面再将右中左结点，添加到栈中
                if(node->right)     // 添加右结点，空结点不入栈
                    st.push(node->right);
                st.push(node);      // 添加中结点
                st.push(nullptr);   // 中结点已经访问，但是还没有处理，加入空结点做个标记
                if(node->left)      // 添加左结点，空结点不入栈
                    st.push(node->left);
            } else {    // 只有遇到空结点的时候，才将下一个结点放入结果集
                st.pop();   // 空结点弹出
                node = st.top();    // 重新取栈元素
                st.pop();
                result.push_back(node->val);    // 加入到结果集
            }
        }
        return result;
    }
};
// @lc code=end