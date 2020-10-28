#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
char s[30];
int n;
int a[30];

int transform() {
    int count = strlen(s);
    for (int i = 0; i < count; i++) {
        a[i] = s[i] - '0';
    }
    return count;
}

int findMax(int *a, int start, int end) {
    int max = a[start];
    int index = start;
    for (int i = start; i <= end; i++) {
        if (a[i] > max) {
            max = a[i];
            index = i;
        }
    }
    return index;

}

void move(int *a, int start, int end) {
    for (int i = end; i > start; i--) {
        a[i] = a[i - 1];
    }
}

int main() {
    while (scanf("%s %d", s, &n) != EOF) {
        getchar();
        int sum = transform();
        int start = 0;
        int end = start + n;
        if (end > sum - 1) end = sum - 1;
        while (n != 0) {
            if (start > end) break;
            int target = findMax(a, start, end);
            int temp = a[target];
            move(a, start, target);
            a[start] = temp;
            n = n - (target - start);
            start++;
            end = start + n;
            if (end > sum - 1) end = sum - 1;
        }
        for (int i = 0; i < sum; i++) {
            printf("%d", a[i]);
        }
        printf("\n");
    }
}
/*
�����������̰�� ÿ�θ��ݵ�ǰ�������� �����Զ�ľ��飬Ѱ����һ���������ֵ������target �ŵ�startλ�� ͬʱע�� ԭstartλ�õ����ݲ�����target���������Ƿŵ����ĺ���(�����������û����ʶ��) 
���о���Ѱ�����ֵ������Ҫע��end��ֵ���ܳ�����ǰ������������ֵ ���о�������ѭ�������� Ҳ�ǲ�ȫ��n��=0 ��������������� ��ô����start >endΪ����ѭ�������� 
*/
