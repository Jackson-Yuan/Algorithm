/**
 * 公司里有 n 名员工，每个员工的 ID 都是独一无二的，编号从 0 到 n - 1。公司的总负责人通过 headID 进行标识。
 * 在 manager 数组中，每个员工都有一个直属负责人，
 * 其中 manager[i] 是第 i 名员工的直属负责人。对于总负责人，manager[headID] = -1。题目保证从属关系可以用树结构显示。
 * 公司总负责人想要向公司所有员工通告一条紧急消息。他将会首先通知他的直属下属们，然后由这些下属通知他们的下属，直到所有的员工都得知这条紧急消息。
 * 第 i 名员工需要 informTime[i] 分钟来通知它的所有直属下属（也就是说在 informTime[i] 分钟后，他的所有直属下属都可以开始传播这一消息）。
 * 返回通知所有员工这一紧急消息所需要的 分钟数 。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
private:
    vector<vector<int>> tree;
    int maxValue;
    vector<int> realInformTime;
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime) {
        tree = vector<vector<int>>(manager.size(), vector<int>());
        for (int i = 0; i < manager.size(); ++i) {
            if (manager[i] != -1) {
                tree[manager[i]].push_back(i);
            }
        }
        realInformTime = informTime;
        maxValue = 0;
        dfs(headID, realInformTime[headID]);
        return maxValue;
    }

    void dfs(int start, int time) {
        if (realInformTime[start] == 0) {
            if (time > maxValue) maxValue = time;
            return;
        }

        for (int i = 0; i < tree[start].size(); ++i) {
            dfs(tree[start][i], time + realInformTime[tree[start][i]]);
        }
    }
};
/**
 * 此题转化过来就是求数的最长路径，依然是直接暴力
 * 但直接暴力之前，可以先组织一波数据结构，将哪个点
 * 是哪个店的下属关系先整理好，而不是真无脑暴力
 * 这样暴力可以节省时间复杂度
 * */