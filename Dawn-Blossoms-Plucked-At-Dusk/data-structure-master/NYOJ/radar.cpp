#include<iostream>
#include <algorithm>
#include<math.h>

using namespace std;
struct qujian {
    double start;
    double end;
};

bool cmp(struct qujian a, struct qujian b) {
    return a.end < b.end;
}

struct qujian a[1000];

int main() {
    int sum = 0;
    int d, n;
    double x, y;
    while (1) {

        cin >> n >> d;
        if (n == 0 && d == 0) break;
        sum++;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            if (d < y) {
                cout << "-1" << endl;
                continue;
            }
            double temp = sqrt(d * d - y * y);
            a[i].start = x - temp;
            a[i].end = x + temp;
        }
        sort(a, a + n, cmp);

        int count = 1;
        double endd = a[0].end;
        for (int i = 1; i < n; i++) {
            if (a[i].start > endd) {
                count++;
                endd = a[i].end;
            }
        }
        cout << "Case " << sum << ": " << count << endl;

    }
}
/*找点的变式，注意数据类型*/
