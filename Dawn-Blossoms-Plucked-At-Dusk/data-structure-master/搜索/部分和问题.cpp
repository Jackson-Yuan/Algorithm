#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
int n, k;
int visited[20];
int result[20];
int a[20];
int flag;

int count(int index) {
    int sum = 0;
    for (int i = 0; i < index; i++) {
        sum += result[i];
    }
    return sum;
}

void dfs(int start, int index) {
    visited[start] = 1;
    result[index] = a[start];
    index++;
    /*if(count(index) > k) return;*/
    if (count(index) == k) {
        if (flag == 0) printf("Yes\n");
        for (int i = 0; i < index; i++) {
            printf("%d ", result[i]);
        }
        flag = 1;
        printf("\n");
    }
    /*visited[start] = 1;
    result[index] = a[start];
    index++;*/
    for (int i = start; i < n; i++) {
        if (visited[i] == 0) {
            dfs(i, index);
        }
    }
    visited[start] = 0;
}

int main() {
    while (scanf("%d %d", &n, &k) == 2) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        flag = 0;
        for (int i = 0; i < n; i++) {
            memset(visited, 0, sizeof(visited));
            if (i > 0) {
                for (int j = 0; j < i; j++) {
                    visited[j] = 1;
                }
            }
            dfs(i, 0);
            if (flag == 1) break;
        }
        if (flag == 0) printf("No\n");
    }


}
/*
�������������� �Ͳ����ύoj��
�м���ע���
dfs�е�ǰ�㵽�����ܵ��ĵ�Ҫ������Ŀ��˼�������
������ �����ó���Ĵ�1��n��������δ���� �������Ŀ��˼ ����˳����Υ�� 
���и��ִ�����߼�˳�� Ҫ����
����ע�ʹ��봦 ��һ�� �����kΪ0 ��������Ϊ 1 -1����ж�Ϊno
�ڶ��� ��Ϊ�����ж� �ڱ�� �ٸ�ֵ
����
n k Ϊ4 13 ����1 2 4 7 
��ȷ��Ӧ��Ϊ2 4 7
��������ڶ���ע�ʹ��봦��д ���и�bug ����7ѹ��������ʱ  ��Ϊ7������Ϊ���һλ û�а취����dfs��ô���޷��ж�2 4 7������ 
*/
