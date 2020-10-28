/**
 * hdoj 1088
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    string str;
    int count = 0;
    while (cin >> str) {
        if (str.length() == 0) continue;
        /**去除多余空格*/
        if (str == "<br>") {
            count = 0;
            cout << endl;
        } else if (str == "<hr>") {
            if (count == 0)
                cout << "--------------------------------------------------------------------------------" << endl;
            else {
                cout << endl << "--------------------------------------------------------------------------------"
                     << endl;
                count = 0;
            }
        } else {
            /**输出单词*/
            /**若这个单词是开头第一个，不需要计算空格*/
            if (count == 0) {
                if (count + str.size() <= 80) {
                    cout << str;
                    count += str.size();
                } else {
                    cout << endl;
                    count = 0;
                    cout << str;
                    count += str.size();
                }
            } else {/**否则要将空格算作一个字符并打印*/
                if (count + 1 + str.size() <= 80) {
                    cout << " " << str;
                    count += 1 + str.size();
                } else {
                    cout << endl;
                    count = 0;
                    cout << str;
                    count += str.size();
                }
            }
        }
    }

    cout << endl;


    return 0;
}
/**
 * 此题本打算getline读入一行 结果被坑
 * 空格手动加入就行
 * 考验字符串功力
 * */