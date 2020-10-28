/**
 * 有多组数据，每组一行，每组就是一篇小文章。每篇小文章都是由小写字母和空格组成，没有标点符号，遇到#时表示输入结束。
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
    while (true) {
        getline(cin, str);
        if (str == "#") break;
        int count = 0;
        map<string, bool> map;
        int start = 0;
        while (start < str.length() && str[start] == ' ') ++start;
        for (int i = start; i < str.length(); ++i) {
            if (str[i] == ' ') {
                string tmp = str.substr(start, i - start);
                /**去除多余截取的空串*/
                if (!map[tmp] && tmp != "") {
                    ++count;
                    map[tmp] = true;
                }
                start = i + 1;
            }
        }

        /**遍历完，若整个句子尾部没有空格，那么尾部的单词也要算进去判断，若有空格依然去除*/
        if (start < str.length()) {
            string tmp = str.substr(start);
            if (!map[tmp] && tmp != "") {
                ++count;
                map[tmp] = true;
            }
        }


        cout << count << endl;
    }
    return 0;
}
/**
 * 统计一行句子中的不同单词个数
 * 不同解决方式用hash，还要注意整个句子前的空格与整个句子后的空格处理
 * */