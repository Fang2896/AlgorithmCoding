/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        while(fast!=nullptr && fast->next!=nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while(index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return nullptr;
    }
};
// @lc code=end

