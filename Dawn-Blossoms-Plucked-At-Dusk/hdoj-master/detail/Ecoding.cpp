/**
 * Given a string containing only 'A' - 'Z', we could encode it using the following method
 * 1. Each sub-string containing k same characters should be encoded to "kX" where "X" is the only character in this sub-string.
 * 2. If the length of the sub-string is 1, '1' should be ignored.
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

string intToStr(int val) {
    string res;
    while (val) {
        int tmp = val % 10;
        res.append(1, '0' + tmp);
        val /= 10;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        stack<char> ss;
        for (int i = 0; i < str.length(); ++i) {
            ss.push(str[i]);
        }

        string res;
        int count = 1;
        char compare = ss.top();
        ss.pop();
        while (!ss.empty()) {
            if (compare != ss.top()) {
                res.append(1, compare);
                if (count > 1) res.append(intToStr(count));
                compare = ss.top();
                count = 1;
            } else ++count;

            ss.pop();
        }

        res.append(1, compare);
        if (count > 1) res.append(intToStr(count));


        reverse(res.begin(), res.end());
        cout << res << endl;
    }

    return 0;
}
/**
 * 主要是细心，整形数据用字符表示时，两位数以上要注意
 * */