#include<stdio.h>

int map[8][8];
int n;
int count;

// 2 白 3 黑
void dfs(int row, int type) {
    /*代表摆放的列 行上面只放一个 没啥好说的*/
    for (int i = 0; i < n; i++) {
        /*无法放 或已经放过了*/
        if (map[row][i] == 0 || map[row][i] == 2) {
            continue;
        }
        int flag = 1;
        int y1 = i - 1;
        int y2 = i + 1;
        for (int j = row - 1; j >= 0; j--) {
            /*column*/
            if (map[j][i] == type) {
                flag = 0;
                break;
            }
            /*diagonal*/
            if (y1 >= 0 && map[j][y1] == type) {
                flag = 0;
                break;
            }
            y1--;
            if (y2 < n && map[j][y2] == type) {
                flag = 0;
                break;
            }
            y2++;
        }

        if (flag) {
            map[row][i] = type;
            /*继续放当前(白)棋子 否则代表(白)摆完 开始摆黑*/
            if (row < n - 1) {
                dfs(row + 1, type);
            } else {
                /*当白摆完时 开始摆黑 当黑摆完时 说明摆完了*/
                if (type == 2) {
                    dfs(0, 3);
                } else {
                    count++;
                }
            }
            map[row][i] = 1;//还原
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    count = 0;
    dfs(0, 2);
    printf("%d\n", count);
}
/*
思路见注释
其实就是直接搜索 暴力穷举就完事了 但因为行上只可以摆一个 所以 行就不需要检查 这样也好判断递归结束条件
总之 很经典 
*/ 

