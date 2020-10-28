/**
 * 猜数字的游戏，不太难的。题目：随即产生一个3位的正整数，让你进行猜数字，如果猜小了，输出：“猜小了，请继续”。如果猜大了，
 * 输出：“猜大了，请继续”。如果猜对了。输出：“恭喜你，猜对了”。不过最多只能猜10次，如果猜了10次还没有猜对，就退出程序，输出：“Bye Bye”
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int target = rand() % 1000;
    bool token = false;
    for (int i = 0; i < 10; ++i) {
        int tmp;
        cin >> tmp;
        if (tmp == target) {
            cout << "恭喜你，猜对了" << endl;
            token = true;
            break;
        } else if (tmp > target) {
            cout << "猜大了，请继续" << endl;
        } else {
            cout << "猜小了，请继续" << endl;
        }
    }

    if (!token) cout << "Bye Bye" << endl;
    return 0;
}
/**
 * rand函数应用
 * */