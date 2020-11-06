/**
 * 给定两个单词（beginWord和 endWord）和一个字典，找到从beginWord 到endWord 的最短转换序列的长度。转换需遵循如下规则：
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 说明:

 * 如果不存在这样的转换序列，返回 0。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * */
#include "iostream"
#include "vector"
#include "map"
#include "unordered_map"
#include "queue"

using namespace std;

class Solution {
public:
    unordered_map<string, int> wordId;
    vector<vector<int>> edge;
    int nodeNum = 0;

    void addWord(string &word) {
        if (!wordId.count(word)) {
            wordId[word] = nodeNum++;
            edge.emplace_back();
        }
    }

    void addEdge(string &word) {
        addWord(word);
        int id1 = wordId[word];
        for (char &it : word) {
            char tmp = it;
            it = '*';
            addWord(word);
            int id2 = wordId[word];
            edge[id1].push_back(id2);
            edge[id2].push_back(id1);
            it = tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        for (string &word : wordList) {
            addEdge(word);
        }
        addEdge(beginWord);
        if (!wordId.count(endWord)) {
            return 0;
        }
        vector<int> dis(nodeNum, INT_MAX);
        int beginId = wordId[beginWord], endId = wordId[endWord];
        dis[beginId] = 0;

        queue<int> que;
        que.push(beginId);
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            if (x == endId) {
                return dis[endId] / 2 + 1;
            }
            for (int &it : edge[x]) {
                if (dis[it] == INT_MAX) {
                    dis[it] = dis[x] + 1;
                    que.push(it);
                }
            }
        }
        return 0;
    }
};
/**
 * 此题是把单词变换的过程转化成图中节点的搜索
 * 即一个单词看成一个节点，根据题意变动一个字母
 * 变为另外一个单词的过程等价于这两个单词的节点
 * 是连通的，这样就转化为图中求两个节点最短距离问题
 * 在建立点与点是否连通的过程中，如果通过枚举比较两个
 * 单词是否差一个单词，十分耗费时间，不如引入虚节点
 * 例如单词lit，虚节点为*it, l*t, li*，这样lit经过
 * 一次变化变成的单词也必然会连到这个虚节点上，只是最后算距离
 * 时要除以2，因为本来两点的距离，引入虚节点之后，变为两个点到
 * 虚节点之和，最后还要加1，是因为只是边长，根据题目条件得算上开始单词的计数
 * */