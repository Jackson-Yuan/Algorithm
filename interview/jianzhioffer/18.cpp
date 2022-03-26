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
 * 18题删除重复子节点代码如下
 *
 * 还有一个给定单向链表的头指针与要删除的指针，在o（1）时间内删去
 * 这是个脑筋急转弯，其实就是把要删去节点的下一个节点的值复制到这个节点
 * 然后删去下一个节点，等价于删除。但如果删去的节点在表尾，就只好从头节点遍历到要删去节点的前驱
 * 但平均复杂度还是o（1）
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

