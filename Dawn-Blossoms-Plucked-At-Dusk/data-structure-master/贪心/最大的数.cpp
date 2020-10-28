#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
int a[10000];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        if (a[0] == 1) {
            a[1]++;
            a[0] = 0;
        }
        if (a[n - 1] == 1) {
            a[n - 2]++;
            a[n - 1] = 0;
        }
        for (int i = 1; i < n; i++) {
            if (a[i] == 0) continue;
            if (a[i] == 1) {
                int left = i - 1;
                int right = i + 1;
                while (a[left] == 0) left--;
                while (a[right] == 0) right++;
                if (a[left] == 2) a[left]++;
                else if (a[left] <= a[right]) a[left]++;
                else a[right]++;
                a[i] = 0;
            }
        }
        int sum = 1;
        for (int i = 0; i < n; i++) {
            if (a[i]) sum = (sum * a[i]) % 10086;
        }
        printf("%d\n", sum);
    }
}
/*�������˼·���ҵ�1 ��������������ӻ������Ҽ� (��ϸ��������ô������ ����1 �������϶���ȫ��������Ĵ�)�����ѱ�Ϊ��0(��Ŀ����Ҫ�����밡 ����ô���� )
�ؼ�һ������ ��2�������Ҫ���Ƚ�� �������� �� a < b �� (a+1)b > a(b+1) ���� �ҵ�left��right ʱ ���ȼ���С�� ����2 ȴ������  ��2С�� ֻ��1  �����ܼӵ�1��
��Ϊ ���⴦��ľ���1 �������������� ��������1�ļӷ� ��������İ�1��������һ��1���ڰ�1���2(�˷�������һ��1�ļӵĻ���)  �����ֱ�Ӹ�2 ����3 ����һ��1�ټӸ�����һ��ֵ ��ʹֵ����
���� �ж�����һ����С�ڵ��ڣ�����ǰ�� 1 2 1 3 1 4 ������ a < b �� (a+1)b > a(b+1) ���翪ʼʱ �� 3 1 3 1 4 ���û�еȺ������ڶ���3 ��� 3 4 1 4 ���� 3 4 5
����еȺ� ����� 4 3 1 4 ���4 4 4 (�Ǹ����� �Ա�������� ���ȼ���ߵ� �뵽�������Ҳ�Ƿ�) 
*/
