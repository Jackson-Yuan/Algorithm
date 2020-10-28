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
�������Ͽ����Ǳ������� ������п��ܵ�������� �Ƚϳ����ֵ
����˼·��ȷ ��������������ʱ ���������һ��
��ʵ����̫����Ĳ��� ֻ����Ŀ�����Ӵ��Ĵ�ĩβ��ʼ�����ȶԵ���ʼ�� ����жϵ����Ӵ����бȽϼ���
�����������
beast
astonish
eastonish

��Ȼ����һ����ڶ�������ʱ ���Ǵ��߼����ǿ�������������� ���ж��㷨���޷������� ���������������������� ���� ���᳢�Ե�һ�������������
��������ȷ�� 
*/
