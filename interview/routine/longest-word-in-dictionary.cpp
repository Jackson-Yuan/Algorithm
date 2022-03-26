#include "iostream"
#include "string"
#include "vector"

using namespace std;
/**
 * ����һ���ַ�������words ��ɵ�һ��Ӣ��ʵ䡣����words �����һ�����ʣ��õ�������words�ʵ����������������һ����ĸ��ɡ�
 * �������ж�����еĴ𰸣��򷵻ش����ֵ�����С�ĵ��ʡ����޴𰸣��򷵻ؿ��ַ�����
 * ���ӣ�https://leetcode-cn.com/problems/longest-word-in-dictionary
 * */

/**
 * ���⸴ϰһ���ֵ�����ǰ׺�������ã�
 * �ο����ӣ�https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==&mid=2247488490&idx=1&sn=db2998cb0e5f08684ee1b6009b974089&chksm=fd9cb8f5caeb31e3f7f67dba981d8d01a24e26c93ead5491edb521c988adc0798d8acb6f9e9d&token=1006889101&lang=zh_CN&scene=21#wechat_redirect
 * ������Ҫ������
 * next���飺�ַ�����ɵ�Ԫ���Ǹ���ֵ��ֱ�ӿ�26��ǰ׺���󲿷�Ӧ�����ַ�����������˼���������������������
 * isEnd����ǰ�ڵ�����Ƿ�����Ŀ�е�һ������һ�����ʵĽ�β�����ǽ����Ǹ�ǰ׺
 *
 * ǰ׺����Ҫ���¼����ص㣺
 * 1��ǰ׺�Ŀ���ƥ�䣬�����ַ����Ĺ���ǰ׺ֻ�ᱣ��һ��
 * 2���ַ������ƥ�䣬��������
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


