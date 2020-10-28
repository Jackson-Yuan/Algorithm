/**
 * 一块花布条，里面有些图案，另有一块直接可用的小饰条，
 * 里面也有一些图案。对于给定的花布条和小饰条，计算一下能从花布条中尽可能剪出几块小饰条来呢？
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    string str;
    while (true) {
        string source, target;
        cin >> source;
        if (source == "#") break;
        cin >> target;
        int count = 0;
        for (int i = 0; i <= source.length() - target.length(); ++i) {
            string tmp = source.substr(i, target.length());
            if (tmp == target) {
                ++count;
                i += target.length() - 1;
            }
        }

        cout << count << endl;
    }

    return 0;
}