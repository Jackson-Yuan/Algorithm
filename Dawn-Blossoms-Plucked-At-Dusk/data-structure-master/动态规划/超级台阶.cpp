#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<cstdlib>
#include<stdio.h>

using namespace std;

int main() {
    int a[41];
    int N;
    scanf("%d", &N);
    while (N--) {
        memset(a, 0, sizeof(a));
        a[1] = 0;
        a[2] = 1;
        int m;
        scanf("%d", &m);
        if (m <= 2) {
            printf("%d\n", a[m]);
            continue;
        }
        a[1] = 1;
        for (int i = 3; i <= m; i++) {
            a[i] = a[i - 2] + a[i - 1];
        }
        printf("%d\n", a[m]);
    }
}
/*
��̬�滮
ÿ��һ���Ĵ��� ���ڵ���ǰһ���Ĵ�����ǰ�����Ĵ���֮��
��Ҫע�� ������Ŀ��˼ ����ʼ��ʱ����վ�ڵ�һ̨���ϵ�
���Ա߽�ֵҪע��(�����ӽṹ ת�Ʒ��� �߽�) 
*/ 
