/**
问题描述
很久以前，T王国空前繁荣。为了更好地管理国家，王国修建了大量的快速路，用于连接首都和王国内的各大城市。
为节省经费，T国的大臣们经过思考，制定了一套优秀的修建方案，使得任何一个大城市都能从首都直接或者通过其他大城市间接到达。同时，如果不重复经过大城市，从首都到达每个大城市的方案都是唯一的。
J是T国重要大臣，他巡查于各大城市之间，体察民情。所以，从一个城市马不停蹄地到另一个城市成了J最常做的事情。他有一个钱袋，用于存放往来城市间的路费。
聪明的J发现，如果不在某个城市停下来修整，在连续行进过程中，他所花的路费与他已走过的距离有关，在走第x千米到第x+1千米这一千米中（x是整数），他花费的路费是x+10这么多。也就是说走1千米花费11，走2千米要花费23。
J大臣想知道：他从某一个城市出发，中间不休息，到达另一个城市，所有可能花费的路费中最多是多少呢？
输入格式
输入的第一行包含一个整数n，表示包括首都在内的T王国的城市数
城市从1开始依次编号，1号城市为首都。
接下来n-1行，描述T国的高速路（T国的高速路一定是n-1条）
每行三个整数Pi, Qi, Di，表示城市Pi和城市Qi之间有一条高速路，长度为Di千米。
输出格式
输出一个整数，表示大臣J最多花费的路费是多少。
样例输入1
5
1 2 2
1 3 1
2 4 5
2 5 4
样例输出1
135 
输出格式
大臣J从城市4到城市5要花费135的路费。
*/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>

using namespace std;

int getSum(int start, int end) {
    int sum = 0;
    for (int i = start; i < end; i++) {
        sum += i + 10;
    }
    return sum;
}

struct node {
    int target;
    int cost;
};
vector<struct node> grap[10001];
int maxValue;
bool vis[10001];
int index;

void dfs(int location, int length, int start) {
    if (length > maxValue) {
        index = location;
        maxValue = length;
    }
    vis[location] = true;
    for (int i = 0; i < grap[location].size(); i++) {
        if (!vis[grap[location][i].target]) {
            dfs(grap[location][i].target, length + grap[location][i].cost, start + grap[location][i].cost);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        struct node tmp;
        tmp.target = b;
        tmp.cost = c;
        grap[a].push_back(tmp);
        tmp.target = a;
        grap[b].push_back(tmp);
    }

    memset(vis, 0, sizeof(vis));
    maxValue = -1;
    index = 0;
    dfs(1, 0, 0);
    memset(vis, 0, sizeof(vis));
    dfs(index, 0, 0);

    cout << ((11 + 10 + maxValue) * maxValue) / 2 << endl;
    return 0;
}
/**
求树的直径问题
树的直径 是一颗树中 从某点到某点的权值之和最大 具体方法为 先从某点p dfs到与此点距离最长的点q 然后点q到与其最长的点g qg则为树的直径
利用的性质为数中任意一点到其距离最远的点都在直径上 
*/
