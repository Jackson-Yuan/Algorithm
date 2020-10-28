/**
 * 青年歌手大奖赛中，评委会给参赛选手打分。选手得分规则为去掉一个最高分和一个最低分，然后计算平均得分，请编程输出某选手的得分。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<double> counts;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            counts.push_back(tmp);
        }

        sort(counts.begin(), counts.end());

        double sum = 0;
        for (int j = 1; j < counts.size() - 1; ++j) {
            sum += counts[j];
        }

        printf("%.2f\n", sum / (n - 2));
    }

    return 0;
}