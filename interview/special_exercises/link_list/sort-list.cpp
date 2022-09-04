#include "iostream"
#include "ListNode.h"

using namespace std;
/**
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表。
 * 链接：https://leetcode.cn/problems/sort-list/
 * */

/**
 * 最直观的方法，值保存在一个数组里，然后数组排序，再还原成链表
 *
 * 如果需要直接对链表进行排序，且为nlogn复杂度，参考归并排序思路
 * 先找出链表的中间节点mid（利用快慢指针），mid前面（不包含mid）成一条链
 * mid后面（包含mid）成一条链，mid指针的前驱pre，pre->next需要设置为null，将这两条链断开
 * 不然进行两个链表排序时，遍历链的结束条件或许永远不会满足
 * 同时注意递归的结束条件：1、为空；2、后继为空
 *
 * */

/**
 * 此外还有一种空间复杂度只为常数级别的解决方案，力扣题解自行查阅（因为感觉没必要）
 * */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        ListNode *low = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            low = low->next;
            fast = fast->next->next;
        }

        /**
         * 此处分割成两条节点一节点是head这个没啥好说的
         * 另外一个节点只能是low，不要图省事变成low->next
         * 这么搞你会发现，当割到只剩两个节点时，这种割法压根割不下来
         * 递归无限嵌套导致直接爆栈
         * */
        ListNode *head1 = head;
        ListNode *head2 = low;

        ListNode *p = head;
        while (p->next != low) {
            p = p->next;
        }

        p->next = nullptr;

        ListNode *a = sortList(head1);
        ListNode *b = sortList(head2);

        ListNode *res = merge(a, b);

        return res;
    }


    ListNode *merge(ListNode *a, ListNode *b) {
        ListNode *head = new ListNode(-1);
        ListNode *p = head;

        while (a != nullptr && b != nullptr) {
            ListNode *tmp = nullptr;
            if (a->val > b->val) {
                tmp = b;
                b = b->next;
            } else {
                tmp = a;
                a = a->next;
            }

            tmp->next = p->next;
            p->next = tmp;
            p = p->next;
        }


        if (a != nullptr) {
            p->next = a;
        }

        if (b != nullptr) {
            p->next = b;
        }

        return head->next;
    }
};

int main() {
    vector<int> array = {1};

    ListNode *head = constructLinkList(array);

    Solution solution;
    solution.sortList(head);
}