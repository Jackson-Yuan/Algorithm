#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;
struct data {
    int state[3];
    int step;
};

int cup[3];
int target[3];
bool visited[100][100][100];//ˮ��״̬��� 
bool isTarget(data node) {
    for (int i = 0; i < 3; i++) {
        if (node.state[i] != target[i]) return false;
    }
    return true;
}

void classifyWater(int source, int destination, data &node) {
    int differenceWater = cup[destination] - node.state[destination];
    if (node.state[source] >= differenceWater) {
        node.state[destination] += differenceWater;
        node.state[source] -= differenceWater;
    } else {
        node.state[destination] += node.state[source];
        node.state[source] = 0;
    }
}

int bfs() {
    int i, j, k;
    data node;
    queue<data> a;

    memset(visited, false, sizeof(visited));
    node.state[0] = cup[0];
    node.state[1] = node.state[2] = 0;
    node.step = 0;
    a.push(node);
    visited[node.state[0]][0][0] = true;

    while (!a.empty()) {
        data temp = a.front();
        a.pop();
        if (isTarget(temp)) {
            return temp.step;
        }

        for (i = 0; i < 3; i++) {
            for (j = 1; j < 3; j++) {
                k = (i + j) % 3;//����֮��
                if (temp.state[i] != 0 && temp.state[k] < cup[k]) {
                    data newTemp = temp;
                    classifyWater(i, k, newTemp);
                    newTemp.step = temp.step + 1;
                    if (visited[newTemp.state[0]][newTemp.state[1]][newTemp.state[2]] == false) {
                        visited[newTemp.state[0]][newTemp.state[1]][newTemp.state[2]] = true;
                        a.push(newTemp);
                    }
                }

            }
        }
    }
    return -1;

}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        for (int i = 0; i < 3; i++) {
            scanf("%d", &cup[i]);
        }
        for (int j = 0; j < 3; j++) {
            scanf("%d", &target[j]);
        }
        printf("%d\n", bfs());
    }
}
/*
����Ϊbfs  ����ʹ��dfs �������ڴ���ˮ����ˮ�����Ƿ�Ҫ��˳�� ����a����b b����c �� a����c c����b�������a���Ե���b�� �ֵ���c
���Խ�����ˮ����״̬����bfsȫ���Ƴ� ���ٴ���Щ״̬�����ƣ�ֱ��Ѱ�ҵ����(�����������dfs���պ���˵)

*/
