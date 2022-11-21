/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        while(n-- && fast!=nullptr) 
            fast = fast->next;
        fast = fast->next;
        while(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummyHead->next;
    }
};
// @lc code=end

/* 自己写的版本
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 双指针法
        ListNode* fast = head, *slow = head;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* prev = dummyHead;
        while(--n) 
            fast = fast->next;
        while(fast->next != nullptr) {
            prev = prev->next;
            slow = slow->next;
            fast = fast->next;
        }
        // 此时slow到达了该删除的结点位置
        prev->next = slow->next;
        slow->next = nullptr;
        delete slow;
        return dummyHead->next;
    }
};
*/
