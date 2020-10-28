#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;
struct node {
    double leftx;
    double lefty;
    double rightx;
    double righty;
};

bool cmp(struct node a, struct node b) {
    return a.leftx < b.leftx;
}

int main() {
    struct node a[2];
    for (int i = 0; i < 2; i++) {
        scanf("%lf%lf%lf%lf", &a[i].leftx, &a[i].lefty, &a[i].rightx, &a[i].righty);
    }
    sort(a, a + 2, cmp);
    if (a[1].leftx < a[0].rightx && (a[1].lefty < a[0].righty && )) {
        double result = (a[0].rightx - a[1].leftx) * (a[0].righty - a[1].lefty);
        printf("%.2f\n", result);
    } else {
        printf("0.00\n");
    }
    return 0;
}
/*
此题 少考虑了一种情况 导致思路出错 没有考虑全面 
主要是相交的情况 一个是靠右的在上方
一个是靠左的在上方 两者不同的相交情况 使得我这个方法出错
所以要先判断两者谁高谁低，
再利用主对角线与副对角线进行一系列判断
底下的代码较为简单 可作为参考 
*/
/*#include<stdio.h>

#define max(x,y) ((x)>(y)?(x):(y))

#define min(x,y) ((x)<(y)?(x):(y))

int main(){

    double x1,y1,x2,y2;    //矩形1

    double x3,y3,x4,y4;    //矩形2

    double m1,n1;        //交集左上角坐标.

    double m2,n2;        //交集右下角坐标.

    scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);

    scanf("%lf%lf%lf%lf",&x3,&y3,&x4,&y4);

    m1 = max(min(x1,x2),min(x3,x4));

    n1 = max(min(y1,y2),min(y3,y4));

    m2 = min(max(x1,x2),max(x3,x4));

    n2 = min(max(y1,y2),max(y3,y4));

    if(m2>m1 && n2>n1)

        printf("%.2f\n",(m2 - m1)*(n2 - n1));

    else

        printf("0.00\n");

    return 0;

}*/
	
