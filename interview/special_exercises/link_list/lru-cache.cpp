#include "iostream"
#include "unordered_map"

using namespace std;
/**
 * 请你设计并实现一个满足LRU (最近最少使用) 缓存 约束的数据结构。
 * 实现 LRUCache 类：
 * LRUCache(int capacity) 以 正整数 作为容量capacity 初始化 LRU 缓存
 * int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
 * void put(int key, int value)如果关键字key 已经存在，则变更其数据值value ；如果不存在，则向缓存中插入该组key-value 。如果插入操作导致关键字数量超过capacity ，则应该 逐出 最久未使用的关键字。
 * 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
 * 链接：https://leetcode.cn/problems/lru-cache
 * */

/**
 * hash + 双向（循环）链表
 * */
struct Node {
    int key;
    int val;
    Node *next;
    Node *pre;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->next = this;
        this->pre = this;
    }
};

class LRUCache {
private:
    Node *head;
    int capacity;
    unordered_map<int, Node *> map;

public:
    LRUCache(int capacity) {
        this->head = new Node(-1, -1);
        this->capacity = capacity;
    }

    int get(int key) {
        auto ite = map.find(key);

        if (ite == map.end()) return -1;
        Node *target = ite->second;
        Node *pre = target->pre;
        Node *next = target->next;

        pre->next = next;
        next->pre = pre;

        headInsert(target);

        return target->val;

    }

    void put(int key, int value) {
        Node *target;
        auto ite = map.find(key);
        if (ite != map.end()) {
            target = ite->second;
            target->val = value;

            Node *pre = target->pre;
            Node *next = target->next;
            pre->next = next;
            next->pre = pre;
        } else {
            target = new Node(key, value);
            map[key] = target;

            if (map.size() - 1 >= capacity) {
                Node *deleteNode = head->pre;
                Node *tail = deleteNode->pre;
                tail->next = head;
                head->pre = tail;

                map.erase(deleteNode->key);
                delete deleteNode;
            }
        }

        headInsert(target);

    }


    void headInsert(Node *target) {
        target->next = this->head->next;
        target->next->pre = target;
        this->head->next = target;
        target->pre = this->head;
    }
};

int main() {
    auto *cache = new LRUCache(2);
    cout << cache->get(2) << endl;
    cache->put(2, 6);
    cout << cache->get(1) << endl;
    cache->put(1, 5);
    cache->put(1, 2);
    cout << cache->get(1) << endl;
    cout << cache->get(2) << endl;


}