/**
问题描述
　　小明的实验室有N台电脑，编号1~N。原本这N台电脑之间有N-1条数据链接相连，恰好构成一个树形网络。在树形网络上，任意两台电脑之间有唯一的路径相连。


　　不过在最近一次维护网络时，管理员误操作使得某两台电脑之间增加了一条数据链接，于是网络中出现了环路。环路上的电脑由于两两之间不再是只有一条路径，使得这些电脑上的数据传输出现了BUG。


　　为了恢复正常传输。小明需要找到所有在环路上的电脑，你能帮助他吗？
输入格式
　　第一行包含一个整数N。
　　以下N行每行两个整数a和b，表示a和b之间有一条数据链接相连。


　　对于30%的数据，1 <= N <= 1000
　　对于100%的数据, 1 <= N <= 100000， 1 <= a, b <= N


　　输入保证合法。
输出格式
　　按从小到大的顺序输出在环路上的电脑的编号，中间由一个空格分隔。
样例输入
5
1 2
3 1
2 4
2 5
5 3
样例输出
1 2 3 5
*/
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;
int start, end, n;
int num[100001];
bool visited[100001];
int result[100001];
vector<int> bond[100001];

int find(int root) {
    int son = root;
    while (root != num[root]) {
        root = num[root];
    }
    while (son != root) {
        int temp = num[son];
        num[son] = root;
        son = temp;
    }
    return root;
}

void dfs(int location, int count) {
    if (location == end) {
        sort(result, result + count);
        for (int i = 0; i < count; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < bond[location].size(); i++) {
        if (visited[bond[location][i]] == 0) {
            visited[bond[location][i]] = 1;
            result[count] = bond[location][i];
            dfs(bond[location][i], count + 1);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        num[i] = i;
    }
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int aa = find(a);
        int bb = find(b);
        if (aa == bb) {
            start = a;
            end = b;
        } else {
            num[aa] = bb;
            bond[a].push_back(b);
            bond[b].push_back(a);
        }
    }
    result[0] = start;
    visited[start] = 1;
    dfs(start, 1);
}
/**
vector容器可以直接模拟邻接表来模拟图
并查集 一定要实行路径压缩算法 
这题没有直接超时 
*/
