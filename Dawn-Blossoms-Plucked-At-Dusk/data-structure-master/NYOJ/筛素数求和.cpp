#include<stdio.h>

int main() {
    int n, m, i, j, t;

    int *a = 0;
    int *b = 0;
    scanf("%d", &n);
    while (n) {
        t = 0;
        scanf("%d", &m);
        a = new int[m];
        b = new int[m];
        for (i = 0; i < m; i++) {
            scanf("%d", &a[i]);
        }
        for (i = 0; i < m; i++) {
            b[i] = 0;
        }
        for (i = 0; i < m; i++) {

            if (a[i] == 1) continue;
            if (a[i] == 2) b[i] = 1;
            for (j = a[i] - 1; j > 1; j--) {
                if (a[i] % j)

                    b[i] = 1;

                else {
                    b[i] = 0;
                    break;
                }
            }

        }
        for (i = 0; i < m; i++) {
            if (b[i] == 1) t = t + a[i];
        }
        printf("%d\n", t);
        n--;
        delete[]a;
        delete[]b;
    }
}//��Ҫ˼·  ����һ������ֵ�ж��Ƿ�Ϊ���� ������b���� 
