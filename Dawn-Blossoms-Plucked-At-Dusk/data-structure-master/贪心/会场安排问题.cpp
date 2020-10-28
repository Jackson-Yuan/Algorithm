#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;
struct activity {
    int start;
    int end;
};
struct activity ac[10000];

bool compare(struct activity a, struct activity b) {
    return a.end < b.end;
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &ac[i].start, &ac[i].end);
        }
        sort(ac, ac + n, compare);
        int count = 1;
        int tempEnd = ac[0].end;
        for (int i = 1; i < n; i++) {
            if (ac[i].start > tempEnd) {
                count++;
                tempEnd = ac[i].end;
            }
        }
        printf("%d\n", count);
    }
}
/*
�������һ�������̰��  ����ÿ����Ľ���ʱ���� Ϊʲô������ʼʱ���� ԭ��ܼ� 
���һ����ʼʱ���С ������ʱ��ܴ� ��֮���һЩ����ʱ��С����ʼʱ���� ��û���� 
����Ҫ���ս���ʱ���С�������� �Ͼ�Ҫ�����ܶ�İ��Ż ����Ҫ������ʱ��˳���� 
*/
