#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
int a[1001];

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + m);

        int sum = 0;
        while (m >= 4) {
            if (2 * a[1] + a[0] + a[m - 1] <= 2 * a[0] + a[m - 1] + a[m - 2]) {
                sum += 2 * a[1] + a[0] + a[m - 1];
            } else sum += 2 * a[0] + a[m - 1] + a[m - 2];

            m -= 2;
        }
        if (m == 1 || m == 2) {
            sum += a[m - 1];
        } else if (m == 3) {
            sum += a[m - 1] + a[m - 2] + a[m - 3];
        }

        printf("%d\n", sum);
    }
}
/*
���� �����ֲ���  һ���� ��̺ͺ͵ڶ����ȹ��� ������ֵ�Ͳ���� Ȼ����͵ڶ������� �ڶ������ֵ�Ͳ���� �Դ�Ϊ�ֻ�
�ڶ��������� ����̵�һ������ ��һ�δλ��� �Դ�Ϊ�ֻ� ÿ���ֻض�Ҫ�������ֲ��ԱȽ�
����ԭ�� ���ֲ��Եı��ʽΪ a[1]+a[1]+a[0]+a[m-1]��a[0]+a[0]+a[m-1]+a[m-2]
Լ����ͬ�� ��ʣ�� a[1]+a[1] �� ��a[0]+a[m-2]���������бȽ� 
*/
