/**
 * 优先队列(其实就是堆)
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * 下沉
 * */
void headAdjust(int *a, int k, int len) {
    int tmp = a[k];
    for (int i = 2 * k; i <= len; i *= 2) {
        if (i < len && a[i] > a[i + 1]) ++i;
        if (tmp < a[i]) break;
        else {
            a[k] = a[i];
            k = i;
        }
    }
    a[k] = tmp;
}

/**
 * 尾部插入，上浮
 * */
void swim(int *a, int k) {
    while (k > 1 && a[k / 2] > a[k]) {
        int tmp = a[k / 2];
        a[k / 2] = a[k];
        a[k] = tmp;
        k /= 2;
    }
}

/**
 * 构造优先队列
 * */
void insert(int *a, int value, int &len) {
    ++len;
    a[len] = value;
    swim(a, len);
}

/**
 * 删除最小值，重新构造最小堆
 * */
int deleteMin(int *a, int &len) {
    int minValue = a[1];
    a[1] = a[len];
    --len;
    headAdjust(a, 1, len);
    return minValue;

}


int main() {
    int a[100];
    int n;
    cin >> n;

    int len = 0;
    for (int j = 0; j < n; ++j) {
        int tmp;
        cin >> tmp;
        insert(a, tmp, len);
    }

    int res = 0;
    while (len > 1) {
        int tmpA = deleteMin(a, len);
        int tmpB = deleteMin(a, len);
        res += tmpA + tmpB;
        insert(a, tmpA + tmpB, len);
    }

    cout << res << endl;
}
/**
 * 自制优先队列，完成霍夫曼树求wpl
 * */