/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2023-01-11 19:00:42
 * @LastEditTime : 2023-01-11 19:41:18
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        // 栈也是可以的
    }
};
// @lc code=end


/* Queue Version
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // 核心思想：内侧是否相等，外侧是否相等？
        if(root == nullptr) return true;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while(!que.empty()) {
            TreeNode* leftNode = que.front();   que.pop();
            TreeNode* rightNode = que.front();  que.pop();
            if(leftNode == nullptr && rightNode == nullptr)
                continue;
            if((leftNode == nullptr && rightNode != nullptr) ||
                (leftNode != nullptr && rightNode == nullptr))
                return false;
            if(leftNode != nullptr && rightNode != nullptr) {
                if(leftNode->val != rightNode->val) {
                    return false;
                }
            }
            que.push(leftNode->left);
            que.push(rightNode->right);
            que.push(leftNode->right);
            que.push(rightNode->left);
        }
        return true;
    }
};
*/


/* Recursive Version
class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        if(left == nullptr && right != nullptr) return false;
        else if(left != nullptr && right == nullptr)    return false;
        else if(left == nullptr && right == nullptr)    return true;
        else if(left->val != right->val)    return false;
        // 下面的情况是 左右都不为空，且数值相同的时候， 就是比较外侧和内侧
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        return outside && inside;
    }
    bool isSymmetric(TreeNode* root) {
        // 思路： 层序遍历可以输出
        return compare(root->left, root->right);
    }
};
*/