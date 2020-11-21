#include "iostream"

using namespace std;

struct ListNode {
    int val;

    ListNode *next;
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        return sortList(head, NULL);
    }


    ListNode *sortList(ListNode *head, ListNode *end) {
        if (head == NULL) return head;
        if (head->next == end) {
            head->next = NULL;
            return head;
        }

        ListNode *fast = head, *slow = head;
        while (fast != end) {
            slow = slow->next;
            fast = fast->next;
            if (fast != end) fast = fast->next;
        }

        ListNode *mid = slow;
        ListNode *a = sortList(head, mid);
        ListNode *b = sortList(mid, end);
        ListNode *ans = merge(a, b);
        return ans;
    }

    ListNode *merge(ListNode *a, ListNode *b) {
        ListNode *tmpHead = new ListNode;
        ListNode *tmp = tmpHead;
        while (a != NULL && b != NULL) {
            if (a->val <= b->val) {
                tmp->next = a;
                a = a->next;
            } else {
                tmp->next = b;
                b = b->next;
            }

            tmp = tmp->next;
        }

        if (a != NULL) tmp->next = a;
        else tmp->next = b;

        ListNode *ans = tmpHead->next;
        delete tmpHead;
        return ans;
    }
};
/**
 * 链表的归并排序，其实就是仿照数组的归并排序思路
 * 但由于链表的检索不像数组索引来的方便，且两个链表进行归并时，必须最后都以空串结尾
 * 所以必须进行判断 :
 * if(head->next == end) {
 * head->next = NULL;
 * return head;
 * }
 * 这句话就是用来保证归并的两个链表最后说为NULL的（即递归分裂到只有单个时，单个的next置为NULL，这样就会保证归并时与归并后所得的串末尾均为NULL）
 * */