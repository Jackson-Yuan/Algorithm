#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int cmp(string a, string b) {
    /**
    防止出现a为"00" b为"1"类似情况 出现误判
    */
    if (a.find_first_not_of('0') == string::npos) a = "0";
    else a = a.substr(a.find_first_not_of('0'));
    if (b.find_first_not_of('0') == string::npos) b = "0";
    else b = b.substr(b.find_first_not_of('0'));
    if (a.length() > b.length()) return 1;
    else if (a.length() < b.length()) return -1;
    else {
        if (a < b) return -1;
        else if (a > b) return 1;
        else return 0;
    }
}

string createStr(int value) {
    char a[1000];
    int index = 0;
    while (value) {
        a[index] = value % 10 + '0';
        value /= 10;
        index++;
    }
    string res;
    if (index == 0) {
        res = "0";
    } else {
        a[index] = '\0';
        res = a;
    }
    reverse(res.begin(), res.end());
    return res;
}

string add(string a, string b) {
    a = a.substr(a.find_first_not_of('0'));
    b = b.substr(b.find_first_not_of('0'));
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    long long aa = a.length();
    long long bb = b.length();
    long long max = aa > bb ? aa : bb;
    max += 10;
    string result(max, '0');

    for (int i = 0; i < aa; i++) {
        result[i] = a[i];
    }

    int temp = 0;//进位保存 
    for (int i = 0; i < max; i++) {
        if (i < b.length()) {
            temp += (result[i] - '0') + (b[i] - '0');
        } else temp += (result[i] - '0');

        result[i] = temp % 10 + '0';
        temp /= 10;
    }

    reverse(result.begin(), result.end());
    result = result.substr(result.find_first_not_of('0'));
    return result;
}

/**此方法一定保证a >ｂ不是的话　调换*/
string subtract(string a, string b) {
    a = a.substr(a.find_first_not_of('0'));
    b = b.substr(b.find_first_not_of('0'));
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    long long aa = a.length();
    long long bb = b.length();
    long long max = aa > bb ? aa : bb;
    string result(max, '0');

    for (int i = 0; i < aa; i++) {
        result[i] = a[i];
    }

    for (int i = 0; i < max; i++) {
        if (i < b.length()) {
            int up = result[i] - '0';
            int bottom = b[i] - '0';
            if (up >= bottom) {
                result[i] = '0' + up - bottom;
            } else {
                int k = 1;
                /**100 - 9 的情况  不能一味的借位减一*/
                while (result[i + k] == '0') {
                    result[i + k] = '9';
                    k++;
                }

                result[i + k] = (result[i + k] - '0' - 1) + '0';
                result[i] = (10 - (b[i] - '0') + result[i] - '0') + '0';
            }
        }
    }

    reverse(result.begin(), result.end());
    int split = result.find_first_not_of('0');
    if (split == string::npos) {
        return "0";
    } else return result.substr(split);

}

/**a < b 情况*/
string divide(string a, string b) {
    string res = "0.";
    for (int i = 0; i < 101; i++) {
        a.append("0");
        int t = 0;
        while (cmp(a, b) >= 0) {
            a = subtract(a, b);
            t++;
        }
        res.append(createStr(t));
    }
    return res;
}

int main() {
    string a = "1";
    string b = "1";

    for (int i = 3; i <= 400; i++) {
        string tmp = b;
        b = add(a, b);
        a = tmp;
    }

    cout << divide(a, b);
}
