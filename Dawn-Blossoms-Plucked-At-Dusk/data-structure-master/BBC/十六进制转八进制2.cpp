#include<stdio.h>
#include<string.h>

char h[100002], b[400002], e[400002];

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", h);
        int i, len = 0;
        /*先把16进制化成二进制——从后往前展开 */
        for (i = strlen(h) - 1; i >= 0; i--) {
            int v;
            if (h[i] >= '0' && h[i] <= '9')
                v = h[i] - '0';
            else v = h[i] - 'A' + 10;
            for (int j = 0; j < 4; j++) {
                b[len++] = v % 2 + '0';
                v /= 2;
            }
        }
        b[len] = '\0';
        int x = 0, cnt = 1;
        int l = 0;
        for (i = 0; i < len; i++) {
            /*每三位二进制转成一位8进制,最后不足三位补0*/
            if (cnt == 4 || i == len - 1) {
                x = cnt * (b[i] - '0') + x;
                cnt = 1;
                e[l++] = x + '0';
                x = 0;
            } else {
                x = cnt * (b[i] - '0') + x;
                cnt *= 2;
            }
        }
        i = l - 1;
        while (i >= 0 && e[i] == '0')
            /*去掉前导0*/
            i--;
        if (i < 0)
            printf("0");
        for (; i >= 0; i--) {
            printf("%c", e[i]);
        }
        printf("\n");
    }
    return 0;
}
