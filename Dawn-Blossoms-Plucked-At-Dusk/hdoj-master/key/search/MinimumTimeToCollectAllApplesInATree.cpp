/**
 * 给你一棵有n个节点的无向树，节点编号为0到n-1,它们中有一些节点有苹果。
 * 通过树上的一条边，需要花费1秒钟。你从节点0出发，请你返回最少需要多少秒，可以收集到所有苹果，并回到节点0。
 * 无向树的边由edges给出，其中edges[i]=[fromi, toi]，表示有一条边连接 from 和 toi 。除此以外，还有一个布尔数组 hasApple ，
 * 其中hasApple[i] = true代表节点i有一个苹果，否则,节点i没有苹果。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <string.h>
#include <set>

using namespace std;

class Solution {
private:
    vector<int> graph[100001];
    bool visited[100001];
    vector<int> path;
    set<int> points;
    bool isStop;
public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple) {
        for (int i = 0; i < edges.size(); ++i) {
            int start = edges[i][0], end = edges[i][1];
            graph[start].push_back(end);
            graph[end].push_back(start);
        }
        for (int i = 0; i < hasApple.size(); ++i) {
            if (hasApple[i]) {
                isStop = false;
                memset(visited, 0, sizeof(visited));
                dfs(i);
            }
        }
        int all = points.size() == 0 ? 0 : points.size() - 1;
        return all * 2;
    }

    void dfs(int cur) {
        visited[cur] = true;
        path.push_back(cur);
        if (cur == 0) {
            for (int i = 0; i < path.size(); ++i) {
                points.insert(path[i]);
            }
            isStop = true;
            path.pop_back();
            return;
        }
        vector<int> links = graph[cur];
        for (int i = 0; i < links.size(); ++i) {
            if (!isStop && !visited[links[i]]) {
                visited[links[i]] = true;
                dfs(links[i]);
            }
        }
        path.pop_back();
    }
};
/**
 * 本题求法就是算出根节点到苹果节点所经过的总边数 * 2就是最后的解
 * 但正如思路描述的那样根节点到苹果节点所经过的总边数，很容易产生从根节点开始遍历到所有苹果节点所经历的边的想法，其实这样搞
 * 会有重边现象很难处理，这时就不应该放在去除重边上，而是去除重复点上，可以开个set集合对象保存路径的点，从每个苹果节点开始dfs
 * 寻找根节点，保存经过的点，找到根节点后插入set集合，set会自动去重，每个苹果节点遍历完后，set里的点数减去一就是边数再乘以2完事
 * 当然也可以从根节点遍历整个数，遇到苹果节点，将路径上的点插入set集合，这种方式时间复杂度略低
 * */