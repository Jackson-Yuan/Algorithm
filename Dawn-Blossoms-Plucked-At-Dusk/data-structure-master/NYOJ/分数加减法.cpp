#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int maxdivisor(int a, int b) {
    int max = 0;
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    while (a) {
        int temp = b % a;
        b = a;
        max = a;
        a = temp;
    }
    return max;
}

int minmultiple(int a, int b) {
    int max = maxdivisor(a, b);
    int min = a * b / max;
    return min;
}

int main() {
    char a, b, o, c, d;
    while (scanf("%c/%c%c%c/%c", &a, &b, &o, &c, &d) != EOF) {
        getchar();
        int aint = a - '0';
        int bint = b - '0';
        int cint = c - '0';
        int dint = d - '0';
        if (bint == 0 || dint == 0) continue;
        int min = minmultiple(bint, dint);
        aint = aint * min / bint;
        cint = cint * min / dint;
        int sum;
        if (o == '+') {
            sum = aint + cint;
        } else {
            sum = aint - cint;
        }
        if (sum == 0) {
            printf("0\n");
            continue;
        }
        int tempsum = abs(sum);
        int max = maxdivisor(tempsum, min);
        int molecule = sum / max;
        int denominator = min / max;
        if (molecule % denominator == 0) {
            printf("%d\n", molecule / denominator);
            continue;
        }
        printf("%d/%d\n", molecule, denominator);
    }


}
/*
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int f(int m,int n)
{
if(m%n==0)
return n;
if(m%n)
return f(n,m%n);
}
int main()
{
char a[7];
while(scanf("%s",a)!=EOF)
{
for(int i=0;i<7;i++)
a[i]-='0';
a[3]+='0';
int q=(a[3]=='+')?a[0]*a[6]+a[2]*a[4]:a[0]*a[6]-a[2]*a[4];
int w=a[2]*a[6];
int c=abs(q);
if(c%w==0)
printf("%d\n",q/w);
else
printf("%d/%d\n",q/f(c,w),w/f(c,w));
}
}


*/
