#include "iostream"
#include "vector"

using namespace std;
/**
 * ��һ���� '0' �� '1' ��ɵĶ�ά�����ڣ��ҵ�ֻ���� '1' ����������Σ��������������
 * ���ӣ�https://leetcode.cn/problems/maximal-square/
 * */

/**
 * dp����ĺ��������i��jΪ���½ǵ������εı߳�
 * ״̬ת�Ʒ��̣�dp[i][j]������min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])����ߺ��ϱߺ���⣬б�Ϸ���Ҫ��֤��������ʵ�ĵķǿ��ĵ�
 * */
class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (matrix[0][i] == '1') dp[0][i] = 1;
            ans = max(ans, dp[0][i]);
        }


        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    int up = 0, left = 0, shift = 0;
                    up = dp[i - 1][j];
                    if (j - 1 >= 0) {
                        left = dp[i][j - 1];
                        shift = dp[i - 1][j - 1];
                    }

                    dp[i][j] = min(up, min(left, shift)) + 1;
                    ans = max(ans, dp[i][j]);
                }
            }

        }

        return ans * ans;
    }
};

