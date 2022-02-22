#include "iostream"

using namespace std;


/**
 * ������k���ڵ�  ��Ȼ˫ָ�룬����ָ�룬��ʼʱ��һ����������㣬һ���ڵ�k���ڵ�
 * ע���ж�һЩ�߽�����
 * */
struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode *getKthFromEnd(ListNode *head, int k) {
        if (head == NULL || k == 0) return NULL;
        ListNode *second = head;
        for (int i = 0; i < k - 1; ++i) {
            second = second->next;
            if (second == NULL) return NULL;
        }

        ListNode *first = head;

        while (second->next) {
            first = first->next;
            second = second->next;
        }

        return first;
    }
};

