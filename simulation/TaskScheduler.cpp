/**
 * 给你一个用字符数组tasks 表示的 CPU 需要执行的任务列表。其中每个字母表示一种不同种类的任务。任务可以以任意顺序执行
 * 并且每个任务都可以在 1 个单位时间内执行完。在任何一个单位时间，CPU 可以完成一个任务，或者处于待命状态。
 * 然而，两个 相同种类 的任务之间必须有长度为整数 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。
 * 你需要计算完成所有任务所需要的 最短时间 。
 * */
#include "iostream"
#include "map"
#include "vector"

using namespace std;

class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        map<char, int> freq;
        for (char ch: tasks) {
            ++freq[ch];
        }

        // 任务总数
        int m = freq.size();
        vector<int> nextValid, rest;
        for (auto[_, v]: freq) {
            nextValid.push_back(1);
            rest.push_back(v);
        }

        int time = 0;
        for (int i = 0; i < tasks.size(); ++i) {
            ++time;
            int minNextValid = INT_MAX;
            for (int j = 0; j < m; ++j) {
                if (rest[j]) {
                    minNextValid = min(minNextValid, nextValid[j]);
                }
            }

            time = max(time, minNextValid);
            int best = -1;
            for (int j = 0; j < m; ++j) {
                if (rest[j] && nextValid[j] <= time) {
                    /**某一类任务数多优先分配*/
                    if (best == -1 || rest[j] > rest[best]) {
                        best = j;
                    }
                }
            }
            nextValid[best] = time + n + 1;
            --rest[best];
        }

        return time;
    }
};
/**
 * 此题直接模拟分配过程，有贪心的思想在里面，即一类任务多的优先分配
 * 核心在于开两个数组，存储某类任务的剩余个数即下次合法调度时间（rest数组与nextValid数组）
 * 开始时所有类型的任务合法时间均为1，开始遍历task数组，先自增时间
 * 然后挑选所有类型下次开始合法调度时间的最小值，与自增的time的作比较取较大的
 * 然后再次遍历所有类型选取最佳类型，原则为：
 * 有剩余个数，且下次合法调度时间不得大于time，且优先分配拥有任务数多的类型
 * 分配完后，也需修改对应的下次合法调度时间与剩余数量
 * */