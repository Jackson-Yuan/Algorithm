/**
 * 每行包含一个字符和一个整数n(0<n<41)，不同的字符表示不同的花纹，整数n表示等腰三角形的高。
 * 显然其底边长为2n-1。如果遇到@字符，则表示所做出来的样板三角形已经够了。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    char a;
    int n;
    bool isPrint = false;
    while (true) {
        cin >> a;
        if (a == '@') break;
        cin >> n;
        getchar();
        if (isPrint) cout << endl;
        vector<vector<char>> graph(n, vector<char>(2 * n - 1, ' '));
        int divide = (2 * n - 1) / 2;
        for (int i = 0; i < graph.size(); ++i) {
            if (i == 0) {
                graph[i][divide] = a;
            } else {
                graph[i][divide - i] = a;
                graph[i][divide + i] = a;
            }
        }

        for (int i = 0; i < graph[graph.size() - 1].size(); ++i) {
            graph[graph.size() - 1][i] = a;
        }

        for (int i = 0; i < graph.size(); ++i) { ;
            for (int j = 0; j <= divide; ++j) {
                cout << graph[i][j];
            }

            cout << endl;
            ++divide;
        }
        isPrint = true;
    }

    return 0;
}