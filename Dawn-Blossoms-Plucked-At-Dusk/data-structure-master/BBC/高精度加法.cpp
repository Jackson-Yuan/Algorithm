#include<stdio.h>
#include<string.h>

int a[100];
int b[100];
char aa[101];
char bb[101];

int main() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    /*�����ַ�����ȡ��������*/
    scanf("%s", aa);
    scanf("%s", bb);
    int index = strlen(aa);
    int suma, sumb;
    suma = index;
    for (int i = 0; i < index; i++) {
        a[index - i - 1] = aa[i] - '0';
    }
    index = strlen(bb);
    sumb = index;
    for (int i = 0; i < index; i++) {
        b[index - i - 1] = bb[i] - '0';
    }

    if (suma > sumb) index = suma;
    else index = sumb;

    /*��� ��λ���ж�*/
    for (int i = 0; i < index; i++) {
        int temp = a[i] + b[i];
        if (temp >= 10) {
            a[i] = temp % 10;
            temp /= 10;
            a[i + 1] += temp;
        } else a[i] = temp;
    }

    /*a[i]��ĩλ������Ȼ����10 ���Ի�Ҫ������*/
    while (a[index] >= 10) {
        int temp = a[index];
        a[index] = temp % 10;
        a[index + 1] += temp / 10;
        index++;
    }

    for (int i = index; i >= 0; i--) {
        if (a[i] == 0 && i == index) continue;
        printf("%d", a[i]);
    }
    printf("\n");

}
/*�����ע��*/ 
