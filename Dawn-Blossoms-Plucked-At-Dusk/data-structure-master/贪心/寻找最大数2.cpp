#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
char s[30];
int n;
int a[30];

int transform() {
    int count = strlen(s);
    for (int i = 0; i < count; i++) {
        a[i] = s[i] - '0';
    }
    return count;
}

int findMax(int *a, int start, int end) {
    int max = a[start];
    int index = start;
    for (int i = start; i <= end; i++) {
        if (a[i] > max) {
            max = a[i];
            index = i;
        }
    }
    return index;

}

void move(int *a, int start, int end) {
    for (int i = end; i > start; i--) {
        a[i] = a[i - 1];
    }
}

int main() {
    while (scanf("%s %d", s, &n) != EOF) {
        getchar();
        int sum = transform();
        int start = 0;
        int end = start + n;
        if (end > sum - 1) end = sum - 1;
        while (n != 0) {
            if (start > end) break;
            int target = findMax(a, start, end);
            int temp = a[target];
            move(a, start, target);
            a[start] = temp;
            n = n - (target - start);
            start++;
            end = start + n;
            if (end > sum - 1) end = sum - 1;
        }
        for (int i = 0; i < sum; i++) {
            printf("%d", a[i]);
        }
        printf("\n");
    }
}
/*
此题就是利用贪心 每次根据当前交换次数 算出最远的剧情，寻找这一区间内最大值的索引target 放到start位置 同时注意 原start位置的数据不是与target交换，而是放到他的后面(就是这个问题没有意识到) 
还有就是寻找最大值的区间要注意end的值不能超过当前数组的最大索引值 还有就是跳出循环的条件 也是不全是n！=0 如果交换次数过多 那么就是start >end为跳出循环的条件 
*/
