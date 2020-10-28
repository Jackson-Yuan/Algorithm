#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>

using namespace std;
struct coordinate {
    double left;
    double right;
};

bool cmp(struct coordinate a, struct coordinate b) {
    return a.left < b.left;
}

struct coordinate a[100000];

int main() {
    int N;
    cin >> N;
    while (N--) {
        int n;
        double w, h;
        scanf("%d%lf%lf", &n, &w, &h);
        for (int i = 0; i < n; i++) {
            double x, r;
            scanf("%lf%lf", &x, &r);
            double flag;
            if (2 * r > h) {
                flag = sqrt(r * r - h * h / 4);
            } else flag = 0;
            a[i].left = x - flag;
            a[i].right = x + flag;
        }
        sort(a, a + n, cmp);
        int count = 0;
        double temp = 0;
        for (int i = 0; i < n; i++) {
            //左端点达不到0或最后一个端点到达不了w
            /*	if((i==0 && a[i].left > 0) || (i==n-1 && a[i].right< w)){
                    count = 0;
                    break;
                }*/
            if (a[i].left <= temp) {
                double start = a[i].right;
                while (a[i].left <= temp) {
                    start = max(a[i].right, start);
                    i++;
                    if (i == n) break;
                }
                temp = start;
                i--;
                count++;

            }/*else{
		    	count=0;
		    	break;
		    }
		    
		    if(a[i].right>=w) break;*/

            if (temp >= w) break;
        }
        if (temp >= w)
            cout << count << endl;
        else cout << 0 << endl;
    }
}
/*
此题第一个关键点为 求出喷水装置的有效面积，不是整个圆的面积 而是圆与草坪相交的矩形的面积，进而转换为区间，与【0,w】比是否能完全覆盖
 在检查是否能完全覆盖时，应注意 下一个点的左端点一定要<= 上一个点的右端点，并且只有当下一个点的右端点大于 上一个点的右端点时才能计数
 至于下一个点怎么取，不是按照按左端点的大小的索引来取 ，而是谁在小于上一个端点的右端点的情况下，比较谁的右端点值大来选取，上图注释掉的部分
 是错误代码  if(temp >= w) break;新增  注释代码报可能有特殊情况没有考虑 至于怎么样 以后再说 

*/
