/**
 * 用字符串表示的一些大数运算
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

/**整形转字符串，例题需要*/
string intToStr(int val) {
    string res;
    while (val) {
        int tmp = val % 10;
        res.append(1, '0' + tmp);
        val /= 10;
    }

    reverse(res.begin(), res.end());
    return res;
}

/**加法*/
string add(string a, string b) {
    /**去除前导0*/
    int indexA = a.find_first_not_of('0');
    if (indexA == string::npos) a = "0";
    else a = a.substr(indexA);
    int indexB = b.find_first_not_of('0');
    if (indexB == string::npos) b = "0";
    else b = b.substr(indexB);


    /**开始加法运算*/
    reverse(a.begin(), a.end());
    indexA = 0;
    reverse(b.begin(), b.end());
    indexB = 0;
    string res;
    int extra = 0;
    while (indexA < a.length() && indexB < b.length()) {
        int tmp = (a[indexA] - '0') + (b[indexB] - '0') + extra;
        char tmpValue = '0' + tmp % 10;
        extra = tmp / 10;
        res.append(1, tmpValue);
        ++indexA;
        ++indexB;
    }

    /**可能a字符串位数多*/
    while (indexA < a.length()) {
        int tmp = (a[indexA] - '0') + extra;
        char tmpValue = '0' + tmp % 10;
        extra = tmp / 10;
        res.append(1, tmpValue);
        ++indexA;
    }

    /**可能b字符串位数较多(两者只有一个可能)*/
    while (indexB < b.length()) {
        int tmp = (b[indexB] - '0') + extra;
        char tmpValue = '0' + tmp % 10;
        extra = tmp / 10;
        res.append(1, tmpValue);
        ++indexB;
    }

    /**进位还存在*/
    if (extra > 0) {
        char tmpValue = '0' + extra % 10;
        res.append(1, tmpValue);
    }

    reverse(res.begin(), res.end());

    return res;
}

/**减法*/
string substract(string a, string b) {
    /**默认a > b*/
    int indexA = a.find_first_not_of('0');
    if (indexA == string::npos) a = "0";
    else a = a.substr(indexA);
    int indexB = b.find_first_not_of('0');
    if (indexB == string::npos) b = "0";
    else b = b.substr(indexB);

    /**开始逐个相减*/
    reverse(a.begin(), a.end());
    indexA = 0;
    reverse(b.begin(), b.end());
    indexB = 0;
    string res;
    while (indexA < a.length() && indexB < b.length()) {
        int tmpA = a[indexA] - '0';
        int tmpB = b[indexB] - '0';
        int target;
        /**够减直接减掉*/
        if (tmpA >= tmpB) target = tmpA - tmpB;
        else {
            /**不够减借位，若借位为0，变9继续向前借位*/
            int start = indexA + 1;
            /**虽说这个有个start < a,length() 但由于a > b 永远不会违反这个条件*/
            while (start < a.length() && a[start] == '0') {
                a[start] = '9';
                ++start;
            }
            /**找到一个非0位，减1*/
            a[start] = (char) (a[start] - 1);
            /**若减去1为0，不应该0给去掉，如0101，变为0001，减去就gg了*/
            /**if (a[start] == '0') a = a.substr(0, start);*/

            target = 10 + tmpA - tmpB;
        }

        res.append(1, '0' + target);
        ++indexA;
        ++indexB;
    }

    /**b的位数小于等于a的位数，所以只有a可能有结余，一个个赋值即可*/
    while (indexA < a.length()) {
        res.append(1, a[indexA]);
        ++indexA;
    }

    reverse(res.begin(), res.end());
    /**如200 - 137 结果是063，把前导0抹去*/
    int index = res.find_first_not_of('0');
    if (index == string::npos) res = "0";
    else res = res.substr(index);

    return res;
}

/**判断大小，仅限与两个正数*/
bool compare(string a, string b) {
    int indexA = a.find_first_not_of('0');
    if (indexA == string::npos) a = "0";
    else a = a.substr(indexA);
    int indexB = b.find_first_not_of('0');
    if (indexB == string::npos) b = "0";
    else b = b.substr(indexB);

    if (a.length() > b.length()) return true;
    else if (a.length() < b.length()) return false;
    else {
        return a >= b;
    }
}

/**除法，仅限正数，整数除法*/
string divide(string a, string b) {
    if (!compare(a, b)) return "0";

    int indexA = a.find_first_not_of('0');
    if (indexA == string::npos) a = "0";
    else a = a.substr(indexA);
    int indexB = b.find_first_not_of('0');
    if (indexB == string::npos) b = "0";
    else b = b.substr(indexB);

    /**运用大数相减，相减求商*/
    string res = "0";
    while (compare(a, b)) {
        a = substract(a, b);
        res = add(res, "1");
    }

    return res;

}

/**取模，仅限正数*/
string mod(string a, string b) {
    int indexA = a.find_first_not_of('0');
    if (indexA == string::npos) a = "0";
    else a = a.substr(indexA);
    int indexB = b.find_first_not_of('0');
    if (indexB == string::npos) b = "0";
    else b = b.substr(indexB);

    while (compare(a, b)) {
        a = substract(a, b);
    }
    cout << "hhhh";

    return a;
}

/**乘法，因为例题设计进制乘法，一个乘数直接整形即可*/
string multiple(string a, int b) {
    string res = "0";
    reverse(a.begin(), a.end());
    int base = 1;
    for (int i = 0; i < a.length(); ++i) {
        int tmp = b * (a[i] - '0') * base;
        res = add(res, intToStr(tmp));
        base *= 10;
    }

    return res;
}

int main() {
    int m, n;
    string x;
    while (cin >> m >> n >> x) {
        string current = "0";
        reverse(x.begin(), x.end());
        int base = 1;
        for (int i = 0; i < x.length(); ++i) {
            string target;
            if (x[i] >= '0' && x[i] <= '9') {
                target = string(1, x[i]);
            } else {
                target = intToStr(10 + x[i] - 'A');
            }
            string tmp = multiple(target, base);
            base *= m;
            current = add(current, tmp);
        }

        string res;
        while (current != "0") {
            string tmp = mod(current, intToStr(n));
            res.append(tmp);
            current = divide(current, intToStr(n));
        }

        reverse(res.begin(), res.end());

        cout << res;
    }


}
