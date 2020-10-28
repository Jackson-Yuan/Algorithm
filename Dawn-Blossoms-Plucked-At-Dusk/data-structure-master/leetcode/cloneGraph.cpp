#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    map<int, int> m;
    map<int, Node *> mm;
public:
    Node *cloneGraph(Node *node) {
        if (node == NULL) return NULL;
        Node *root = new Node(node->val);
        mm[root->val] = root;
        generate(root, node);
        return root;
    }

    void generate(Node *pre, Node *target) {
        m[target->val] = 1;
        vector<Node *> list = target->neighbors;
        for (int i = 0; i < list.size(); ++i) {
            if (m[list[i]->val] == 0) {
                Node *tmp = new Node(list[i]->val);
                mm[list[i]->val] = tmp;
                pre->neighbors.push_back(tmp);
                generate(tmp, list[i]);
            } else {
                pre->neighbors.push_back(mm[list[i]->val]);
            }
        }
    }
};
/**
 * 复制一个无向连通图，数据结构如上图
 * 其实依然时候dfs，bfs两大基本算法的拓展
 * 此题，主要繁琐在在dfs遍历过程中还原各个节点之间的连接关系
 * 此时Hash真是神技啊
 * */