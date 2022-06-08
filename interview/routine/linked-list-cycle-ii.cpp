#include "iostream"

using namespace std;

/**
 * 给定一个链表的头节点 head，返回链表开始入环的第一个节点。如果链表无环，则返回null。
 * 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
 * 为了表示给定链表中的环，评测系统内部使用整数 pos来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，
 * 则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
 * 不允许修改 链表。
 * 链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
 * */

/**
 * 记住一个规律，快慢指针相遇的点一定在环内，且一定在慢指针的第一圈就碰到
 *
 * 此时从链表第一个节点开始，同时与慢指针前进，第一个相遇的头节点一定是环的起点。
 * */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;

        ListNode *slow = head;
        ListNode *fast = head;


        bool isFind = false;
        while (fast && fast->next && slow) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                isFind = true;
                break;
            }
        }


        if (!isFind) return NULL;

        ListNode *p = head;
        while (p != slow) {
            p = p->next;
            slow = slow->next;
        }

        return p;
    }
};

