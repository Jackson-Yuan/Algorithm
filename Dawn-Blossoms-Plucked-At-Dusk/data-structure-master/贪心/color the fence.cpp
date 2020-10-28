#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
int a[9];
int n;

int findMin(int *a) {
    int min = 100001;
    int index = -1;
    for (int i = 0; i < 9; i++) {
        if (a[i] < min) {
            min = a[i];
            index = i;
        }
    }
    return min;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < 9; i++) {
            scanf("%d", &a[i]);
        }
        int min = findMin(a);
        if (min > n) {
            printf("-1\n");
            continue;
        }
        int count = n / min;
        while (count--) {
            for (int i = 8; i >= 0; i--) {
                if (n >= a[i] && (n - a[i]) / min == count) {
                    printf("%d", i + 1);
                    n -= a[i];
                    break;
                }
            }
        }
        printf("\n");
    }

}
/*��������ҵ��ķѵ���Сֵ ��������д��λ�� ���Ǵ�ǰ�� Ȼ���ڴ�ǰ���� ����ʹÿλ���������ܴ�(���ûע�� ��Ϊ��ֻҪ�ҵ���Сֵ���� ���ǲ���)
������������ʱ �ַ�ע��һ�� �ж���ʱ ������������Ĳ�ֵ ������Сֵ�ܷ� ����ʣ���λ�� ���ܾͲ���
�Ͼ�λ���� �϶��� 
*/ 
