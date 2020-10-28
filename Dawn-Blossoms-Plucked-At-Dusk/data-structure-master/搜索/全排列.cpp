#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
int n;
int result[100];
int visited[100];

void dfs(int index, int count) {
    if (visited[index] == 1) return;
    visited[index] = 1;
    result[count] = index;
    if (count == n - 1) {
        for (int i = 0; i < n; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    } else {
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i, count + 1);
            }
        }
    }
    visited[index] = 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        dfs(i, 0);
    }
}
