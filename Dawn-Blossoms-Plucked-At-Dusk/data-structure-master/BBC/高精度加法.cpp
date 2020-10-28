#include<stdio.h>
#include<string.h>

int a[100];
int b[100];
char aa[101];
char bb[101];

int main() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    /*利用字符串抽取两个加数*/
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

    /*相加 进位的判断*/
    for (int i = 0; i < index; i++) {
        int temp = a[i] + b[i];
        if (temp >= 10) {
            a[i] = temp % 10;
            temp /= 10;
            a[i + 1] += temp;
        } else a[i] = temp;
    }

    /*a[i]的末位可能依然大于10 所以还要再讨论*/
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
/*详情见注释*/ 
