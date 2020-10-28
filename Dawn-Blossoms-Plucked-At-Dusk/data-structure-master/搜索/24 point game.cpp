#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
double a[10];
int visited[10];
int flag;
int n;
int target;

void dfs(double s, int count) {
    if (flag == 1) return;
    if (count == n) {
        /*�����������*/
        if (fabs(s - target) < 0.0000001) {
            flag = 1;
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && flag == 0) {
            visited[i] = 1;
            dfs(s * a[i], count + 1);
            dfs(s + a[i], count + 1);
            dfs(a[i] - s, count + 1);
            dfs(s - a[i], count + 1);
            dfs(s / a[i], count + 1);
            dfs(a[i] / s, count + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        scanf("%d%d", &n, &target);
        for (int i = 0; i < n; i++) {
            scanf("%lf", &a[i]);
        }
        flag = 0;
        for (int i = 0; i < n; i++) {
            memset(visited, 0, sizeof(visited));
            visited[i] = 1;
            dfs(a[i], 1);
            if (flag == 1) break;
        }
        if (flag == 0) printf("No\n");
        else printf("Yes\n");
    }
}
/*
���⻹��ö�� һ�������ܲ��ܴﵽĳ��Ŀ�� һ�㶼����� Ȼ��ÿ�����㶼�ѼӼ��˳�������һ��(�����ͳ��� Ҫע������˳�� ͬʱ��Ҫע��ÿ��dfs������ ѭ��һ�� Ҫ�����ʱ�ǻ�ԭ �Ա����¸�ѭ��Ҫ���ʵ����ܷ��ʵ���ԭ����)
����������Ŀ��˼������ ��ΪҪ������˳�� ����Ӽ��˳� �������ʰ��� �� 
*/
