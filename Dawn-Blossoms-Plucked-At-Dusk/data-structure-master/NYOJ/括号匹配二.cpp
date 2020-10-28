#include<stdio.h>
#include<string.h>

char a[101];
int dp[101][101];
int n;
int max = 9999999999;

void clean() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
}

bool match(char a, char b) {
    if ((a == '(' && b == ')') || (a == '[' && b == ']')) return true;
    else return false;
}

int min(int a, int b) {
    if (a > b) return b;
    else return a;
}

void solve() {
    clean();
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            dp[i][j] = max;
            if (match(a[i], a[j])) dp[i][j] = dp[i + 1][j - 1];
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }
}

int main() {
    int count;
    scanf("%d", &count);
    getchar();
    while (count--) {
        scanf("%s", a);
        n = strlen(a);
        solve();
        printf("%d\n", dp[0][n - 1]);
    }
}
/*状态定义dp[i][j] 从i到j的最小需求括号数
状态转移 如果首尾一样，首尾缩进一个，如果字符串中至少有两个字符 ，拆分为AB两部分，为AB两部分相加（不断在i到j中寻找分割点） 
特别注意，初始化dp表时 如果i>j置0 i=j置1，dp顺序一定是从已经初始化好的数据中开始 逐渐累积 
*/
