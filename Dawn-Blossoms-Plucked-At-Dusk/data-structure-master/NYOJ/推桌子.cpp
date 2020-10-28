#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>

using namespace std;
struct qujian {
    int start;
    int end;
    int flag;
};

bool cmp(struct qujian a, struct qujian b) {
    return a.start < b.start;
}

struct qujian a[200];
int b[200];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            if (x > y) {
                int temp = x;
                x = y;
                y = temp;
            }
            a[i].start = (x - 1) / 2;
            a[i].end = (y - 1) / 2;
            a[i].flag = 1;
        }
        sort(a, a + n, cmp);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (a[i].flag == 0) continue;
            int endd = a[i].end;
            for (int j = i + 1; j < n; j++) {
                if (a[j].start > endd && a[j].flag == 1) {
                    a[j].flag = 0;
                    endd = a[j].end;
                }
            }
            count++;
        }


        cout << count * 10 << endl;
    }
}
/*
排列顺序值得关注，但目前找不到返利，也可以转化为求区间最大的堆叠次数 
*/
/*int index=0;
      int j;
      b[index]=a[0].flag;
      for(int i=1;i<n;i++)
      {
         for(j=0;j<=index;j++)
         {
              if(a[i].flag==b[j]) break;
         }
         if(j>index){
              index++;
              b[index]=a[i].flag;
         }
      }*/
