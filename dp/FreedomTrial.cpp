/**
 * ������Ϸ������4���У�����ͨ�����ɡ�Ҫ����ҵ�����Ϊ��Freedom Trail Ring���Ľ������̣���ʹ�ñ���ƴд�ض��ؼ��ʲ��ܿ��š�
 * ����һ���ַ���ring����ʾ�����⻷�ϵı��룻������һ���ַ���key����ʾ��Ҫƴд�Ĺؼ��ʡ�����Ҫ����ܹ�ƴд�ؼ����������ַ������ٲ�����
 * �����ring�ĵ�һ���ַ���12:00������롣����Ҫ˳ʱ�����ʱ����ת ring ��ʹkey��һ���ַ��� 12:00������룬
 * Ȼ�������İ�ť���Դ����ƴд��key�е������ַ���
 * */
#include <algorithm>
#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<int> pos[26];
        for (int i = 0; i < ring.size(); i++) {
            pos[ring[i] - 'a'].push_back(i);
        }

        vector<vector<int>> dp(key.size(), vector<int>(ring.size(), INT_MAX));
        for (int i = 0; i < key.size(); i++) {
            for (auto j : pos[key[i] - 'a']) {
                if (i == 0) {
                    dp[i][j] = min(dp[i][j], 0 + clac(ring.size(), 0, j) + 1);
                    continue;
                }

                for (auto k : pos[key[i - 1] - 'a']) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + clac(ring.size(), k, j) + 1);
                }
            }
        }


        /**���������е���Сֵ*/
        return *min_element(dp.back().begin(), dp.back().end());
    }

    int clac(int len, int a, int b) {
        return min((len + a - b) % len, (len + b - a) % len);
    }
};
/**
 * ��Ȼ�ǲٵ��Ķ�̬�滮
 * dp���������Ϊ����Ϊm��key(ʵ���������Ϊm-1)��������Ϊj���ַ�����̾���(����Ϊj���ַ�����ʵ���Ǵ�key���һ���ַ���ֻ������ַ�������
 * ring���ж��λ�ã����Ա�����������Ҫѡ����Сֵ)
 * ֪�������壬ÿ��dp[i][j]��ֵ��������dp[i-1][k]����Сֵ(k�Ǵ�key��ǰ�ַ�ǰһ���ַ�����λ�õ���������Ϊ����һ��λ�ã����Ա���
 * ȫ������ȡ��Сֵ)
 * */


