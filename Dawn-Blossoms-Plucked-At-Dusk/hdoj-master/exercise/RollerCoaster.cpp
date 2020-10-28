/**
 * RPG girls今天和大家一起去游乐场玩，终于可以坐上梦寐以求的过山车了。
 * 可是，过山车的每一排只有两个座位，而且还有条不成文的规矩，就是每个女生必须找个个男生做partner和她同坐。但是，每个女孩都有各自的想法，
 * 举个例子把，Rabbit只愿意和XHD或PQK做partner，Grass只愿意和linle或LL做partner，PrincessSnow愿意和水域浪子或伪酷儿做partner。考虑到经费问题，
 * boss刘决定只让找到partner的人去坐过山车，其他的人，嘿嘿，就站在下面看着吧。聪明的Acmer，你可以帮忙算算最多有多少对组合可以坐上过山车吗？
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
int k, m, n;
vector<vector<int>> link;
vector<bool> visited;
vector<int> boyToGirl;

bool find(int index) {
    for (int i = 0; i < link[index].size(); ++i) {
        int boyId = link[index][i] - 1;
        if (!visited[boyId]) {
            visited[boyId] = true;
            if (boyToGirl[boyId] == -1 || find(boyToGirl[boyId])) {
                boyToGirl[boyId] = index;
                return true;
            }
        }
    }

    return false;
}

int main() {
    while (true) {
        cin >> k;
        if (k == 0) break;
        cin >> m >> n;
        link = vector<vector<int>>(m, vector<int>());
        boyToGirl = vector<int>(n, -1);
        int a, b;
        while (k--) {
            cin >> a >> b;
            link[a - 1].push_back(b);
        }

        int count = 0;
        for (int i = 0; i < m; ++i) {
            visited = vector<bool>(n, false);
            if (find(i)) ++count;
        }

        cout << count << endl;
    }

    return 0;
}
/**
 * 匈牙利算法，解决类似题目描述的匹配问题
 * 核心思想就是能配对，先配;若不能，找到他先前配对好的，看是否可以让其配对其他的，以此类推，是个递归
 */