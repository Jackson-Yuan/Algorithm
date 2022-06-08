#include "iostream"
#include "string"
#include "vector"

using namespace std;
/**
 * 给出一个字符串数组words 组成的一本英语词典。返回words 中最长的一个单词，该单词是由words词典中其他单词逐步添加一个字母组成。
 * 若其中有多个可行的答案，则返回答案中字典序最小的单词。若无答案，则返回空字符串。
 * 链接：https://leetcode-cn.com/problems/longest-word-in-dictionary
 * */

/**
 * 本题复习一下字典树（前缀树的运用）
 * 参考链接：https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==&mid=2247488490&idx=1&sn=db2998cb0e5f08684ee1b6009b974089&chksm=fd9cb8f5caeb31e3f7f67dba981d8d01a24e26c93ead5491edb521c988adc0798d8acb6f9e9d&token=1006889101&lang=zh_CN&scene=21#wechat_redirect
 * 两个重要参数：
 * next数组：字符串组成的元素是个定值，直接开26（前缀树大部分应用于字符串，但这种思想可以套用至其他场景）
 * isEnd：当前节点表明是否是题目中的一个串（一个单词的结尾）还是仅仅是个前缀
 *
 * 前缀树主要以下几个特点：
 * 1、前缀的快速匹配，几个字符串的公共前缀只会保留一份
 * 2、字符串间的匹配，比如这题
 * */

class Trie {
private:
    vector<Trie *> children;
    bool isEnd;

public:
    Trie() {
        this->children = vector<Trie *>(26, NULL);
        this->isEnd = false;
    }


    void insert(string &word) {
        Trie *start = this;
        for (char val : word) {
            int index = val - 'a';
            if (start->children[index] == NULL) {
                start->children[index] = new Trie();
            }
            start = start->children[index];
        }

        start->isEnd = true;
    }


    bool search(string &word) {
        Trie *start = this;

        for (char val : word) {
            int index = val - 'a';
            if (start->children[index] == NULL || !(start->children[index]->isEnd)) return false;
            start = start->children[index];
        }

        return start != NULL && start->isEnd;
    }
};

class Solution {
public:
    string longestWord(vector<string> &words) {
        Trie trie;
        for (auto &val : words) {
            trie.insert(val);
        }

        string ans = "";

        for (auto &val : words) {
            if (trie.search(val)) {
                if (val.length() > ans.length()) {
                    ans = val;
                } else if (val.length() == ans.length() && val < ans) {
                    ans = val;
                }
            }
        }


        return ans;
    }
};


