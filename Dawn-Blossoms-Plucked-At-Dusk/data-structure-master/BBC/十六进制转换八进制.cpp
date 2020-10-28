#include<stdio.h>
#include<string.h>

char a[100000];
char b[400000];
char result[400000];
int value[3] = {4, 2, 1};
int sum;

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        sum = 0;
        scanf("%s", a);
        int length = strlen(a);
        int count = length * 4;
        if (count % 3 != 0) {
            int temp = count / 3;
            temp = temp * 3 + 3;
            int difference = temp - count;
            for (int i = 0; i < difference; i++) {
                b[sum] = '0';
                sum++;
            }
        }
        /*转换二进制*/
        for (int i = 0; i < length; i++) {
            int temp;
            int tempValue[4];
            if (a[i] >= '0' && a[i] <= '9') {
                temp = a[i] - '0';
            } else {
                temp = a[i] - 'A' + 10;
            }

            for (int j = 0; j < 4; j++) {
                tempValue[j] = temp % 2;
                temp /= 2;
            }

            for (int j = 3; j >= 0; j--) {
                b[sum] = tempValue[j] + '0';
                sum++;
            }
        }
        int index = 0;
        for (int i = 0; i < sum; i++) {
            if (i % 3 == 0) {
                result[index] = value[i % 3] * (b[i] - '0') + '0';
                index++;
            } else {
                result[index - 1] = result[index - 1] - '0' + value[i % 3] * (b[i] - '0') + '0';
            }
        }
        /*for(int i = 0 ; i < index ; i++){
            if(i == 0 && result[i] == '0') continue;
            printf("%c",result[i]);
        }*/
        int i = 0;
        while (i < index && result[i] == '0') i++;
        if (i >= index) printf("0\n");
        else {
            for (; i < index; i++) {
                printf("%c", result[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
/*
先不管了  两者答案都是一样的 此题如上代码错误 原因只有一个 temp数组开小了 要补0 所以大于400000 
*/
/*#include<stdio.h>
#include<string.h>

char h[100002],b[400002],e[400002];
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",h);
        int i,len=0;
        /*先把16进制化成二进制——从后往前展开 */
/*for(i=strlen(h)-1;i>=0;i--){
    int v;
    if(h[i]>='0' && h[i]<='9')
        v=h[i]-'0';
    else v=h[i]-'A'+10;
    for(int j=0;j<4;j++){
        b[len++]=v%2+'0';
        v/=2;
    }
}
b[len]='\0';
int x=0,cnt=1;
int l=0;
for(i=0;i<len;i++){
    /*每三位二进制转成一位8进制,最后不足三位补0*/
/*if(cnt==4||i==len-1){
    x=cnt*(b[i]-'0')+x;
    cnt=1;
    e[l++]=x+'0';
    x=0;
} else{
    x=cnt*(b[i]-'0')+x;
    cnt*=2;
   }
}
i=l-1;
while(i>=0 && e[i]=='0')
/*去掉前导0*/
/* i--;
if(i<0)
 printf("0");
for (;i>=0;i--){
 printf("%c",e[i]);
}
printf("\n");
}
return 0;
}*/
