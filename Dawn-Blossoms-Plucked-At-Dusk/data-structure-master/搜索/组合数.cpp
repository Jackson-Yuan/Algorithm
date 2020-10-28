#include<stdio.h>

int a[15];
int n, r;

void dfs(int c, int x) {
    int i;
    if (x == r + 1) {
        for (int j = 1; j <= r; j++) {
            printf("%d", a[j]);
        }
        printf("\n");
        return;
    }
    for (i = c; i > 0; i--) {
        a[x] = i;
        dfs(i - 1, x + 1);

    }

}

int main() {

    scanf("%d%d", &n, &r);
    dfs(n, 1);
    return 0;

}
/*
此题利用dfs回溯的特性
dfs就是一条路走到底 再回溯到上一个点进行继续搜索，递归刚好满足此特性
此题也就利用了这一特性
例如输入5 3 
循环加递归 保证满足三个之后，回溯到只有2个的情况，继续第三个的情况
如543 542 541 接着在回溯到第一个点的情况 探出第二个点 如532 531
因为循环的特性  所以不需访问标记 
如543打印完之后，回溯到54 再到542 这时第三个数不可能访问到3，因为循环已经跳过了3
*/
