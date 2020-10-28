//
// Created by Lenovo on 2020/6/9.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
struct point {
    int key;
    int val;
    point *next;
    point *pre;
};

class LRUCache {
private:
    int capacity;
    map<int, point *> m;
    point *head;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new point;
        head->next = head->pre = head;
    }

    int get(int key) {
        auto ite = m.find(key);
        if (ite == m.end()) return -1;
        else {
            point *cur = ite->second;
            point *pre = cur->pre, *next = cur->next;
            pre->next = next;
            next->pre = pre;
            cur->next = head->next;
            cur->pre = head;
            cur->next->pre = cur;
            head->next = cur;
            return cur->val;
        }
    }

    void put(int key, int value) {
        auto ite = m.find(key);
        if (ite == m.end()) {
            if (m.size() >= this->capacity) {
                point *tmp = head->pre;
                m.erase(tmp->key);
                head->pre = tmp->pre;
                tmp->pre->next = head;
                delete tmp;
            }
            point *cur = new point;
            cur->key = key;
            cur->val = value;
            cur->pre = head;
            cur->next = head->next;
            cur->next->pre = cur;
            head->next = cur;
            m[key] = cur;
        } else {
            point *cur = ite->second;
            cur->val = value;
            point *pre = cur->pre, *next = cur->next;
            pre->next = next;
            next->pre = pre;
            cur->next = head->next;
            cur->pre = head;
            cur->next->pre = cur;
            head->next = cur;
        }
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;
}