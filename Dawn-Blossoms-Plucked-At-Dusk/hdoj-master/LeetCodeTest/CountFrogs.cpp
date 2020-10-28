/**
 * 给你一个字符串 croakOfFrogs，它表示不同青蛙发出的蛙鸣声（字符串 "croak" ）的组合。由于同一时间可以有多只青蛙呱呱作响，
 * 所以 croakOfFrogs 中会混合多个 “croak” 。请你返回模拟字符串中所有蛙鸣所需不同青蛙的最少数目。
 * 注意：要想发出蛙鸣 "croak"，青蛙必须 依序 输出 ‘c’, ’r’, ’o’, ’a’, ’k’ 这 5 个字母。如果没有输出全部五个字母，那么它就不会发出声音。
 * 如果字符串 croakOfFrogs 不是由若干有效的 "croak" 字符混合而成，请返回 -1 。
 *
 * 输入：croakOfFrogs = "croakcroak"
 * 输出：1
 * 解释：一只青蛙 “呱呱” 两次
 *
 * 输入：croakOfFrogs = "crcoakroak"
 * 输出：2
 * 解释：最少需要两只青蛙，“呱呱” 声用黑体标注
 * 第一只青蛙 "crcoakroak"
 * 第二只青蛙 "crcoakroak"
 *
 * 输入：croakOfFrogs = "croakcrook"
 * 输出：-1
 * 解释：给出的字符串不是 "croak" 的有效组合。
 * */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c = 0, r = 0, o = 0, a = 0, k = 0;
        int res = 0;
        for (int i = 0; i < croakOfFrogs.length(); ++i) {
            if (croakOfFrogs[i] == 'c') {
                if (k > 0) {
                    --k;
                } else {
                    ++res;
                }
                ++c;
            } else if (croakOfFrogs[i] == 'r') {
                --c;
                ++r;
            } else if (croakOfFrogs[i] == 'o') {
                --r;
                ++o;
            } else if (croakOfFrogs[i] == 'a') {
                --o;
                ++a;
            } else if (croakOfFrogs[i] == 'k') {
                --a;
                ++k;
            }

            if (c < 0 || r < 0 || o < 0 || a < 0 || k < 0) return -1;
        }

        if (c != 0 || r != 0 || o != 0 || a != 0) return -1;
        return res;
    }
};
/**
 * 本题其实思路，是个人都懂，就是数吗，且要注意每个字母的先后顺序
 * 但如何实现是关键
 * 而此题，如循环中代码所演示的操作，遍历到字母，对应的奇数器加一，同时按顺序上前一个字母计数器对应减一
 * 这样一次循环下来，若出现负数，则代表顺序不对，很巧妙
 * 同时对于字母残缺的判断，不要带有k计数器的判断
 * */