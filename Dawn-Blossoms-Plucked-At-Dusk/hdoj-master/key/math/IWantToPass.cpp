/**
 * 算法笔记 p189
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
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        map<char, int> m;
        int indexP = -1, indexT = -1;
        for (int i = 0; i < str.length(); ++i) {
            ++m[str[i]];
            if (str[i] == 'P') indexP = i;
            if (str[i] == 'T') indexT = i;
        }

        if (m['P'] == 1 && m['T'] == 1 && m['A'] >= 1 && m['T'] + m['A'] + m['P'] == str.length()) {
            if (indexT - indexP > 1) {
                int midA = indexT - indexP - 1;
                int leftA = indexP;
                int rightA = str.length() - indexT - 1;
                if (midA == 1) cout << "YES";
                else {
                    int dif = midA - 1;
                    rightA -= dif * leftA;
                    if ((rightA > 0 && leftA > 0) || (rightA == 0 && leftA == 0)) cout << "YES";
                    else cout << "NO";
                }
            } else cout << "NO";
        } else cout << "NO";

        cout << endl;
    }
    return 0;
}
/**
 * 冷静分析，看清题目条件再判断，浪费好长时间
 * */