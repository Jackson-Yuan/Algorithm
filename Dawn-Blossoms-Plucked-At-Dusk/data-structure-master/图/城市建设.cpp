/**
问题描述
　　栋栋居住在一个繁华的C市中，然而，这个城市的道路大都年久失修。市长准备重新修一些路以方便市民，于是找到了栋栋，希望栋栋能帮助他。

　　C市中有n个比较重要的地点，市长希望这些地点重点被考虑。现在可以修一些道路来连接其中的一些地点，每条道路可以连接其中的两个地点。另外由于C市有一条河从中穿过，也可以在其中的一些地点建设码头，所有建了码头的地点可以通过河道连接。

　　栋栋拿到了允许建设的道路的信息，包括每条可以建设的道路的花费，以及哪些地点可以建设码头和建设码头的花费。

　　市长希望栋栋给出一个方案，使得任意两个地点能只通过新修的路或者河道互达，同时花费尽量小。
输入格式
　　输入的第一行包含两个整数n, m，分别表示C市中重要地点的个数和可以建设的道路条数。所有地点从1到n依次编号。
　　接下来m行，每行三个整数a, b, c，表示可以建设一条从地点a到地点b的道路，花费为c。若c为正，表示建设是花钱的，如果c为负，则表示建设了道路后还可以赚钱（比如建设收费道路）。
　　接下来一行，包含n个整数w_1, w_2, …, w_n。如果w_i为正数，则表示在地点i建设码头的花费，如果w_i为-1，则表示地点i无法建设码头。
　　输入保证至少存在一个方法使得任意两个地点能只通过新修的路或者河道互达。
输出格式
　　输出一行，包含一个整数，表示使得所有地点通过新修道路或者码头连接的最小花费。如果满足条件的情况下还能赚钱，那么你应该输出一个负数。
样例输入
5 5
1 2 4
1 3 -1
2 3 3
2 4 5
4 5 10
-1 10 10 1 1
样例输出
9
样例说明
　　建设第2、3、4条道路，在地点4、5建设码头，总的花费为9。
数据规模和约定
　　对于20%的数据，1<=n<=10，1<=m<=20，0<=c<=20，w_i<=20；
　　对于50%的数据，1<=n<=100，1<=m<=1000，-50<=c<=50，w_i<=50；
　　对于70%的数据，1<=n<=1000；
　　对于100%的数据，1 <= n <= 10000，1 <= m <= 100000，-1000<=c<=1000，-1<=w_i<=1000，w_i≠0。
*/
#include<iostream>
#include<stdio.h>
#include<algorithm >

using namespace std;
int num[10001];

int find(int root) {
    int son = root;
    while (root != num[root]) {
        root = num[root];
    }

    while (son != num[son]) {
        int tmp = num[son];
        num[son] = root;
        son = tmp;
    }

    return root;
}

struct route {
    int x;
    int y;
    int cost;
};
struct route r[100000];

bool cmp(struct route a, struct route b) {
    return a.cost < b.cost;
}

int kruskal(int n, int m) {
    int ans = 0, edge = 0;
    for (int i = 0; i <= n; i++) {
        num[i] = i;
    }
    sort(r, r + m, cmp);
    for (int i = 0; i < m; i++) {
        int a = r[i].x;
        int b = r[i].y;
        int aa = find(a);
        int bb = find(b);
        if (aa != bb) {
            ans += r[i].cost;
            edge++;
            num[aa] = bb;

        } else if (r[i].cost < 0) ans += r[i].cost;

    }

    if (edge == n - 1) return ans;
    else return -1;
}

int main() {
    int n, m, len = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &r[i].x, &r[i].y, &r[i].cost);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp != -1) {
            r[m + cnt].x = 0;
            r[m + cnt].y = i;
            r[m + cnt].cost = tmp;
            cnt++;
        }
    }

    int ans = kruskal(n, m);
    if (ans != -1) {
        printf("%d\n", min(ans, kruskal(n + 1, m + cnt)));
    } else {
        printf("%d\n", kruskal(n + 1, m + cnt));
    }

    return 0;
}
/**
此题为最小生成树题目 
当然也有坑点
以为道路有可能盈利 所以盈利的道路 必须加上去 但不能算作连通的边 值得注意
第二 有码头的存在 可能会致使值变大 所以应该先检查是否能得出连通的值 若能
则 再把码头算进去 比大小 若不能 那就直接算带码头的


同时 处理码头的方式也很巧妙 利用虚设点0来解决 值得学习 
**/
