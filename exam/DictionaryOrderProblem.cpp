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
    vector<int> count(len);/**ͳ��ÿһλ��ĸС�����ж��ٸ�*/
    for (int i = 0; i < count.size(); ++i) {
        count[i] = str[i] - 96;
    }

    int passed = 1;/**�Ѿ����˶��ٸ���ĸ*/
    for (int i = len; i > 0; --i) {
        for (int j = passed; j < count[len - i]; ++j) {
            ans += C(26 - j, i - 1);
        }
        passed = count[len - i] + 1;/**�ۼ��Ѿ��ù�����ĸ +1����ǰ�ж�����ĸ*/
    }

    cout << ans + 1 << endl;
}