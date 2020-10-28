#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;
vector<int> v;
bool vis[5];

void dfs(int index, int start) {
    if (index == 2) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    } else {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    for (int i = start + 1; i <= 3; i++) {
        v.push_back(i);
        dfs(index + 1, i);
        v.pop_back();
    }
}

void dfs2(int index) {
    if (v.size() == 2) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }
    if (index == 3) return;

    v.push_back(index + 1);
    dfs2(index + 1);
    v.pop_back();
    dfs2(index + 1);
}

int main() {
    dfs(0, 0);
    v.clear();
    cout << endl;
    dfs2(0);
}
/**
���ֲ�ͬ˼·��n������ѡȡ������
��һ��������ÿ��ѡȡ�ķ�Χ
�ڶ��� ��ÿ����������ѡ�� ѡ��ѡ
�ڶ���������� 
*/
