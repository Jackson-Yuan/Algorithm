#include "iostream"
#include "vector"

using namespace std;

/**
 * 给你一棵根节点为 0 的二叉树，它总共有 n个节点，节点编号为0到n - 1。同时给你一个下标从0开始的整数数组parents表示这棵树，
 * 其中parents[i]是节点 i的父节点。由于节点 0是根，所以parents[0] == -1。
 * 一个子树的 大小为这个子树内节点的数目。每个节点都有一个与之关联的分数。求出某个节点分数的方法是，将这个节点和与它相连的边全部 删除，
 * 剩余部分是若干个 非空子树，这个节点的 分数为所有这些子树 大小的乘积。
 * 链接：https://leetcode-cn.com/problems/count-nodes-with-the-highest-score
 * */

/**
 * 去掉节点后，值的来源有三个，左右子树，及将以这个节点为根节点的子移除剩余的大小（根节点除外）
 * 本题起初的思路是先统计出各点相连的边，随后开一个数组保存每个点以这个点为根节点的子树大小
 * 这样计算某个点值的时候，直接拿取两个子树节点的值及节点总数减去（两个子树节点+1）的值（根节点除外），三者相乘
 *
 * 但计算每个节点为根节点子树大小用子树保存，时间复杂度是大于o（n）的
 *
 * 我们这时可以想利用dfs，边遍历边计算子树大小
 * */
class Solution {
private:
    long maxScore;
    long ans;
public:
    int countHighestScoreNodes(vector<int> &parents) {
        vector<int> container(parents.size(), 1);
        vector<vector<int>> link(parents.size());

        int n = parents.size();
        maxScore = INT_MIN;
        ans = 0;
        for (int i = 0; i < n; ++i) {
            if (parents[i] != -1) {
                link[parents[i]].push_back(i);
            }
        }

        dfs(0, link);

        return ans;
    }


    int dfs(int index, vector<vector<int>> &link) {
        long score = 1;

        /**
         * 计算移除以这个节点为根节点的子树移除后的大小
         * 用的是拿节点总数减去这个节点左右子树大小，再减去1（这个节点本省）
         * */
        long all = link.size() - 1;

        for (int next : link[index]) {
            int next_val = dfs(next, link);

            score *= next_val;
            all -= next_val;
        }


        /**
         * 如果是根节点，剩余的子树节点为0，不能乘
         * */
        if (index != 0) score *= all;

        if (score == maxScore) {
            ++ans;
        } else if (score > maxScore) {
            ans = 1;
            maxScore = score;
        }


        return link.size() - all;

    }
};

