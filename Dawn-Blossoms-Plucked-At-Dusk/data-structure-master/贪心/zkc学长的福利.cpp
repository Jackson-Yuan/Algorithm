#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
struct node {
    int left;
    int right;
};
struct node a[1001];

bool cmp(struct node aa, struct node bb) {
    return aa.left * aa.right < aa.right * bb.right;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        scanf("%d%d", &a[0].left, &a[0].right);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &a[i].left, &a[i].right);
        }
        sort(a + 1, a + n + 1, cmp);
        int max = -1;
        for (int i = 1; i <= n; i++) {
            int sum = 1;
            for (int j = 0; j < i; j++) {
                sum *= a[j].left;
            }
            int temp = sum / a[i].right;
            if (max < temp) max = temp;
        }
        printf("%d\n", max);
    }

}
