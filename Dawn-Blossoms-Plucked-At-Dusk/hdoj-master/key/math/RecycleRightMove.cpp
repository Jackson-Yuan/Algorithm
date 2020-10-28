/**
 * 算法笔记 p201
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int gcd(int a, int b) {
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    while (a) {
        int tmp = b % a;
        b = a;
        a = tmp;
    }

    return b;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> array(n, -1);
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        array[(i + m) % n] = value;
    }

    for (int i = 0; i < array.size(); ++i) {
        cout << array[i];
        if (i != array.size() - 1) cout << " ";
    }

    return 0;
}