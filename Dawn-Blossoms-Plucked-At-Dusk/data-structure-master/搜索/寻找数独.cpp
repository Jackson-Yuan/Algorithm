/**
你一定听说过“数独”游戏。
如【图1.png】，玩家需要根据9×9盘面上的已知数字，推理出所有剩余空格的数字，并满足每一行、每一列、每一个同色九宫内的数字均含1-9，不重复。

数独的答案都是唯一的，所以，多个解也称为无解。

本图的数字据说是芬兰数学家花了3个月的时间设计出来的较难的题目。但对会使用计算机编程的你来说，恐怕易如反掌了。

本题的要求就是输入数独题目，程序输出数独的唯一解。我们保证所有已知数据的格式都是合法的，并且题目有唯一的解。

格式要求，输入9行，每行9个数字，0代表未知，其它数字为已知。
输出9行，每行9个数字表示数独的解。

例如：
输入（即图中题目）：
005300000
800000020
070010500
400005300
010070006
003200080
060500009
004000030
000009700

程序应该输出：
145327698
839654127
672918543
496185372
218473956
753296481
367542819
984761235
521839764

再例如，输入：
800000000
003600000
070090200
050007000
000045700
000100030
001000068
008500010
090000400

程序应该输出：
812753649
943682175
675491283
154237896
369845721
287169534
521974368
438526917
796318452
*/
#include<stdio.h>
#include<iostream>

using namespace std;
int map[9][9];

bool judge(int x, int y, int value) {
    bool token = true;
    /**check row*/
    for (int i = 0; i < 9; i++) {
        if (i != y) {
            if (map[x][i] == 0) continue;
            else if (map[x][i] == value) {
                token = false;
                break;
            }
        }
    }
    if (!token) return false;
    /**check column*/
    for (int i = 0; i < 9; i++) {
        if (i != x) {
            if (map[i][y] == 0) continue;
            else if (map[i][y] == value) {
                token = false;
                break;
            }
        }
    }
    if (!token) return false;

    int tmp = x / 3;
    int startX = tmp * 3;
    tmp = y / 3;
    int startY = tmp * 3;
    for (int i = startX; i < startX + 3; i++) {
        for (int j = startY; j < startY + 3; j++) {
            if (i != x || j != y) {
                if (map[i][j] == 0) continue;
                else if (map[i][j] == value) {
                    token = false;
                    break;
                }
            }
        }
    }

    if (!token) return false;

    return token;
}

void dfs(int x, int y) {
    if (x == 9 && y == 0) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    if (map[x][y] != 0) {
        if (y + 1 < 9) dfs(x, y + 1);
        else dfs(x + 1, 0);
    } else {
        for (int i = 1; i <= 9; i++) {
            if (judge(x, y, i)) {
                map[x][y] = i;
                if (y + 1 < 9) dfs(x, y + 1);
                else dfs(x + 1, 0);
                map[x][y] = 0;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> map[i][j];
        }
    }
    cout << endl;

    dfs(0, 0);
}
/**
深搜的经典题 大致思路 dfs穷举所有情况 最后统一判断 其实这样并不科学
而是编写一个judge函数来进行减枝操作来减少运行时间
下面来回顾一下枚举过程
从 0 0 开始 若map[0][0]不等于0直接下一个点
若为0 开始 1 ~ 9枚举 利用judge函数判断当前情况下能否放
若当一个点遍历 1 ~ 9都没能成功 退回上一个点重新选择，若上一个点还不行 退回上一个，以此类推(但记得退回时 map得还原为0，否则会出错) 
*/
