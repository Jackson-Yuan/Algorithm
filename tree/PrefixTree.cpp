#include "iostream"
#include "string"
#include "string.h"

using namespace std;

/**
 * 字典树（前缀树），主要用于比如啥自动检查，单词联想等
 * 这边字典树只争对英文字符
 *
 * 英文有26个字母，所以不必存储字符本身，可以直接存储一个容量为26的子节点数组
 * 这样在构建，遍历，搜素时，只需检查英文字符对应的索引下标即可
 * */
class Trie {
private:
    Trie *next[26];
    bool isEnd;
public:
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }

    /**
     * 插入字符串
     * */
    void insert(string word) {
        Trie *node = this;
        for (char c : word) {
            if (node->next[c - 'a'] == NULL) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }

    /**
     * 搜索是否包含指定字符串
     * */
    bool search(string word) {
        Trie *node = this;
        for (char c : word) {
            if (!node->next[c - 'a']) return false;
            node = node->next[c - 'a'];
        }
        return node->isEnd;
    }

    /**
     * 搜索是否包含指定字符前缀
     * */
    bool startsWith(string prefix) {
        Trie *node = this;
        for (char c : prefix) {
            if (!node->next[c - 'a']) return false;
            node = node->next[c - 'a'];
        }
        return true;
    }
};

int main() {
    Trie node;
    node.insert("yyc");
    cout << node.search("yyc") << endl;
    cout << node.startsWith("yy") << endl;
}