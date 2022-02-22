#include "iostream"
#include "vector"

using namespace std;

/**
 * ��һ��n x n�Ĺ������������ϣ�һ����ʿ�ӵ�Ԫ�� (row, column)��ʼ�������Խ��� k ���ƶ����к����� �� 0 ��ʼ �ģ��������ϵ�Ԫ���� (0,0) �����µ�Ԫ���� (n - 1, n - 1) ��
 * ������ʿ��8�ֿ��ܵ��߷�������ͼ��ʾ��ÿ���ƶ��ڻ�����������������Ԫ��Ȼ����������������һ����Ԫ��
 * ÿ����ʿҪ�ƶ�ʱ�������������8�ֿ��ܵ��ƶ���ѡ��һ��(��ʹ���ӻ��뿪����)��Ȼ���ƶ������
 * ��ʿ�����ƶ���ֱ�������� k �����뿪�����̡�
 * ���� ��ʿ������ֹͣ�ƶ��������������ϵĸ��� ��
 * ���ӣ�https://leetcode-cn.com/problems/knight-probability-in-chessboard
 * */

/**
 * ���Ա���dfs����
 * ��������Ҫ����һ���ļ��仯������ʩ����Ϊÿ��ǰһ�����п����߻��������Ե��µݹ���Ⱥܴ�
 * ���м��仯�ݹ���Լ�С������
 * ͬʱע�⣬��Ϊ�������double���ͣ��ж��Ƿ񱣴�����������Ƿ����0�����Ǵ���һ����С����
 *
 * ������Ӧ�ò���Ҫ����Ϊ������ϰ�ߣ�����д��
 * */
class Solution {
public:
    //�˸�����
    vector<pair<int, int>> directions = {{1,  2},
                                         {-1, 2},
                                         {1,  -2},
                                         {-1, -2},
                                         {2,  1},
                                         {-2, 1},
                                         {2,  -1},
                                         {-2, -1}};

    double knightProbability(int N, int K, int r, int c) {
        //board[row][col][j]���ڴ洢��row�У�col����j��������ĸ���
        vector<vector<vector<double>>> board(N, vector<vector<double>>(N, vector<double>(K + 1, 0)));
        return nextStep(board, N, K, r, c, K);
    }

    //step������ǻ���Ҫ�ߵĲ�����[nowRow][nowCol]�����ڵ�λ��
    double nextStep(vector<vector<vector<double>>> &board, int N, int K, int nowRow, int nowCol, int step) {
        if (nowRow < 0 || nowCol < 0 || nowRow >= N || nowCol >= N) {//����
            return 0;
        }
        //�����ʱstep == 0���������Ѿ������ƶ�������û�г���ĸ��ʾ���1.0
        if (step == 0) {
            return 1.0;
        }
        //��������֮ǰ����������ע��double���Ͳ���ֱ���ж�board[nowRow][nowCol][step] == 0����Ҫ�ж����Ƿ�С��һ����С��ֵ������1e-6��
        if (abs(board[nowRow][nowCol][step]) > 1e-6) {
            return board[nowRow][nowCol][step];
        }
        //��ٰ˸�����
        for (auto &direction : directions) {
            board[nowRow][nowCol][step] +=
                    nextStep(board, N, K, nowRow + direction.first, nowCol + direction.second, step - 1) / 8;
        }
        return board[nowRow][nowCol][step];
    }
};

int main() {
    Solution solution;
    cout << solution.knightProbability(3, 2, 0, 0);

    double a = 0.000000000000000000000007;
    double b = 0.000000000000000000000006;

    cout << (a == b);
}

