#include "iostream"
#include "vector"
#include "queue"

using namespace std;


/**
 * ������������һ�ݴ�СΪn x n�� ���� grid�������ÿ�� ��Ԫ�� ����0��1��Ǻ��ˡ�����0������1����½��
 * �����ҳ�һ������Ԫ���������Ԫ�����������½�ص�Ԫ��ľ��������ģ������ظþ��롣���������ֻ��½�ػ��ߺ����뷵��-1��
 * ��������˵�ľ����ǡ������پ��롹��Manhattan Distance����(x0, y0) ��(x1, y1)��������Ԫ��֮��ľ�����|x0 - x1| + |y0 - y1|��
 * ���ӣ�https://leetcode-cn.com/problems/as-far-from-land-as-possible
 * */

/**
 * �����Ƕ�ԴBFSһ���������⣬��ԴBFS������Ϊ�ж����㣬��ʼ�����������
 * ��ʵ���Լ�����һ������Դ�㣬���Դ��ֻ����������ӣ�����͵ȼ�Ϊ
 * �ӳ���Դ�㿪ʼ�������������
 * */
struct node {
    int x;
    int y;
    int step;
};

class Solution {
private:
    vector<vector<int>> directs = {{1,  0},
                                   {-1, 0},
                                   {0,  1},
                                   {0,  -1}};
public:
    int maxDistance(vector<vector<int>> &grid) {
        int row = grid.size(), column = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(column, false));
        queue<node> q;

        int ans = -1;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (grid[i][j] == 1) {
                    node cur;
                    cur.x = i;
                    cur.y = j;
                    cur.step = 0;
                    q.push(cur);
                }
            }
        }

        while (!q.empty()) {
            node cur = q.front();
            q.pop();
            if (cur.step > ans) ans = cur.step;
            for (auto &direct : directs) {
                int next_x = cur.x + direct[0];
                int next_y = cur.y + direct[1];

                if (next_x < 0 || next_x >= row || next_y < 0 | next_y >= column) continue;

                if (!visited[next_x][next_y] && grid[next_x][next_y] == 0) {
                    visited[next_x][next_y] = true;
                    node next;
                    next.x = next_x;
                    next.y = next_y;
                    next.step = cur.step + 1;
                    q.push(next);
                }
            }
        }

        if (ans <= 0) return -1;
        else return ans;
    }
};

