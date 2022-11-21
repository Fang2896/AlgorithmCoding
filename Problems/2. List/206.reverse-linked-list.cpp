/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        // 从后往前反转指针
        // 先判断边缘条件
        // 假定思想：
        // 假定这个函数已经把后面的翻转完了，然后考虑接下来的操作！
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        // 递归调用
        ListNode* last = reverseList(head->next);   // 找到最后一个了
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};
// @lc code=end

/* 从前往后递归法
class Solution {
public:
    // 从前往后递归法
    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if(cur == nullptr) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        return reverse(cur, temp);
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr, head);
    }
};

*/



/* 双指针法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur != nullptr) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};
*/