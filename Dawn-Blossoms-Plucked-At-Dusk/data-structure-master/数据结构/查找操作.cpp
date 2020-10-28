#include<iostream>
#include<algorithm>

using namespace std;
struct list {
    int a[100];
    int length;
};

/*顺序查找*/
int findKey(struct list aa, int key) {
    int i;
    aa.a[0] = key;/*哨兵位*/
    for (i = aa.length; aa.a[i] != key; i--);
    return i;
}

/*二分查找 */
int binarySearch(struct list aa, int key) {
    int left = 1;
    int right = aa.length - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (key < aa.a[mid]) right = mid - 1;
        else if (key > aa.a[mid]) left = mid + 1;
        else return mid;
    }
    return 0;
}

int main() {
    struct list b;
    b.length = 10;
    for (int i = 1; i <= 10; i++) {
        b.a[i] = i;
    }
    cout << findKey(b, 5) << " " << binarySearch(b, 5);
}
