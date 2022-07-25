#include "iostream"
#include "ListNode.h"


/**
 * ����һ���������ͷ�ڵ� head �������жϸ������Ƿ�Ϊ������������ǣ����� true �����򣬷��� false ��
 * ���ӣ�https://leetcode.cn/problems/palindrome-linked-list/
 * */

/**
 * ������򵥴ֱ���һ���������ǽ��������ݸ��Ƶ����飬����˫ָ���һͷһβ
 * ���ռ临�Ӷȸ�
 * �������һ���ռ临�Ӷȵ͵��㷨
 *
 * �����˷�ת�Ϳ���ָ�����
 *
 * �����ÿ���ָ���ҳ��е�mid����midΪ��㣬��ת�е���ĩβ������
 * ���ֱ��ͷ��β��β��������������жϻ��ĵķ�ʽ��ʼ���������м��
 * ֵ��ע����ǣ�while����ֹ��������Ϊ��������û�����������������ѭ������ֹ����Ϊ����ͷ��㿪ʼ�������Ҳ��ܵ���mid
 *
 * ͬʱע���ж����ע�⻹ԭ����
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
         * ��߷�ת��ֻҪ����ת���ͷ����ٷ�һ�μ��ɣ������������Ӳ���
         * ��Ϊmid�ڵ��ǰ��������mid
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

