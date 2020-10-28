#include<stdio.h>

void swap(int *a, int *b) {
    int temp;
    if ((*a) < (*b)) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

void swapadd(int *a, int *b, int *c, int *d) {
    swap(a, b);
    swap(a, c);
    swap(a, d);
    swap(b, c);
    swap(b, d);
    swap(c, d);
}

int main() {
    int n, a, b, c, d, i, j, count, t;
    scanf("%d", &count);

    while (count--) {
        t = 0;
        scanf("%d", &n);
        /*if(n!=6174)
        {
            t++;
        }
        else
        {
            t++;
            printf("%d",t);
            return 0;
        }
        a=n/1000;
        b=(n/100)%10;
        c=(n/10)%10;
        d=n%10;
        swapadd(&a,&b,&c,&d);
        i=a*1000+b*100+c*10+d;//大
        swapadd(&d,&c,&b,&a);
        j=a*1000+b*100+c*10+d;//小 */
        while (n != 6174) {
            t++;

            a = n / 1000;
            b = (n / 100) % 10;
            c = (n / 10) % 10;
            d = n % 10;
            swapadd(&a, &b, &c, &d);
            i = a * 1000 + b * 100 + c * 10 + d;//大
            swapadd(&d, &c, &b, &a);
            j = a * 1000 + b * 100 + c * 10 + d;//小
            n = i - j;
        }
        t++;
        printf("%d\n", t);
    }

}
