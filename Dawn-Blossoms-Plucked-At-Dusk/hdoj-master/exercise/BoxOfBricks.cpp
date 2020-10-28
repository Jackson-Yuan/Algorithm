/**
 * Little Bob likes playing with his box of bricks.
 * He puts the bricks one upon another and builds stacks of different height.
 * “Look, I've built a wall!”, he tells his older sister Alice. “
 * Nah, you should make all stacks the same height. Then you would have a real wall.”, she retorts. A
 * fter a little consideration, Bob sees that she is right.
 * So he sets out to rearrange the bricks, one by one, such that all stacks are the same height afterwards.
 * But since Bob is lazy he wants to do this with the minimum number of bricks moved. Can you help?
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
    bool isPrint = false;
    while (true) {
        cin >> n;
        if (n == 0) break;
        if (isPrint) cout << endl;
        vector<int> height(n, -1);
        int all = 0;
        for (int i = 0; i < height.size(); ++i) {
            cin >> height[i];
            all += height[i];
        }

        int average = all / height.size();

        int count = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (height[i] < average) {
                count += average - height[i];
            }
        }

        cout << count << endl;
        isPrint = true;
    }

    return 0;
}