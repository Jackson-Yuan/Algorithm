#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
char b[101];
int a[100];
int c[100];

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    while (N--) {
        int n, m;
        scanf("%s %d", b, &n);
        int index = strlen(b);
        for (int i = 0; i < index; i++) {
            a[i] = b[i] - '0';
        }
        m = index - n;
        int temp = 0;
        int index2 = 0;
        for (int i = m - 1; i >= 0; i--) {
            int max = a[temp];
            for (int j = temp; j < index - i; j++) {
                if (a[j] > max) {
                    max = a[j];
                    temp = j;
                }
            }
            c[index2] = max;
            index2++;
            temp++;
        }
        for (int i = 0; i < index2; i++) {
            printf("%d", c[i]);
        }
        printf("\n");
    }
}/*
������Ǵ����������ҵ�ɾ��һЩ����ʹ��ʣ�µ������
����ȷ��Ŀ���Ǽ�λ�����ڰ�ÿһλ���ķ�Χȷ�����ҳ�ÿһλ����Χ��
���ֵ���� 


*/ 
