/**
 * 由于徐老汉没钱，收费员就将他的羊拿走一半，看到老汉泪水涟涟，犹豫了一下，又还给老汉一只。巧合的是，后面每过一个收费站，
 * 都是拿走当时羊的一半，然后退还一只，等到老汉到达市场，就只剩下3只羊了。
 * 你,当代有良知的青年，能帮忙算一下老汉最初有多少只羊吗？
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
    cin >> n;
    while (n--) {
        int count;
        cin >> count;
        int sum = 3;
        for (int i = count; i >= 1; --i) {
            sum = (sum - 1) * 2;
        }

        cout << sum << endl;
    }

    return 0;
}