#include "iostream"
#include "string"
#include "vector"

using namespace std;

int C(int m, int n) {
    int mother = 1, son = 1;
    for (int i = n; i > 1; --i) {
        son *= i;
    }

    for (int i = m; i > m - n; --i) {
        mother *= i;
    }

    return mother / son;
}


int main() {
    string str;
    cin >> str;
    int len = str.length(), ans = 0;
    for (int i = 1; i < len; ++i) {
        ans += C(26, i);
    }
    vector<int> count(len);/**统计每一位字母小于它有多少个*/
    for (int i = 0; i < count.size(); ++i) {
        count[i] = str[i] - 96;
    }

    int passed = 1;/**已经用了多少个字母*/
    for (int i = len; i > 0; --i) {
        for (int j = passed; j < count[len - i]; ++j) {
            ans += C(26 - j, i - 1);
        }
        passed = count[len - i] + 1;/**累计已经用过的字母 +1代表当前判定的字母*/
    }

    cout << ans + 1 << endl;
}