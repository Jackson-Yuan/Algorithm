/**
 * next数组方法实现kmp
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    string base, target;
    while (cin >> base >> target) {
        vector<int> next(target.length(), 0);
        int i = 0, j = 1;
        while (j < target.length()) {
            if (target[i] == target[j]) {
                next[j] = i + 1;
                ++j;
                ++i;
            } else {
                if (i != 0) i = next[i - 1];
                else {
                    next[j] = 0;
                    ++j;
                }
            }
        }
        int start = -1;
        j = 0, i = 0;
        while (i < base.length()) {
            if (base[i] == target[j]) {
                ++i;
                ++j;
            } else {
                if (j == 0) {/**j已经没法退后了，只能移动i指针选择与目标串第一个字符相匹配*/
                    ++i;
                    continue;
                } else j = next[j - 1];/**当前字符不匹配，且j有后退的余地，则查看当前索引前一个位置的字符，以这个字符为结尾的next数组大小为多少*/
            }
            if (j == target.length()) {
                start = i - target.length();
                break;
            }
        }

        cout << start << endl;
    }

    return 0;
}
/**
 * kmp算法的核心思路在于寻找最大的前缀与后缀相同字符串的长度
 * next数组就是记录索引为i的字符结尾的字符串，前缀与后缀相等的最大长度
 * 当初始串与目标串相比较时，若在一个位置不匹配，一方面说明了此位置前面的
 * 字符都与目标串匹配，则寻找目标串前一个位置的索引的next[i]得出已经匹配字符串的
 * 最大公共前后缀的长度，因后缀与前缀相等且最大，将后缀相等的部分替换为前缀相等的部分(相当于目标串右移，代码中体现在j指针指向前缀索引的下一个)
 * 然后匹配前缀的下一个索引在与发送不匹配的初始串地址再次比较
 * */