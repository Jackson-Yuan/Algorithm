/**
��������
����С����ʵ������N̨���ԣ����1~N��ԭ����N̨����֮����N-1����������������ǡ�ù���һ���������硣�����������ϣ�������̨����֮����Ψһ��·��������


�������������һ��ά������ʱ������Ա�����ʹ��ĳ��̨����֮��������һ���������ӣ����������г����˻�·����·�ϵĵ�����������֮�䲻����ֻ��һ��·����ʹ����Щ�����ϵ����ݴ��������BUG��


����Ϊ�˻ָ��������䡣С����Ҫ�ҵ������ڻ�·�ϵĵ��ԣ����ܰ�������
�����ʽ
������һ�а���һ������N��
��������N��ÿ����������a��b����ʾa��b֮����һ����������������


��������30%�����ݣ�1 <= N <= 1000
��������100%������, 1 <= N <= 100000�� 1 <= a, b <= N


�������뱣֤�Ϸ���
�����ʽ
��������С�����˳������ڻ�·�ϵĵ��Եı�ţ��м���һ���ո�ָ���
��������
5
1 2
3 1
2 4
2 5
5 3
�������
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
vector��������ֱ��ģ���ڽӱ���ģ��ͼ
���鼯 һ��Ҫʵ��·��ѹ���㷨 
����û��ֱ�ӳ�ʱ 
*/
