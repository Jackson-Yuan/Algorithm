#include<stdio.h>
#include<stdlib.h>

int count;
int sum[8];
bool vis[8];

void dfs(int index) {
    if (index == 8) {
        count++;
        return;
    }

    for (int i = 0; i < 8; i++) {
        if (vis[i] == false) {
            bool flag = true;
            for (int j = 0; j < index; j++) {
                if (abs(index - j) == abs(i - sum[j])) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                sum[index] = i;
                vis[i] = true;
                dfs(index + 1);
                vis[i] = false;
            }
        }
    }
}

int main() {
    count = 0;
    dfs(0);
    printf("%d\n", count);
}
