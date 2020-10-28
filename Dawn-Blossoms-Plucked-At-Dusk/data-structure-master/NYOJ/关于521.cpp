#include<iostream>

using namespace std;

int main() {

    int data1[1000000] = {0};
    int data2[1000000] = {0};
    int s[6];
    int a, b, n = 0;
    for (int i = 125; i < 1000000; i++) {
        int a = 0, b = 0, c = 0;
        s[0] = i / 100000;
        s[1] = (i / 10000) % 10;
        s[2] = (i / 1000) % 10;
        s[3] = (i / 100) % 10;
        s[4] = (i / 10) % 10;
        s[5] = i % 10;

        for (int j = 0; j <= 3; j++) {
            if (s[j] == 5 && s[j + 1] == 2 && s[j + 2] == 1) {
                data2[i] = data2[i - 1] + 1;
                break;
            }
            if (j == 3) {
                data2[i] = data2[i - 1];
            }
        }
        for (int k = 0; k < 6; k++) {

            if (s[k] == 5) {
                a++;
                continue;
            }
            if (s[k] == 2) {
                b++;
                continue;
            }
            if (s[k] == 1) {
                c++;
                continue;
            }
        }
        if (a != 0 && b != 0 && c != 0) data1[i] = data1[i - 1] + 1;
        else data1[i] = data1[i - 1];
    }
    while (cin >> a >> b) {
        n++;
        cout << "Case " << n << ":" << data1[b] - data1[a - 1] << " " << data2[b] - data2[a - 1] << endl;
    }


}
