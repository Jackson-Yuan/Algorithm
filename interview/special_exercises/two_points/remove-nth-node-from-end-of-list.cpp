#include "iostream"
#include "vector"

/**
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 * 链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 * */

/**
 * 本题两个要点：
 * 1、设立链表需节点，免去对头节点的一些判定操作
 * 2、双指针，实现一次遍历
 * */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *virtu = new ListNode(-1, head);
        ListNode *first = head;
        ListNode *second = virtu;

        for (int i = 0; i < n; ++i) {
            first = first->next;
        }

        while (first) {
            first = first->next;
            second = second->next;
        }

        ListNode *target = second->next;
        second->next = target->next;
        ListNode *ans = virtu->next;
        delete virtu;
        delete target;
        return ans;

    }
};
