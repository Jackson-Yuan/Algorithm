#include "iostream"

using namespace std;

/**
 * ����һ�������ͷ�ڵ� head����������ʼ�뻷�ĵ�һ���ڵ㡣��������޻����򷵻�null��
 * �����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ���
 * Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������ pos����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ������� pos �� -1��
 * ���ڸ�������û�л���ע�⣺pos ����Ϊ�������д��ݣ�������Ϊ�˱�ʶ�����ʵ�������
 * �������޸� ����
 * ���ӣ�https://leetcode-cn.com/problems/linked-list-cycle-ii
 * */

/**
 * ��סһ�����ɣ�����ָ�������ĵ�һ���ڻ��ڣ���һ������ָ��ĵ�һȦ������
 *
 * ��ʱ�������һ���ڵ㿪ʼ��ͬʱ����ָ��ǰ������һ��������ͷ�ڵ�һ���ǻ�����㡣
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

