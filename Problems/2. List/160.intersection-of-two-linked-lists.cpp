/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        while (curA != NULL) { // 求链表A的长度
            lenA++;
            curA = curA->next;
        }
        while (curB != NULL) { // 求链表B的长度
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        // 让curA为最长链表的头，lenA为其长度
        if (lenB > lenA) {
            swap (lenA, lenB);
            swap (curA, curB);
        }
        // 求长度差
        int gap = lenA - lenB;
        // 让curA和curB在同一起点上（末尾位置对齐）
        while (gap--) {
            curA = curA->next;
        }
        // 遍历curA 和 curB，遇到相同则直接返回
        while (curA != NULL) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};
// @lc code=end

/* 自己写的代码 有点臃肿
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 老套路，快慢指针
        // 记录链表a和b的偏差以及哪个链表更短
        // flag=0代表a更短，flag=1代表b更短
        int bias = 0, flag = 0; 
        ListNode* tempA = headA, *tempB = headB;
        // 先让其中一个指针指向末尾
        while(tempA != nullptr && tempB != nullptr) {
            tempA = tempA->next;
            tempB = tempB->next;
        }
        // 计算bias, 并将两个temp指针移动
        if(tempA == nullptr) {          // a更短
            flag = 0;
            while(tempB != nullptr) {   
                bias++;
                tempB = tempB->next;
            }
        } else if (tempB == nullptr) {  // b更短
            flag = 1;
            while(tempA != nullptr) {
                bias++;
                tempA = tempA->next;
            }
        }
        // 重新开始
        tempA = headA, tempB = headB;
        // 先将更长的链表移动bias步
        while(bias--) {
            if(flag == 0) {
                tempB = tempB->next;
            } else {
                tempA = tempA->next;
            }
        }
        // 齐头并进，直到遇到指针相同
        while(tempA != nullptr && tempB!= nullptr && tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }
        if(tempA == nullptr) return nullptr;
        else if(tempB == nullptr) return nullptr;
        else return tempA;

    }
};
*/