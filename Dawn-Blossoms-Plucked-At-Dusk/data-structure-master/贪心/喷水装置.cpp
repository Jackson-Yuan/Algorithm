#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>

double a[600];
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lf", &a[i]);
        }
        sort(a, a + n);

        double length = 20.0;
        int count = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] <= 1) continue;
            if (length >= 0) {
                double temp = sqrt(a[i] * a[i] - 1.0) * 2;
                length -= temp;
                count++;
            }
        }
        printf("%d\n", count);
    }
}
/*
ûɶ��˵�� ̰��˼�� ������ѡ���Ƿ�Χ��� ͬʱ �����Χ Ҫ������ˮװ�õ���Ч������Ƿ�Χ
��ע�� ������˫������ �������Ҫ��lf ����˫�����ͱ����޷����� ������f ���򱨴� 
��printf����ȴ%f %lf���double�;��� 
*/
