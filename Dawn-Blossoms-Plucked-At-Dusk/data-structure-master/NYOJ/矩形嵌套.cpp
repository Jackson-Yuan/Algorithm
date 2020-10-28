#include<stdio.h>

struct juxing {
    int x;
    int y;
};

int max(struct juxing a, struct juxing b) {
    if (a.x < b.x && a.y < b.y) return 1;
    else return 0;
}

int dp[10001];
struct juxing a[1001];

int main() {
    int m;
    scanf("%d", &m);
    while (m--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a[i].x, &a[i].y);
            if (a[i].x > a[i].y) {
                int temp = a[i].x;
                a[i].x = a[i].y;
                a[i].y = temp;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i].x > a[j].x) {
                    int temp = a[i].x;
                    a[i].x = a[j].x;
                    a[j].x = temp;
                    temp = a[i].y;
                    a[i].y = a[j].y;
                    a[j].y = temp;
                } else if (a[i].x == a[j].x) {
                    if (a[i].y > a[j].y) {
                        int temp = a[i].x;
                        a[i].x = a[j].x;
                        a[j].x = temp;
                        temp = a[i].y;
                        a[i].y = a[j].y;
                        a[j].y = temp;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            dp[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (max(a[j], a[i]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        int max = dp[0];
        for (int i = 0; i < n; i++) {
            if (max < dp[i]) max = dp[i];
        }
        printf("%d\n", max + 1);
    }
}
