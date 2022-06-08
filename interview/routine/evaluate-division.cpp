#include "iostream"
#include "vector"
#include "string"
#include "map"

using namespace std;

/**
 * 给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，
 * 其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。
 * 另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。
 * 返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0 替代这个答案。
 * 注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。
 * 链接：https://leetcode-cn.com/problems/evaluate-division
 * */


/**
 * 本题转化为图的并查集问题，比较好理解
 * 如 a / b = 2，b / c = 3
 * 即a = 2b，b=3c，即a=6c，变化为同一个变量表示
 * 这个过程视为a->b b->c 以c为root的连通图，同时除了并查集的root数组，额外开一个weight数组，代表当前的元素是根元素的几倍
 *
 * 具体解释查看链接相应题解
 *
 * 这边着重说一下 为何用递归的方式实现并查集的find
 * 并查集中有路径压缩的操作，主要为了防止查询根节点的嵌套次数过深，从而将子节点直接与根节点相连（并查集着重强调连通关系，点与点层次链接没那么重要）
 * 但由于我们的weight数组记录了当前节点是根节点的几倍，若无脑进行路径压缩，而不同步更新weight数组，则会导致结果错误
 * 如：a->b b->c 路径压缩的目标为 a->c b->c 同时weight数组，a，b需对应6c 3c
 * 那么在这种情况的并查集构建中，首先不进行路径压缩情况下，root数组中 a指向b，b指向c 若进行路径压缩，a的weight值需乘上b的weight值才能保证一致（同理b的weight值需乘上他的root指向的weight值）
 * 而常规的循环方式无法解决，不满足后进先算的方式（因为路径压缩中，你想更新a的weight，就必须得到最新的b的weight，而循环查找，却从a开始，与计算步骤相反），
 * 如果用递归恰好满足这种特性
 *
 * 同期还要注意，当检查两个点连通性，需要认祖归宗时，需要更新被认祖归宗的节点值，理解其推导公式
 * */
class Solution {
private:
    vector<int> root;
    vector<double> weight;
public:
    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {

        map<string, int> m;
        int id = 0;
        for (int i = 0; i < equations.size(); ++i) {
            vector<string> cur = equations[i];
            string start = cur[0], end = cur[1];

            if (m.find(start) == m.end()) {
                m[start] = id;
                ++id;
            }

            if (m.find(end) == m.end()) {
                m[end] = id;
                ++id;
            }

        }

        root = vector<int>(id, -1);
        weight = vector<double>(id, 1);

        for (int i = 0; i < equations.size(); ++i) {
            vector<string> cur = equations[i];
            int startIndex = m[cur[0]], endIndex = m[cur[1]];
            double ratio = values[i];

            int startRoot = find(startIndex), endRoot = find(endIndex);

            if (startRoot != endRoot) {
                root[startRoot] = endRoot;
                weight[startRoot] = (ratio * weight[endIndex]) / weight[startIndex];
            }
        }


        vector<double> ans;
        for (vector<string> &cur: queries) {
            auto one = m.find(cur[0]);
            auto two = m.find(cur[1]);

            if (one != m.end() && two != m.end()) {
                int oneRoot = find(one->second);
                int twoRoot = find(two->second);

                if (oneRoot == twoRoot) {
                    ans.push_back(weight[one->second] / weight[two->second]);
                } else ans.push_back(-1);
            } else ans.push_back(-1);
        }

        return ans;
    }


    int find(int x) {
        if (root[x] != -1) {
            int next = root[x];
            root[x] = find(next);
            weight[x] *= weight[next];
            return root[x];
        } else return x;
    }

};

int main() {
    vector<vector<string>> equations = {{"a", "b"},
                                        {"b", "c"}};
    vector<double> value = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"},
                                      {"b", "a"},
                                      {"a", "e"},
                                      {"a", "a"},
                                      {"x", "x"}};

    Solution solution;

    vector<double> ans = solution.calcEquation(equations, value, queries);

    for (double cur: ans) {
        cout << cur << " ";
    }
}
