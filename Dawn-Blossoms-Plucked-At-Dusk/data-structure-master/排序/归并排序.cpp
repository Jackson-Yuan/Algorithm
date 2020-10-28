#include<stdio.h>
#include<iostream>

using namespace std;
int a[100];
int temp[100];

void merge(int *arr, int left, int mid, int right, int *temp);

void sort(int *arr, int left, int right, int *temp) {
    if (left < right) {
        int mid = (left + right) / 2;
        //printf("进入%d %d %d\n",left, mid, right);
        //printf("%d %d\n",left, mid);
        sort(arr, left, mid, temp);//sort left
        //printf("%d %d\n",mid+1, right);
        sort(arr, mid + 1, right, temp);//sort right
        //printf("归并%d %d %d\n",left, mid, right);
        merge(arr, left, mid, right, temp);//sort
    }
}

void merge(int *arr, int left, int mid, int right, int *temp) {
    int i = left;//left sequence index
    int j = mid + 1;//right sequence index
    int t = 0;//temp sequence index

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[t] = arr[i];
            t++;
            i++;
        } else {
            temp[t] = arr[j];
            t++;
            j++;
        }
    }
    //if left sequence is leftover
    while (i <= mid) {
        temp[t] = arr[i];
        t++;
        i++;
    }
    //if right sequence is leftover
    while (j <= right) {
        temp[t] = arr[j];
        t++;
        j++;
    }

    t = 0;
    while (left <= right) {
        arr[left] = temp[t];
        left++;
        t++;
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, 0, 9, temp);
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", temp[i]);
    }
}
/*
归并排序 其实运用的是分治思想 将数组分为几个小数组排序 将小数组排序 再将小数组拼成有序的数组
 最后使整个数组有序 整个算法的时间复杂度为线性对数级 
*/
