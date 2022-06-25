//
// Created by admin on 2022/6/21.
//

#ifndef ALGORITHM_LISTNODE_H
#define ALGORITHM_LISTNODE_H

#include "vector"

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *constructLinkList(vector<int> array) {
    ListNode *head = new ListNode(-1);
    ListNode *p = head;

    for (auto val: array) {
        ListNode *cur = new ListNode(val);
        cur->next = p->next;
        p->next = cur;
        p = p->next;
    }

    return head->next;
}


#endif //ALGORITHM_LISTNODE_H
