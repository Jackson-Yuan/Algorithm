#include<stdio.h>

int a[100000];

int main() {
    int n;
    scanf("%d", &n);
    int m;
    while (n--) {
        scanf("%d", &m);
        int max = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d", &a[i]);
        }


        for (int i = 1; i < m; i++) {
            a[i] = a[i] + a[i - 1];
            if (max < a[i]) {
                max = a[i];
            }
        }
        printf("%d\n", max);
    }
}
/*for(int i=1;i<m;i++)//非连续最大子串和
    {
        for(int j=0;j<i;j++)
        {
            if(b[i]<a[i]+b[j])
            {
                b[i]=a[i]+b[j];
            }
        }
    }*/
