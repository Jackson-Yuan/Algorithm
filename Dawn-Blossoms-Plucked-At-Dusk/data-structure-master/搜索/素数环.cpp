#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;

int visited[21];
int n;
int result[21];
int flag;
int prime[40] = {0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0,
                 0, 0, 0, 1, 0, 0};

void dfs(int x, int index) {
    if (visited[x] == 1) return;
    if (prime[result[index] + x]) {
        index++;
        result[index] = x;
    } else {
        return;
    }
    if (index == n) {
        if (prime[result[n] + result[1]]) {
            flag = 1;
            for (int i = 1; i <= n; i++) {
                printf("%d ", result[i]);
            }
            printf("\n");
        }
        return;
    }
    /*��ǵķ����뻹ԭ ���Է���ѭ����
    Ҳ���Է���ѭ����
    ֻҪ��֤�˳��������ʱ ����ǵ㻹ԭ����
    */
    visited[x] = 1;
    for (int i = 1; i <= n; i++) {
        /*visited[x] = 1;*/
        if (visited[i] == 0) {
            dfs(i, index);
        }
        /*visited[x] = 0;*/
    }
    visited[x] = 0;
}

int main() {
    int sum = 0;
    while (scanf("%d", &n)) {
        if (n == 0) break;
        sum++;
        if (n % 2 != 0 && n != 1) {
            printf("Case %d:\n", sum);
            printf("No Answer\n");
            continue;
        }
        memset(visited, 0, sizeof(visited));
        result[0] = 0;
        flag = 0;
        printf("Case %d:\n", sum);
        dfs(1, 0);
        if (flag == 0) printf("No Answer\n");
    }
}
/*
�����һ�� �Ƚ����������1-n �����ӵ���ͨͼ��֯������ͨ����Ƿ����뻹ԭ���ʱ�ǣ����ﵽʵ�ֶ���dfs·���Ĺ���
��dfs�����й� û��һ�����ж��Ƿ���ǰһ�����Ϊ���� ��Ȼ��ѹ�������飬���ܴ���n����ʱ�����ж��Ƿ���βΪ�������ܴ�ӡ��
���ܵĻ� ���� ���ݵ���һ��������̽
ͬʱ Ҫע�� nΪ������n��Ϊ1��ʱ�򲻿����� Ҫ�ر�ָ��������ʱ 
*/
