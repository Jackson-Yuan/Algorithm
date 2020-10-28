#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
char b[101];
int a[100];
int c[100];

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    while (N--) {
        int n, m;
        scanf("%s %d", b, &n);
        int index = strlen(b);
        for (int i = 0; i < index; i++) {
            a[i] = b[i] - '0';
        }
        m = index - n;
        int temp = 0;
        int index2 = 0;
        for (int i = m - 1; i >= 0; i--) {
            int max = a[temp];
            for (int j = temp; j < index - i; j++) {
                if (a[j] > max) {
                    max = a[j];
                    temp = j;
                }
            }
            c[index2] = max;
            index2++;
            temp++;
        }
        for (int i = 0; i < index2; i++) {
            printf("%d", c[i]);
        }
        printf("\n");
    }
}/*
本题就是从若干数中找到删掉一些数，使得剩下的数最大
首先确定目标是几位数，在把每一位数的范围确定，找出每一位数范围中
最大值即可 


*/ 
