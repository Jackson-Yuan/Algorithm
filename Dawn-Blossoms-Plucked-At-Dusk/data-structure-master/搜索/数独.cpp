#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
int map[9][9];
int flag;

/*判断次数在此行，此列，此3*3的小方格有没有重复的数*/
bool judge(int number, int x, int y) {
    for (int i = 0; i < 9; i++) {
        if (map[x][i] == number) return false;
    }

    for (int i = 0; i < 9; i++) {
        if (map[i][y] == number) return false;
    }

    int a = x / 3;
    a = 3 * a;
    int b = y / 3;
    b = 3 * b;
    for (int i = a; i < a + 3; i++) {
        for (int j = b; j < b + 3; j++) {
            if (map[i][j] == number) return false;
        }
    }

    return true;
}

void dfs(int x, int y) {
    if (flag == 1) return;
    if (x == 9 && y == 0) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
        flag = 1;
        return;
    }
    if (map[x][y] == 0) {
        for (int i = 1; i <= 9; i++) {
            if (flag == 1) {
                return;
            }
            if (judge(i, x, y)) {
                map[x][y] = i;
                if (y + 1 == 9) dfs(x + 1, 0);
                else dfs(x, y + 1);
                map[x][y] = 0;//还原，回溯到上一个点前需还原，否则从上一个点再次拜访此点时会误判 ，但此处还是建议赋值一次，还原一次，以便于judge函数比较 ,不建议放在注释代码处

            }
        }
        /*map[x][y] = 0;*/

    } else {
        if (y + 1 == 9) dfs(x + 1, 0);
        else dfs(x, y + 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        flag = 0;
        dfs(0, 0);
    }
}
/*此题拿到手大致思路是有的 无脑直接暴力dfs穷举所有情况 判断是否有效
但因害怕超时而没有细想，细想的话 首先在判断上 应该编写一个judge函数，judge函数中判断3*3方格的手法利用除法的性质巧妙的找到9个3*3方格首个元素的所在
同时在dfs过程中 塞一个数之前，就要判断一次 再赋值
同时赋值的还原位置也要细细考虑(如此题的map[x][y] = 0) 总之 是一道好题 
*/
