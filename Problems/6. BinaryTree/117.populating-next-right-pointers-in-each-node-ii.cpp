/****************************************************************
 * @file name    : File name
 * @Description  : 
 * @Version      : 0.0
 * @Author       : M1kanN
 * @Date         : 2022-12-11 17:05:56
 * @LastEditTime : 2022-12-11 20:59:47
 ****************************************************************/
/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if(root != nullptr) 
            que.push(root);
        while(!que.empty()) {
            int size = que.size();
            Node* preNode;
            Node* node;
            for(int i = 0; i < size; i++) {
                if(i == 0) {
                    preNode = que.front();
                    que.pop();
                    node = preNode;
                } else {
                    node = que.front();
                    que.pop();
                    preNode->next = node;
                    preNode = preNode->next;
                }
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }
            preNode->next = nullptr;
        }
        return root;
    }
};
// @lc code=end

