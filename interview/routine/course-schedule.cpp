#include "iostream"
#include "vector"

using namespace std;


/**
 * 你这个学期必须选修 numCourses 门课程，记为0到numCourses - 1 。
 * 在选修某些课程之前需要一些先修课程。 先修课程按数组prerequisites 给出，其中prerequisites[i] = [ai, bi] ，表示如果要学习课程ai 则 必须 先学习课程 bi 。
 * 例如，先修课程对[0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
 * 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
 * 链接：https://leetcode-cn.com/problems/course-schedule
 * */

/**
 * 问题直接抽象成判断图中是否有环，bfs，dfs均可
 *
 * 注意这边visited数组，不只是简单的bool，如果是简单的bool，怕是会超时
 * visited在这有三个选项，0，1，2
 * 0代表还未搜索到，1代表搜索中，2代表搜索完成
 * 之所以多出个2是因为，我们在dfs时，是从每个点都做一遍dfs，因为我们判断是否有环（有就行，不是统计多少个环）
 * visited为2代表从这个点我已经搜索过了，如果之前遍历的时候有环你再从这儿搜，搜出来结果还是有环重复搜索了；如果没环，再次进入这个
 * 点往下搜结果依然没环，是用来避免重复计算的，否则如果用布尔值来仅仅区分有没有访问，会导致时间复杂度为平方复杂度
 * */
class Solution {
private:
    vector<int> visited;
    bool isFind;
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> link(numCourses);
        visited = vector<int>(numCourses, 0);
        isFind = false;
        for (vector<int> &cur : prerequisites) {
            link[cur[0]].push_back(cur[1]);
        }


        for (int i = 0; i < numCourses; ++i) {
            if (!isFind) {
                dfs(i, link);
            } else break;
        }

        return !isFind;
    }


    void dfs(int index, vector<vector<int>> &link) {
        visited[index] = 1;

        vector<int> &next = link[index];

        for (int val : next) {
            if (!isFind && visited[val] == 0) {
                dfs(val, link);
            } else if (visited[val] == 1) {
                isFind = true;
                break;
            }
        }

        visited[index] = 2;
    }
};

