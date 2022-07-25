#include "iostream"
#include "../link_list/ListNode.h"

using namespace std;

/**
 * ���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣����������������ཻ�ڵ㣬���� null ��
 *
 * ���ӣ�https://leetcode.cn/problems/intersection-of-two-linked-lists/
 * */

/**
 * ������򵥵�һ��˼·��ֱ�ӱ���һ������Ȼ���ٱ�������һ����Ѱ��һ����
 *
 * ����ṩ����һ��˼·������˫ָ�룬�ֱ������ͷ��㿪ʼ������ĳ��ָ��������ˣ�������һ��
 * ͷ��ʼ��ͷ��������ô�����뷨���ڣ������������ཻ�������ཻ��ǰ���ڵ���һ�����������������Ȼ������
 * ������һ������һ�������������һ��ͷ��㿪ʼ�����ⲽ����������ʹ������ָ�뻥��ͷ��������ʼ��˲�䣬�ཻ�㵽
 * ����ָ��Ľڵ����һ��
 *
 * �����ཻ������������ȳ��벻�ȳ�Ҳ�����������˵������
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
