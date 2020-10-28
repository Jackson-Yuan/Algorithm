#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
    int x;
    int y;
};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        int height = matrix.size(), width = matrix[0].size();
        queue<struct node> q;
        vector<vector<int>> res(height, vector<int>(width, 0x7fffffff));
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (matrix[i][j] == 0) {
                    res[i][j] = 0;
                    struct node tmp;
                    tmp.x = i;
                    tmp.y = j;
                    q.push(tmp);
                }
            }
        }

        while (!q.empty()) {
            struct node current = q.front();
            q.pop();
            int tmpX = current.x, tmpY = current.y;
            if (tmpX + 1 < height && res[tmpX + 1][tmpY] > res[tmpX][tmpY] + 1) {
                res[tmpX + 1][tmpY] = res[tmpX][tmpY] + 1;
                struct node tmp;
                tmp.x = tmpX + 1;
                tmp.y = tmpY;
                q.push(tmp);
            }

            if (tmpX - 1 >= 0 && res[tmpX - 1][tmpY] > res[tmpX][tmpY] + 1) {
                res[tmpX - 1][tmpY] = res[tmpX][tmpY] + 1;
                struct node tmp;
                tmp.x = tmpX - 1;
                tmp.y = tmpY;
                q.push(tmp);
            }

            if (tmpY + 1 < width && res[tmpX][tmpY + 1] > res[tmpX][tmpY] + 1) {
                res[tmpX][tmpY + 1] = res[tmpX][tmpY] + 1;
                struct node tmp;
                tmp.x = tmpX;
                tmp.y = tmpY + 1;
                q.push(tmp);
            }

            if (tmpY - 1 >= 0 && res[tmpX][tmpY - 1] > res[tmpX][tmpY] + 1) {
                res[tmpX][tmpY - 1] = res[tmpX][tmpY] + 1;
                struct node tmp;
                tmp.x = tmpX;
                tmp.y = tmpY - 1;
                q.push(tmp);
            }


        }

        return res;
    }
};

/**
 * 此题最初是每个点都来手bfs，直接暴力掉，可惜直接超时
 * 不妨换种思路，先将为0的点压入结果矩阵，反正为0无需计算
 * 再由每个位0的向四周bfs计算距离，每个点距离一旦变得比原来小（最初每个点值位0x7fffffff）
 * 就压入队列，进行下一轮更新，而不是根据访问数组标记是否压入队列
 * */