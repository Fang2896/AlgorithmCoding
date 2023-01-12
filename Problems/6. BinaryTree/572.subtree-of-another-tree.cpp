/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2023-01-11 20:00:24
 * @LastEditTime : 2023-01-11 20:25:24
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
// 进阶方法是KMP和树哈希，以后有机会一定要再刷一遍
    // 深度优先搜索暴力匹配，也是挺慢的。但是稍微比原来的暴力函数好点
    // Your runtime beats 73.38 % of cpp submissions
    // Your memory usage beats 54.68 % of cpp submissions (28.1 MB)
    bool check(TreeNode* p, TreeNode* q) {
        if(!q && !p) {
            return true;
        }
        if((p && !q) || (!p && q) || (p->val != q->val)) {
            return false;
        }
        return check(p->left, q->left) && check(p->right, q->right);
    }
    
    bool dfs(TreeNode* p, TreeNode *q) {
        if(!p)
            return false;
        return check(p, q) || dfs(p->left, q) || dfs(p->right, q);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }
};
// @lc code=end

/* 先写出比较两棵树是否相同的函数，再每个结点一起比
class Solution {
public:
    // 很慢的一种方法：(用的是迭代，递归的话代码简洁些)
    // 182/182 cases passed (56 ms)
    // Your runtime beats 6.11 % of cpp submissions
    // Your memory usage beats 5.01 % of cpp submissions (49.6 MB)
    
    bool isSametree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)    return true;
        queue<TreeNode*> que;
        que.push(p);    que.push(q);
        while(!que.empty()) {
            TreeNode* node1 = que.front();  que.pop();
            TreeNode* node2 = que.front(); que.pop();
            if(node1 == nullptr && node2 == nullptr) {
                continue;
            }
            else if((node1 == nullptr && node2 != nullptr) ||
                (node1 != nullptr && node2 == nullptr)) {
                return false;
            } else if(node1 != nullptr && node2 != nullptr) {
                if(node1->val != node2->val) {
                    return false;
                }
            }
            que.push(node1->left);
            que.push(node2->left);
            que.push(node1->right);
            que.push(node2->right);
        }
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr)   return true;
        stack<TreeNode*> st;
        bool flag = false;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            flag = isSametree(node, subRoot);
            if(flag == true) {
                break;
            }
            if(node->right) st.push(node->right);
            if(node->left)  st.push(node->left);
        }
        return flag;
    }
};

*/