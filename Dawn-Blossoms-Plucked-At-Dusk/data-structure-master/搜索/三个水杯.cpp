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
bool visited[100][100][100];//水杯状态标记 
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
                k = (i + j) % 3;//神来之笔
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
此题为bfs  不能使用dfs 理由在于此题水杯倒水，不是非要按顺序到 比如a倒向b b倒向c 或 a倒向c c倒向b这种情况a可以倒向b后 又倒向c
所以将三个水杯的状态利用bfs全部推出 ，再从这些状态继续推，直到寻找到结果(或许可以利用dfs，日后再说)

*/
