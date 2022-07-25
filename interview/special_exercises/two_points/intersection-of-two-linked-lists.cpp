#include "iostream"
#include "../link_list/ListNode.h"

using namespace std;

/**
 * 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
 *
 * 连接：https://leetcode.cn/problems/intersection-of-two-linked-lists/
 * */

/**
 * 本题最简单的一个思路：直接保存一条链表，然后再遍历另外一条，寻找一样的
 *
 * 这边提供另外一种思路，利用双指针，分别从两个头结点开始遍历，某个指针遍历完了，从另外一个
 * 头开始重头遍历。这么做的想法再于：两个链表若相交，若在相交点前，节点数一样，则遍历过程中自然会碰到
 * 但若不一样，当一个遍历完从另外一个头结点开始遍历这步操作，可以使得两个指针互换头结点遍历开始的瞬间，相交点到
 * 两个指针的节点个数一样
 *
 * 若不相交，则两个链表等长与不等长也可以用上面的说法解释
 * */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;

        ListNode *pA = headA;
        ListNode *pB = headB;

        while (pA != pB) {
            pA = (pA == NULL ? headB : pA->next);
            pB = (pB == NULL ? headA : pB->next);
        }

        return pA;
    }
};
