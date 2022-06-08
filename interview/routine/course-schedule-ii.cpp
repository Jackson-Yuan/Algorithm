#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"

using namespace std;
/**
 * 现在你总共有 numCourses 门课需要选，记为0到numCourses - 1。给你一个数组prerequisites ，其中 prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修bi 。
 * 例如，想要学习课程 0 ，你需要先完成课程1 ，我们用一个匹配来表示：[0,1] 。
 * 返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。
 * 链接：https://leetcode-cn.com/problems/course-schedule-ii
 * */

/**
 * 拓扑排序典型应用，BFS与DFS解法，BFS符合逻辑，DFS逆向思维
 * */
class Solution {
private:
    vector<vector<int>> graph;
    vector<int> indegree;
    vector<int> visited;
    vector<int> ans;
    bool isValid;
public:
    vector<int> findOrderByBFS(int numCourses, vector<vector<int>> &prerequisites) {
        indegree = vector<int>(numCourses, 0);
        graph = vector<vector<int>>(numCourses);

        for (vector<int> &cur: prerequisites) {
            int start = cur[1], end = cur[0];
            ++indegree[end];
            graph[start].push_back(end);
        }

        queue<int> q;
        for (int i = 0; i < indegree.size(); ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            int root = q.front();
            q.pop();
            ans.push_back(root);

            for (int next: graph[root]) {
                --indegree[next];
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        if (ans.size() == numCourses) return ans;
        else return {};
    }

    vector<int> findOrderByDFS(int numCourses, vector<vector<int>> &prerequisites) {
        visited = vector<int>(numCourses, 0);
        graph = vector<vector<int>>(numCourses);

        for (vector<int> &cur: prerequisites) {
            int start = cur[1], end = cur[0];
            graph[start].push_back(end);
        }


        ans.clear();
        isValid = true;
        for (int i = 0; i < numCourses; ++i) {
            if (isValid && visited[i] == 0) {
                dfs(i);
            }
        }


        if (isValid) {
            reverse(ans.begin(), ans.end());
            return ans;
        } else {
            ans.clear();
            return ans;
        }
    }


    void dfs(int start) {
        visited[start] = 1;

        for (int next: graph[start]) {
            if (isValid && visited[next] == 0) {
                dfs(next);
            } else if (isValid && visited[next] == 1) {
                isValid = false;
                break;
            }
        }

        visited[start] = 2;
        ans.push_back(start);
    }
};

int main() {
    Solution solution;

    vector<vector<int>> link = {{1, 0},
                                {2, 6},
                                {1, 7},
                                {5, 1},
                                {6, 4},
                                {7, 0},
                                {0, 5}};

    vector<int> ans = solution.findOrderByBFS(8, link);
}

