/**
 * 输入一个数据n，代表n个叶节点，每个n节点都要权值，求这n个节点的霍夫曼树，即打印出WPL
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < n; ++i) {
            int current;
            cin >> current;
            q.push(current);
        }

        int res = 0;
        while (q.size() > 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();

            res += a + b;
            q.push(a + b);
        }

        cout << res << endl;
    }

    return 0;
}
/**
 * 利用优先队列来实现，这里还有一个重要的性质，
 * wpl的求法一是利用路径长度乘以叶子节点来实现
 * 而是直接利用非叶子节点的权值和做即可
 * */