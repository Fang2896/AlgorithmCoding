/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next;
            List* tmp1 = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = tmp;
            cur->next->next->next = tmp1;
            cur = cur->next->next;
        }
        return dummyHead->next;
    }
};
// @lc code=end

/*  自己写的第一版代码，丑的一批
Your runtime beats 4.03 % of cpp submissions
Your memory usage beats 21.34 % of cpp submissions (7.4 MB)
--- --- --- --- --- ---
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        ListNode* dummyHead = new ListNode(0);
        ListNode* left = dummyHead;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* right = second->next;

        while( 1 ) {
            left->next = second;
            first->next = right;
            second->next = first;
            if(right == nullptr) return dummyHead->next;
            if(right->next == nullptr) return dummyHead->next;
            left = first;
            first = right;
            second = right->next;
            right = second->next;
        }

    }
};
*/

