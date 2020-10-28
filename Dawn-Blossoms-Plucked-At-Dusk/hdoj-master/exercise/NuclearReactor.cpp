/**
 * 某核反应堆有两类事件发生：
 * 高能质点碰击核子时，质点被吸收，放出3个高能质点和1个低能质点；
 * 低能质点碰击核子时，质点被吸收，放出2个高能质点和1个低能质点。
 * 假定开始的时候（0微秒）只有一个高能质点射入核反应堆，每一微秒引起一个事件发生(对于一个事件，当前存在的所有质点都会撞击核子)，
 * 试确定n微秒时高能质点和低能质点的数目。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == -1) break;
        vector<long long> up;
        up.push_back(1);
        vector<long long> down;
        down.push_back(0);
        for (int i = 1; i <= n; ++i) {
            long long generateUp = 3 * up[i - 1] + 2 * down[i - 1];
            long long generateDown = 1 * up[i - 1] + 1 * down[i - 1];
            up.push_back(generateUp);
            down.push_back(generateDown);
        }

        cout << up[n] << ", " << down[n] << endl;
    }
    return 0;
}