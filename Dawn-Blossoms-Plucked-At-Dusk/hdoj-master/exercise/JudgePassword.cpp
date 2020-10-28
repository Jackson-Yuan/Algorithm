/**
 * 首先，我们就要设置一个安全的密码。那什么样的密码才叫安全的呢？一般来说一个比较安全的密码至少应该满足下面两个条件：
 * (1).密码长度大于等于8，且不要超过16。
 * (2).密码中的字符应该来自下面“字符类别”中四组中的至少三组。
 * 这四个字符类别分别为：
 * 1.大写字母：A,B,C...Z;
 * 2.小写字母：a,b,c...z;
 * 3.数字：0,1,2...9;
 * 4.特殊符号：~,!,@,#,$,%,^;
 * 给你一个密码，你的任务就是判断它是不是一个安全的密码。(输入的密码仅由上面的四类组成)
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
        if (str.length() < 8 || str.length() > 16) {
            cout << "NO" << endl;
            continue;
        }
        int count[4] = {0};

        for (int i = 0; i < str.length(); ++i) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                ++count[0];
            } else if (str[i] >= 'a' && str[i] <= 'z') {
                ++count[1];
            } else if (str[i] >= '0' && str[i] <= '9') {
                ++count[2];
            } else {
                ++count[3];
            }
        }

        int val = 0;
        for (int i = 0; i < 4; ++i) {
            if (count[i] > 0) ++val;
        }

        if (val >= 3) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}