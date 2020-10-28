/**
 * 给你两个时间，算出相减的值
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

int main() {
    vector<int> t1(3, -1);
    vector<int> t2(3, -1);
    scanf("%d:%d:%d", &t1[0], &t1[1], &t1[2]);
    scanf("%d:%d:%d", &t2[0], &t2[1], &t2[2]);
    vector<int> res;
    int index1 = 2, index2 = 2;
    while (index1 >= 0 && index2 >= 0) {
        int current;
        if (t1[index1] >= t2[index2]) {
            current = t1[index1] - t2[index2];
        } else {
            int start = index1 - 1;
            while (t1[start] == 0) {
                t1[start] = 59;
                --start;
            }

            t1[start] -= 1;
            current = 60 + t1[index1] - t2[index2];
        }

        res.push_back(current);
        --index1;
        --index2;
    }

    printf("%02d:%02d:%02d", res[2], res[1], res[0]);

}