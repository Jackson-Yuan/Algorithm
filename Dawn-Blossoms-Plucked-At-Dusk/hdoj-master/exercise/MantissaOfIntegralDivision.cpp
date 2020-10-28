/**
 * 一个整数，只知道前几位，不知道末二位，被另一个整数除尽了，那么该数的末二位该是什么呢？
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
    int a, b;
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        a = a * 100;
        vector<int> res;
        for (int i = 0; i <= 99; ++i) {
            int tmp = a + i;
            if (tmp % b == 0) res.push_back(i);
        }

        for (int i = 0; i < res.size(); ++i) {
            printf("%02d", res[i]);/**输出前导0*/
            if (i != res.size() - 1) cout << " ";
        }

        cout << endl;
    }
}