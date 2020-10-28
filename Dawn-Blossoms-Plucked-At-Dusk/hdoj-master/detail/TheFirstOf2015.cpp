
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int stringToInt(string s) {
    int res = 0;
    int base = 1;
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == '-') {
            res = -res;
        } else {
            int tmp = s[i] - '0';
            tmp *= base;
            res += tmp;
        }

        base *= 10;
    }

    return res;
}

int main() {
    string s;
    cin >> s;
    vector<int> val;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            int start = i + 1;
            while (start < s.length() && (s[start] >= '0' && s[start] <= '9')) ++start;
            string tmp = s.substr(i, start - i);
            val.push_back(stringToInt(tmp));
            i = start - 1;/**防止出现类似2-9，直接start赋值，会跳过负号*/
        } else if (s[i] == '-') {
            int start = i + 1;
            while (start < s.length() && (s[start] >= '0' && s[start] <= '9')) ++start;
            if (start != i + 1) {
                string tmp = s.substr(i, start - i);
                val.push_back(stringToInt(tmp));
                i = start - 1;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < val.size(); ++i) {
        res += val[i];
    }

    cout << val.size() << " " << res << endl;

    return 0;
}
/**字符串操作，注意细节*/