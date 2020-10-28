#include<stdio.h>
#include<string.h>

int a[100000];

int main() {
    int n;

    while (scanf("%d", &n)) {
        int temp = 0;
        int max_min;
        int resultmax = -100;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i <= n; i++) {
            if (temp < 1) {
                temp = (i / 3) + 1;
                max_min = a[i];
            } else {
                int extratemp = (i / 3) + 1;
                if (temp != extratemp) {
                    if (max_min > resultmax) resultmax = max_min;
                    max_min = a[i];
                    temp = extratemp;
                    continue;
                }
                if (temp % 2 != 0) {
                    if (a[i] > max_min) max_min = a[i];
                } else {
                    if (a[i] < max_min) max_min = a[i];
                }

            }
        }

        printf("%d\n", resultmax);
    }
}

/*
自己所写较为繁琐
真确解答在于循环的手法 
*/
/*
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<math.h>
#include<string.h>
#include <stdlib.h>
using namespace std;
int main(){
  //  freopen("input.txt","r",stdin);
   int n;
   while(cin>>n){
        int maxx=-100000,k=0,a,b,c;
        k=n/3;
        int max,min;
        for(int i=1;i<=k;i++){
            cin>>a>>b>>c;
            if(i%2!=0){
                if(a>b&&a>c)
                max=a;
                else if(b>a&&b>c)
                max=b;
                else
                max=c;
                if(max>maxx)
                    maxx=max;
            }else{
                if(a<b&&a<c)
                    min=a;
                else if(b<a&&b<c)
                    min=b;
                else
                    min=c;
                if(min>maxx)
                    maxx=min;
            }
        }
        cout<<maxx<<endl;
   }
   return 0;
}






#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
int N;
int a[10005];
int b[10005];
while(scanf("%d",&N)!=EOF)
{
int i,j,t=0,k=0;
for(i=1;i<=N;i++)
scanf("%d",&a[i]);
for(j=1;j<=N;j+=3){
if(j%6==1)
b[k++]=max(max(a[j],a[j+1]),a[j+2]);
else if(j%6==4)//else ???
b[k++]=min(min(a[j],a[j+1]),a[j+2]);
}
sort(b,b+k);
printf("%d\n",b[k-1]); 
} 
}

*/
