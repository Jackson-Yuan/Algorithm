/**
n个人去r个水龙头打水，装水的时间为t1到tn，应如何安排他们的顺序 使得每个人实际打水时间总和最小 
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int n, r;
int perTime[500];
int wait[500];

int main() {
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        cin >> perTime[i];
    }

    for (int i = 0; i < r; i++) {
        wait[i] = 0;
    }

    sort(perTime, perTime + n);
    for (int i = 0; i < n; i++) {
        int temp = perTime[i];
        int index = i % r;
        perTime[i] += wait[index];
        wait[index] += temp;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += perTime[i];
    }

    cout << sum << endl;
}
/**
此题利用贪心
因为要使实际打水时间最小 实际打水时间为接水时间 等待时间之和 接水时间固定无法改变，所以尽可能使等待时间最小
所以应该使接水时间最少的优先去接 可由 最小时间 = 接水时间之和 + 等待时间(由接水时间决定) 
所以r个水龙头 要排前r接水时间小的人去排 接着下一批r个 至于每一批的每个人与前一批的每个人是没有必然对应关系 但写程序的时候只能强行加上一种对应关系 不然没法算啊  
*/

