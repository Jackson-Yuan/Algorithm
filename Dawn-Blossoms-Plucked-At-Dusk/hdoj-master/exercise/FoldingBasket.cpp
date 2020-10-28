/**
 * 看网页把 hdoj2074
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

int main() {
    int n;
    char a, b;
    bool isPrint = false;
    while (EOF != scanf("%d %c %c", &n, &a, &b)) {
        if (isPrint) {
            cout << endl;
        }
        if (n == 1) {
            cout << a << endl;
            continue;
        }
        vector<char> character;
        character.push_back(a);
        character.push_back(b);
        vector<vector<char>> res(n, vector<char>(n, ' '));

        int count = 1;
        int index = 0;
        int initialX = n / 2, initialY = n / 2;
        while (count <= n) {
            index = index % character.size();
            int step = count, startX = initialX, startY = initialY;
            while (step--) {
                res[startX][startY] = character[index];
                ++startY;
            }
            --startY;

            step = count;
            while (step--) {
                res[startX][startY] = character[index];
                ++startX;
            }
            --startX;

            step = count;
            while (step--) {
                res[startX][startY] = character[index];
                --startY;
            }
            ++startY;

            step = count;
            while (step--) {
                res[startX][startY] = character[index];
                --startX;
            }
            ++startX;

            ++index;
            count += 2;
            --initialX;
            --initialY;
        }

        res[0][0] = ' ';
        res[0][n - 1] = ' ';
        res[n - 1][0] = ' ';
        res[n - 1][n - 1] = ' ';

        for (int i = 0; i < res.size(); ++i) {
            for (int j = 0; j < res[i].size(); ++j) {
                cout << res[i][j];
            }
            cout << endl;
        }

        isPrint = true;

    }

    return 0;
}
/**
 * 此题的解法没啥说头看图画螺旋曲线，建立一个char型的二维数组就行
 * 但格式比较坑，n==1的时候按题目意思得磨掉，其实得打印
 * 还有就是最后一个打印完之后，别加空行
 * 佛了
 * */