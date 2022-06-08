#include "iostream"

using namespace std;


/**
 * 链表倒数k个节点  依然双指针，快慢指针，初始时，一个在链表起点，一个在地k个节点
 * 注意判断一些边界条件
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

