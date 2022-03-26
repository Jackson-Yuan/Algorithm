#include "iostream"
#include "vector"

using namespace std;

/**
 * �� n �����򣬱��Ϊ0 �� n - 1��ÿ�������϶�����һ�����֣���Щ���ִ�������nums�С�
 * ����Ҫ����������е����򡣴��Ƶ� i ����������Ի��nums[i - 1] * nums[i] * nums[i + 1] öӲ�ҡ������ i - 1 �� i + 1 �����i���ڵ������������š�
 * ��� i - 1�� i + 1 ����������ı߽磬��ô�͵�����һ������Ϊ 1 ������
 * �����ܻ��Ӳ�ҵ����������
 * ���ӣ�https://leetcode-cn.com/problems/burst-balloons
 * */


/**
 * �������Ȱ������� ��������ˣ�Ȼ��ɾ���м�������ڼ���ĳ������������ɾ�Դ����ƣ��ҳ�������ѡ��
 * ������һ��ɾһ���ᵼ����������Ӳ����ڱ�����ڣ�ʹ�ú����������Դ������ǲ�������˼ά����ȫ���̿�����ÿ�����һ������
 * dfs(i,j)�����i��j�����ֵ
 * ���ü��仯�ݹ飬������ʷ��������״̬���Է��ظ�����
 *
 * ���ڼ��仯�ݹ�����뵽��ʹ�ã���Ҫ���ȶ���ĵݹ����壬�ٰ��յݹ������Ƿ�����ظ��ĵݹ�״̬����������ظ��������ʹ�ü��仯�ݹ�
 *
 * ͨ�����仯�ݹ飨�Զ����£����ö�̬�滮���Ե����ϣ���д
 * */
class Solution {
private:
    vector<vector<int>> state;
    vector<int> val;
public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        val.resize(n + 2);
        for (int i = 1; i <= n; ++i) {
            val[i] = nums[i - 1];
        }

        val[0] = val[n + 1] = 1;

        state.resize(n + 2, vector<int>(n + 2, -1));
        return dfs(0, n + 1);
    }


    int dfs(int left, int right) {
        if (left + 1 >= right) return 0;

        if (state[left][right] != -1) return state[left][right];


        for (int i = left + 1; i < right; ++i) {
            int sum = val[left] * val[i] * val[right];
            sum += dfs(left, i) + dfs(i, right);
            state[left][right] = max(state[left][right], sum);
        }

        return state[left][right];
    }
};


/**
 * ��̬�滮д��
 * */
class Solution2 {
public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> rec(n + 2, vector<int>(n + 2));
        vector<int> val(n + 2);
        val[0] = val[n + 1] = 1;
        for (int i = 1; i <= n; i++) {
            val[i] = nums[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j <= n + 1; j++) {
                for (int k = i + 1; k < j; k++) {
                    int sum = val[i] * val[k] * val[j];
                    sum += rec[i][k] + rec[k][j];
                    rec[i][j] = max(rec[i][j], sum);
                }
            }
        }
        return rec[0][n + 1];
    }
};


int main() {
    vector<int> nums = {3, 1, 5, 8};

    Solution solution;

    cout << solution.maxCoins(nums);
}

