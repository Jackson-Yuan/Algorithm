#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;
int a[10000];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    printf("%d\n%d\n%d\n", a[n - 1], a[0], sum);
    return 0;
}
