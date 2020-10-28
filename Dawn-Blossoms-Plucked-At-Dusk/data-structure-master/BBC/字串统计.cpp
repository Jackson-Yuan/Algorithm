#include<iostream>
#include<string>

using namespace std;

int main() {
    int len, count;
    int max = -1;
    cin >> len;
    string result = "";
    string s;
    cin >> s;
    int length = s.length();
    for (int i = len; i <= length; i++) {
        for (int j = 0; j <= length - i; j++) {
            string temp = s.substr(j, i);//子串样本
            count = 0;
            for (int k = 0; k <= length - i; k++) {
                string temp2 = s.substr(k, i);//开始统计
                if (temp2 == temp) count++;
            }

            if (count > max) {
                max = count;
                result = temp;
            } else if (count == max && result.length() < temp.length()) {
                result = temp;
            }
        }
    }
    cout << result << endl;
}
/*暴力穷举出所有子串 并统计次数 思路简单 但需要了解string类和 其相关api*/
