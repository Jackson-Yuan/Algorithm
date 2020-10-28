#include<stdio.h>

int a[100];

int partition(int *a, int left, int right);

void quicksort(int *a, int left, int right) {
    if (left < right) {
        int j = partition(a, left, right);
        quicksort(a, left, j - 1);
        quicksort(a, j + 1, right);
    }
}

int partition(int *a, int left, int right) {
    int i = left + 1;
    int j = right;
    int cmp = a[left];
    while (true) {
        while (cmp >= a[i]) {
            i++;
            if (i == right) break;
        }

        while (cmp <= a[j]) {
            j--;
            if (j == right) break;
        }

        if (i >= j) break;
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    int temp = a[left];
    a[left] = a[j];
    a[j] = temp;
    return j;
}

int main() {
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, 9);
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
}
