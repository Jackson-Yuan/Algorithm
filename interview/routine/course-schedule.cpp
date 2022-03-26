#include "iostream"
#include "vector"

using namespace std;


/**
 * �����ѧ�ڱ���ѡ�� numCourses �ſγ̣���Ϊ0��numCourses - 1 ��
 * ��ѡ��ĳЩ�γ�֮ǰ��ҪһЩ���޿γ̡� ���޿γ̰�����prerequisites ����������prerequisites[i] = [ai, bi] ����ʾ���Ҫѧϰ�γ�ai �� ���� ��ѧϰ�γ� bi ��
 * ���磬���޿γ̶�[0, 1] ��ʾ����Ҫѧϰ�γ� 0 ������Ҫ����ɿγ� 1 ��
 * �����ж��Ƿ����������пγ̵�ѧϰ��������ԣ����� true �����򣬷��� false ��
 * ���ӣ�https://leetcode-cn.com/problems/course-schedule
 * */

/**
 * ����ֱ�ӳ�����ж�ͼ���Ƿ��л���bfs��dfs����
 *
 * ע�����visited���飬��ֻ�Ǽ򵥵�bool������Ǽ򵥵�bool�����ǻᳬʱ
 * visited����������ѡ�0��1��2
 * 0����δ��������1���������У�2�����������
 * ֮���Զ����2����Ϊ��������dfsʱ���Ǵ�ÿ���㶼��һ��dfs����Ϊ�����ж��Ƿ��л����о��У�����ͳ�ƶ��ٸ�����
 * visitedΪ2�������������Ѿ��������ˣ����֮ǰ������ʱ���л����ٴ�����ѣ��ѳ�����������л��ظ������ˣ����û�����ٴν������
 * �������ѽ����Ȼû���������������ظ�����ģ���������ò���ֵ������������û�з��ʣ��ᵼ��ʱ�临�Ӷ�Ϊƽ�����Ӷ�
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

