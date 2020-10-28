/**
 * 算法笔记 p329
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <set>
#include <stdio.h>

using namespace std;
int root[1001];

int findRoot(int start) {
    int res = start;
    while (root[res] != -1) res = root[res];

    while (root[start] != -1) {
        int tmp = root[start];
        root[start] = res;
        start = tmp;
    }
    return res;
}

set<int> hobbies[1001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        root[i] = -1;
        int k;
        scanf("%d:", &k);
        for (int j = 0; j < k; ++j) {
            int val;
            cin >> val;
            hobbies[i].insert(val);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto ite = hobbies[j].begin();
            bool token = false;
            while (ite != hobbies[j].end()) {
                auto isInsert = hobbies[i].find(*ite);
                if (isInsert != hobbies[i].end()) {
                    token = true;
                    break;
                }
                ++ite;
            }

            if (token) {
                int rootA = findRoot(i);
                int rootB = findRoot(j);
                if (rootA != rootB) {
                    root[rootB] = rootA;
                }
            }
        }
    }

    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        ++m[findRoot(i)];/**由于连接个关系后，需要统计老大节点*/
    }
    cout << m.size() << endl;
    vector<int> res;
    auto ite = m.begin();
    while (ite != m.end()) {
        res.push_back(ite->second);
        ++ite;
    }
    sort(res.begin(), res.end());
    for (int i = res.size() - 1; i >= 0; --i) {
        cout << res[i];
        if (i != 0) cout << " ";
    }
    return 0;
}
/**
 * 本题并查集的一个经典应用，且需统计每个连通块包含的个数
 * 本来是想把每个连通块老大索引的值设为本身(自己是自己的老大)，然后用map统一统计
 * 后来发现一个致命缺陷，当各个关系的连通都用并查集连通好后，可能并不是每个索引都指向直接祖先
 * 例如0索引对应的是0,1索引对应1,2,3对应1，此时遍历到1与0连通，则root数组变为0的索引为0,1的索引为0，但2,3对应的仍然是1，且此时遍历结束，
 * 则2,3的值并不是直接祖先0
 * 只能用findRoot找到直接祖先最为保险
 * */