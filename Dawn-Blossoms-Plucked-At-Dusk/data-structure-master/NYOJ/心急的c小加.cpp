#include<iostream>
#include<algorithm>

using namespace std;
struct wood {
    int length;
    int weight;
};

bool compare(struct wood a, struct wood b) {
    return a.length == b.length ? a.weight < b.weight : a.length < b.length;
}

struct wood a[1500];
int b[1500];

int main() {
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> a[i].length >> a[i].weight;
        }
        sort(a, a + m, compare);

        int k = 0, j;
        b[k] = a[0].weight;
        for (int i = 1; i < m; i++) {
            for (j = 0; j <= k; j++) {
                if (a[i].weight >= b[j]) {
                    b[j] = a[i].weight;
                    break;
                }
            }
            if (j > k) {
                k++;
                b[k] = a[i].weight;
            }
        }
        cout << k + 1 << endl;
    }
    return 0;
}
/*
������Ȼ̰��˼·������ʱע��˼·�����������򣬳���һ�������������򣬱���������������˺��߼�����һ������weight�ţ���������bug
���ѭ���У�Ҳ��ֵ��ע��İ�weight���������д��棬��Ϊ�����������źõģ����Ȳ��迼�ǣ��ѷ������¿�һ����λʱ���weight����������
ʹʣ�µ�ľ��һһ�Ƚ� 
*/
