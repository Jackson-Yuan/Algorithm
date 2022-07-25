#include "iostream"
#include "ListNode.h"


/**
 * 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
 * 链接：https://leetcode.cn/problems/palindrome-linked-list/
 * */

/**
 * 本题最简单粗暴的一个方法就是将链表数据复制到数组，利用双指针从一头一尾
 * 但空间复杂度高
 * 下面介绍一个空间复杂度低的算法
 *
 * 利用了翻转和块面指针操作
 *
 * 先利用快慢指针找出中点mid，以mid为起点，翻转中点至末尾的链表
 * 随后分别从头结尾与尾结点以类似数组判断回文的方式开始遍历，进行检查
 * 值得注意的是，while的终止条件，因为在链表中没法用索引，所以这边循环的终止条件为：从头结点开始遍历，且不能等于mid
 *
 * 同时注意判断完后注意还原链表
 * */

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (head == nullptr) return true;

        ListNode *mid = findMid(head);
        ListNode *revHead = reverse(mid);

        ListNode *first = head;
        ListNode *second = revHead;

        bool res = true;
        while (first && second && first != mid) {
            if (first->val != second->val) {
                res = false;
                break;
            }

            first = first->next;
            second = second->next;
        }

        /**
         * 这边翻转，只要将翻转后的头结点再翻一次即可，无需额外的连接操作
         * 因为mid节点的前驱还连着mid
         * */
        reverse(revHead);
        print(head);
        return res;
    }


    ListNode *reverse(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;

        while (cur) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        return pre;
    }


    ListNode *findMid(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    void print(ListNode *head) {
        ListNode *p = head;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
    }
};

