/*#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct exper{
	int index;
	long long value;
	int scien;
};
struct exper a[200000];
bool cmp(struct exper a, struct exper b){
	if(a.scien == b.scien) return a.index < b.index;
	else return a.value < b.value;
}
int main(){
	int n;
	scanf("%d",&n);
	int sum = 0;
	for(int i = 0 ; i < n ; i++){
		int num;
		long long first,x,y,m;
		scanf("%d %lld %lld %lld %lld", &num, &first, &x, &y, &m);
		for(int j = 0 ; j < num ; j++){
			a[sum].index = j + 1;
			a[sum].value = first;
			a[sum].scien = i + 1;
			sum++;
			first = (first * x + y) % m;
		}
	}
	
	sort(a, a+sum, cmp);
	int count = 0;
	long long compare = a[0].value;
	for(int i = 0 ; i < sum ; i++){
		if(a[i].value < compare){
			count++;
		}
		compare = a[i].value;
	}
	printf("%d\n",count);
	for(int i = 0 ; i < sum ; i++){
		printf("%lld %d\n",a[i].value,a[i].scien);
	}
}*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct sc {
    int cnt, count;
    long long num[5001];
} p[5010];

struct ms {
    int id;
    long long num;
} ans[200000], t[200000];

int sta, end;

void merge(int x, int y) {
    int mid = (x + y) >> 1, i = x, j = mid + 1, k = x;
    while (i != mid + 1 && j != y + 1) {
        if (ans[i].num > ans[j].num) {
            t[k].id = ans[j].id;
            t[k++].num = ans[j++].num;
        } else {
            t[k].id = ans[i].id;
            t[k++].num = ans[i++].num;
        }
    }
    while (i <= mid) {
        t[k].id = ans[i].id;
        t[k++].num = ans[i++].num;
    }
    while (j <= y) {
        t[k].id = ans[j].id;
        t[k++].num = ans[j++].num;
    }
    for (i = x; i <= y; ++i) {
        ans[i].id = t[i].id;
        ans[i].num = t[i].num;
    }

}

void mergesort(int x, int y) {
    if (x < y) {
        int mid = (x + y) >> 1;
        mergesort(x, mid);
        mergesort(mid + 1, y);
        merge(x, y);
    }
}

int main() {
    int n, i, j, k, l = 0, m, sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        long long t1, t2, t3, t4;
        k = 0;
        scanf("%d %lld %lld %lld %lld", &m, &t1, &t2, &t3, &t4);
        l += m;
        p[i].cnt = m;
        p[i].count = 1;
        p[i].num[0] = -1;
        p[i].num[1] = t1;
        for (j = 2; j <= m; ++j) {
            p[i].num[j] = (p[i].num[j - 1] * t2 + t3) % t4;
            if (p[i].num[j] < p[i].num[j - 1])
                k++;

        }
        if (k > sum) sum = k;
    }
    printf("%d\n", sum);
    if (l <= 200000) {
        sta = 0;
        end = 0;
        while (end < l) {
            for (i = 0; i < n; ++i) {
                for (j = p[i].count; j <= p[i].cnt; ++j) {
                    if (j != p[i].count && p[i].num[j] < p[i].num[j - 1]) {
                        p[i].count = j;
                        break;

                    }
                    ans[end].id = i;
                    ans[end++].num = p[i].num[j];

                }
                if (j > p[i].cnt)//all ascending
                    p[i].count = j;

            }
            mergesort(sta, end - 1);
            sta = end;

        }
        for (i = 0; i < l; ++i) printf("%lld %d\n", ans[i].num, ans[i].id + 1);

    }
    return 0;
}
/*
此题的难点在于如何组织好每个科学家各个问题的顺序 因为此题有个狗屎的设定 每个科学家的问题顺序是固定的 不能随意更改
但中间可以穿插其他科学家的问题 虽然这个设定很bitch 但也简化了求解的过程 因为每个科学家的问题顺序固定 导致了他们坏点个数的固定
所以这个题目 最少的坏点个数为所有科学家中坏点个数最多的 可能会感到诧异 求最少 你整个最多的结果不是扯淡嘛 但是别忘了 有好几个科学家
多个问题 如果插入的顺序不当 会单个最多的还要多 我们只要找到单个最多的 然后在以单个最多的为基准 合理插入其他科学家的问题 便会迎刃而解
如何使得插入合理 ？
如上图代码所示 先用一个结构体存储每个科学家的问题数， 及count变量用于组织顺序时关键因素(暂时无法解释 只能意会)
再用一个结构体存储实验耗能值和所属科学家id (用于排序)
先将数据 输入 
再开始将数据整理至要排序的结构体数组
如何整理 大体上遍历每一个科学家的每一个问题 存储至结构体数组
但注意 若当前点是坏点 则暂不进入数组 直接跳出当前循环 开始下一个科学家的问题遍历 上述情况也成立
一轮循环完后 开始排序(为什么要这样做 因为 坏点不进入数组排序的话 可以保证 每个科学家自身问题的顺序的固定性 因为坏点就是 前一个大于后一个)
由于每个科学家数组的count第一次大循环后记录的是坏点的位置 从坏点的位置继续进入数组 若再次遇到坏点 依然如上 但排序的时候 是从上一个循环排序的结束地方的下一个开始排(每次循环的排序前后不搭嘎 不然直接乱掉
这也是此题的关键所在)

此题 此刻的我基本就看看 叼 
*/
