#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
string str[100];
int visited[100];
int maxValue, n;

void dfs(int no, int length) {
    for (int i = 0; i < n; i++) {
        if (visited[i] < 2) {
            int m = str[no].length();
            int nn = str[i].length();
            for (int j = m - 1; j >= 0; j--) {
                int temp = j;
                for (int k = 0; k < nn && temp < m; k++) {
                    if (str[no].at(temp) == str[i].at(k)) temp++;
                    else break;
                }

                if (temp == m) {
                    visited[i]++;
                    length = length + nn - (m - j);
                    if (length > maxValue) maxValue = length;
                    dfs(i, length);
                    visited[i]--;
                    length = length - (nn - (m - j));
                }
            }
        }
    }
}

int main() {
    char start;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    cin >> start;
    maxValue = 0;
    for (int i = 0; i < n; i++) {
        if (str[i].at(0) == start) {
            memset(visited, 0, sizeof(visited));
            visited[i]++;
            dfs(i, str[i].length());
        }
    }
    cout << maxValue << endl;
}
/**
此题宏观上看就是暴力搜索 穷举所有可能的连接情况 比较出最大值
大致思路正确 但在穷举连接情况时 脑子像抽了一样
其实不用太高深的操作 只需在目标连接串的从末尾开始当做比对的起始点 与待判断的连接串进行比较即可
例如这种情况
beast
astonish
eastonish

虽然当第一个与第二个相连时 我们从逻辑上是可以与第三个相连 但判断算法是无法相连的 但由于搜索会穷举所有情况 所以 还会尝试第一个与第三个相连
所以是正确的 
*/
