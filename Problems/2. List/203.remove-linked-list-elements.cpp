/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        // 用虚头的版本
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next) {
            if(cur->next->val == val) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            } else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
// @lc code=end

/* 不用虚头的版本
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 直接对头节点进行判断的版本
        while(head != nullptr && head->val == val) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        // 删除中间的非头结点
        ListNode* curr = head;
        while(curr && curr->next) { // 考虑到head为空的情况
            if(curr->next->val == val) {
                ListNode* tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};

*/