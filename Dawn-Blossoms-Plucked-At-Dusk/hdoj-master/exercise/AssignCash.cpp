/**
 * 作为杭电的老师，最盼望的日子就是每月的8号了，因为这一天是发工资的日子，养家糊口就靠它了，呵呵
 * 但是对于学校财务处的工作人员来说，这一天则是很忙碌的一天，财务处的小胡老师最近就在考虑一个问题：
 * 如果每个老师的工资额都知道，最少需要准备多少张人民币，才能在给每位老师发工资的时候都不用老师找零呢？
 * 这里假设老师的工资都是正整数，单位元，人民币一共有100元、50元、10元、5元、2元和1元六种。
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
    int cash[6] = {100, 50, 10, 5, 2, 1};
    while (true) {
        cin >> n;
        if (n == 0) break;
        vector<int> money;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            money.push_back(tmp);
        }

        int count = 0;
        for (int j = 0; j < money.size(); ++j) {
            int value = money[j];
            while (value) {
                for (int i = 0; i < 6; ++i) {
                    if (value >= cash[i]) {
                        value -= cash[i];
                        ++count;
                        break;
                    }
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}