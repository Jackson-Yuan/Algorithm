#include "iostream"
#include "vector"

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

/**
 * 18��ɾ���ظ��ӽڵ��������
 *
 * ����һ���������������ͷָ����Ҫɾ����ָ�룬��o��1��ʱ����ɾȥ
 * ���Ǹ��Խת�䣬��ʵ���ǰ�Ҫɾȥ�ڵ����һ���ڵ��ֵ���Ƶ�����ڵ�
 * Ȼ��ɾȥ��һ���ڵ㣬�ȼ���ɾ���������ɾȥ�Ľڵ��ڱ�β����ֻ�ô�ͷ�ڵ������Ҫɾȥ�ڵ��ǰ��
 * ��ƽ�����ӶȻ���o��1��
 * */
class Solution {
public:
    ListNode *deleteDuplicateNode(ListNode *head) {
        ListNode *pr = head;
        if (pr == NULL) return head;
        ListNode *p = head->next;
        if (p == NULL) return head;

        while (p) {
            if (pr->val == p->val) {
                pr->next = p->next;
                delete p;
                p = pr->next;
                continue;
            }

            pr = p;
            p = p->next;
        }

        return head;
    }


    void printLink(ListNode *head) {
        ListNode *p = head;

        while (p) {
            cout << p->val << " ";
            p = p->next;
        }

        cout << endl;
    }

    ListNode *constructLink(vector<int> &nums) {
        ListNode *head = new ListNode(nums[0]);
        ListNode *p = head;

        for (int i = 1; i < nums.size(); ++i) {
            ListNode *cur = new ListNode(nums[i]);
            p->next = cur;
            p = cur;
        }

        return head;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};

    Solution solution;
    ListNode *head = solution.constructLink(nums);
    solution.printLink(head);
    head = solution.deleteDuplicateNode(head);
    solution.printLink(head);

}

