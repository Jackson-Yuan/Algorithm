#include<stdio.h>

int main() {
    /*int a,b,c,sum;
    scanf("%d %d %d",&a,&b,&c);
    sum=70*a+21*b+15*c;
    for(;sum>0;sum=sum-105)
    {
        if(sum<=100&&sum>=10)
        {
            printf("%d",sum);
            break;
        }
        else if(sum<=10)
        {
        printf("No answer");
        break;
       }
    }*/
    int a, b, c, sum;
    scanf("%d %d %d", &a, &b, &c);
    for (sum = 10; sum < 100; sum++) {
        if (sum % 3 == a && sum % 5 == b && sum % 7 == c)
            printf("%d ", sum);
    }

}
