#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>

using namespace std;
struct coordinate {
    double left;
    double right;
};

bool cmp(struct coordinate a, struct coordinate b) {
    return a.left < b.left;
}

struct coordinate a[100000];

int main() {
    int N;
    cin >> N;
    while (N--) {
        int n;
        double w, h;
        scanf("%d%lf%lf", &n, &w, &h);
        for (int i = 0; i < n; i++) {
            double x, r;
            scanf("%lf%lf", &x, &r);
            double flag;
            if (2 * r > h) {
                flag = sqrt(r * r - h * h / 4);
            } else flag = 0;
            a[i].left = x - flag;
            a[i].right = x + flag;
        }
        sort(a, a + n, cmp);
        int count = 0;
        double temp = 0;
        for (int i = 0; i < n; i++) {
            //��˵�ﲻ��0�����һ���˵㵽�ﲻ��w
            /*	if((i==0 && a[i].left > 0) || (i==n-1 && a[i].right< w)){
                    count = 0;
                    break;
                }*/
            if (a[i].left <= temp) {
                double start = a[i].right;
                while (a[i].left <= temp) {
                    start = max(a[i].right, start);
                    i++;
                    if (i == n) break;
                }
                temp = start;
                i--;
                count++;

            }/*else{
		    	count=0;
		    	break;
		    }
		    
		    if(a[i].right>=w) break;*/

            if (temp >= w) break;
        }
        if (temp >= w)
            cout << count << endl;
        else cout << 0 << endl;
    }
}
/*
�����һ���ؼ���Ϊ �����ˮװ�õ���Ч�������������Բ����� ����Բ���ƺ�ཻ�ľ��ε����������ת��Ϊ���䣬�롾0,w�����Ƿ�����ȫ����
 �ڼ���Ƿ�����ȫ����ʱ��Ӧע�� ��һ�������˵�һ��Ҫ<= ��һ������Ҷ˵㣬����ֻ�е���һ������Ҷ˵���� ��һ������Ҷ˵�ʱ���ܼ���
 ������һ������ôȡ�����ǰ��հ���˵�Ĵ�С��������ȡ ������˭��С����һ���˵���Ҷ˵������£��Ƚ�˭���Ҷ˵�ֵ����ѡȡ����ͼע�͵��Ĳ���
 �Ǵ������  if(temp >= w) break;����  ע�ʹ��뱨�������������û�п��� ������ô�� �Ժ���˵ 

*/
