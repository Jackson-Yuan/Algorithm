/**
 * 前一个是字符串大数运算，其实那玩意儿实现大数运算较慢
 * 此方法实现原理，是四位数为一个单位，加减乘除都以四位
 * 为一个单位进行运算，快速，有效
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

struct bigInteger {
    vector<int> digit;/**四位为一个单元*/
    void output() {
        for (int i = digit.size() - 1; i >= 0; --i) {
            if (i != digit.size() - 1) printf("%04d", digit[i]);
            else printf("%d", digit[i]);
        }
    };

    void strToBigInteger(string str) {
        reverse(str.begin(), str.end());
        int base = 1;
        int tmp = 0;
        for (int i = 0; i < str.length(); ++i) {
            if (i != 0 && i % 4 == 0) {
                digit.push_back(tmp);
                base = 1;
                tmp = 0;
            }
            tmp += (str[i] - '0') * base;
            base *= 10;

            if (i == str.length() - 1) {
                digit.push_back(tmp);
            }
        }

        while (digit.size() > 1 && digit[digit.size() - 1] == 0) digit.pop_back();/**防止碰见00000001这种情况*/
    };

    string bigIntegerToStr() {
        string res;
        for (int i = digit.size() - 1; i >= 0; --i) {
            string cur;
            int val = digit[i];
            do {
                cur.append(1, '0' + val % 10);
                val /= 10;
            } while (val);
            if (i != digit.size() - 1) {
                while (cur.length() < 4) cur.append(1, '0');
            }
            reverse(cur.begin(), cur.end());
            res.append(cur);
        }

        return res;
    }
};

/**加法*/
bigInteger add(bigInteger a, bigInteger b) {
    int indexA = 0, indexB = 0;
    int extra = 0;
    bigInteger res;
    while (indexA < a.digit.size() && indexB < b.digit.size()) {
        int tmp = a.digit[indexA] + b.digit[indexB] + extra;
        res.digit.push_back(tmp % 10000);
        extra = tmp / 10000;
        ++indexA;
        ++indexB;
    }

    while (indexA < a.digit.size()) {
        int tmp = a.digit[indexA] + extra;
        res.digit.push_back(tmp % 10000);
        extra = tmp / 10000;
        ++indexA;
    }

    while (indexB < b.digit.size()) {
        int tmp = b.digit[indexA] + extra;
        res.digit.push_back(tmp % 10000);
        extra = tmp / 10000;
        ++indexB;
    }

    if (extra > 0) {
        res.digit.push_back(extra);
    }

    return res;
}

/**减法 默认a > b*/
bigInteger sub(bigInteger a, bigInteger b) {
    int indexA = 0, indexB = 0;
    bigInteger res;
    while (indexA < a.digit.size() && indexB < b.digit.size()) {
        int tmpA = a.digit[indexA], tmpB = b.digit[indexB];
        int target;
        if (tmpA >= tmpB) target = tmpA - tmpB;
        else {
            int start = indexA + 1;
            /**默认a > b 所以start不会越界*/
            while (a.digit[start] == 0) {
                a.digit[start] = 9999;
                ++start;
            }

            a.digit[start] -= 1;
            target = 10000 + tmpA - tmpB;
        }

        res.digit.push_back(target);
        ++indexA;
        ++indexB;
    }

    while (indexA < a.digit.size()) {
        res.digit.push_back(a.digit[indexA]);
        ++indexA;
    }

    /**去除多余的0 如10000001 - 9999999  到这一步时为digit数组里面为20  0是多余的得弹出*/
    while (res.digit.size() > 1 && res.digit[res.digit.size() - 1] == 0) {
        res.digit.pop_back();
    }


    return res;
}

/**乘法 乘以一个小整数*/
bigInteger multiple(bigInteger a, int b) {
    int indexA = 0, extra = 0;
    bigInteger res;
    while (indexA < a.digit.size()) {
        int tmp = a.digit[indexA] * b + extra;
        extra = tmp / 10000;
        res.digit.push_back(tmp % 10000);
        ++indexA;
    }
    /**进位算上*/
    if (extra > 0) res.digit.push_back(extra);

    return res;
}

/**除法 除以一个小整数*/
bigInteger divide(bigInteger a, int b) {
    bigInteger res;
    int remain = 0;
    /**除法实现原理，可以参考笔算除法*/
    for (int i = a.digit.size() - 1; i >= 0; --i) {
        int current = remain * 10000 + a.digit[i];
        res.digit.push_back(current / b);
        remain = current % b;
    }

    reverse(res.digit.begin(), res.digit.end());

    /**去除多余的0， 如100000除以500，经过上面代码 此时digit数组为200、0,而后面这个0是多余的，可由笔算除法可知，所以得弹出*/
    while (res.digit.size() > 1 && res.digit[res.digit.size() - 1] == 0) res.digit.pop_back();

    return res;
}

/**取模,模一个小整数*/
int mod(bigInteger a, int b) {
    int remain = 0;
    for (int i = a.digit.size() - 1; i >= 0; --i) {
        int current = remain * 10000 + a.digit[i];
        remain = current % b;
    }

    return remain;
}

/**M进制数k转为n进制数，包含大数*/
int main() {
    int m, n;
    string k;
    while (cin >> m >> n >> k) {
        bigInteger base;
        base.strToBigInteger("1");
        bigInteger current;
        current.strToBigInteger("0");
        for (int i = k.length() - 1; i >= 0; --i) {
            int tmp;
            if (k[i] >= '0' && k[i] <= '9') tmp = k[i] - '0';
            else tmp = 10 + k[i] - 'A';
            bigInteger tmpValue = multiple(base, tmp);
            current = add(current, tmpValue);
            base = multiple(base, m);
        }

        string res;
        while ((current.digit.size() > 1) || (current.digit.size() == 1 && current.digit[0] != 0)) {
            int tmp = mod(current, n);
            char tmpValue;
            if (tmp < 10) tmpValue = '0' + tmp;
            else tmpValue = 'A' + 10 - tmp;
            res.append(1, tmpValue);
            current = divide(current, n);
        }

        reverse(res.begin(), res.end());

        cout << res << " " << res.length() << endl;
    }

    return 0;
}