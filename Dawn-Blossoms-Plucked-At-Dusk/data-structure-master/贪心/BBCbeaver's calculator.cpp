/*#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct exper{
	int index;
	long long value;
	int scien;
};
struct exper a[200000];
bool cmp(struct exper a, struct exper b){
	if(a.scien == b.scien) return a.index < b.index;
	else return a.value < b.value;
}
int main(){
	int n;
	scanf("%d",&n);
	int sum = 0;
	for(int i = 0 ; i < n ; i++){
		int num;
		long long first,x,y,m;
		scanf("%d %lld %lld %lld %lld", &num, &first, &x, &y, &m);
		for(int j = 0 ; j < num ; j++){
			a[sum].index = j + 1;
			a[sum].value = first;
			a[sum].scien = i + 1;
			sum++;
			first = (first * x + y) % m;
		}
	}
	
	sort(a, a+sum, cmp);
	int count = 0;
	long long compare = a[0].value;
	for(int i = 0 ; i < sum ; i++){
		if(a[i].value < compare){
			count++;
		}
		compare = a[i].value;
	}
	printf("%d\n",count);
	for(int i = 0 ; i < sum ; i++){
		printf("%lld %d\n",a[i].value,a[i].scien);
	}
}*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct sc {
    int cnt, count;
    long long num[5001];
} p[5010];

struct ms {
    int id;
    long long num;
} ans[200000], t[200000];

int sta, end;

void merge(int x, int y) {
    int mid = (x + y) >> 1, i = x, j = mid + 1, k = x;
    while (i != mid + 1 && j != y + 1) {
        if (ans[i].num > ans[j].num) {
            t[k].id = ans[j].id;
            t[k++].num = ans[j++].num;
        } else {
            t[k].id = ans[i].id;
            t[k++].num = ans[i++].num;
        }
    }
    while (i <= mid) {
        t[k].id = ans[i].id;
        t[k++].num = ans[i++].num;
    }
    while (j <= y) {
        t[k].id = ans[j].id;
        t[k++].num = ans[j++].num;
    }
    for (i = x; i <= y; ++i) {
        ans[i].id = t[i].id;
        ans[i].num = t[i].num;
    }

}

void mergesort(int x, int y) {
    if (x < y) {
        int mid = (x + y) >> 1;
        mergesort(x, mid);
        mergesort(mid + 1, y);
        merge(x, y);
    }
}

int main() {
    int n, i, j, k, l = 0, m, sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        long long t1, t2, t3, t4;
        k = 0;
        scanf("%d %lld %lld %lld %lld", &m, &t1, &t2, &t3, &t4);
        l += m;
        p[i].cnt = m;
        p[i].count = 1;
        p[i].num[0] = -1;
        p[i].num[1] = t1;
        for (j = 2; j <= m; ++j) {
            p[i].num[j] = (p[i].num[j - 1] * t2 + t3) % t4;
            if (p[i].num[j] < p[i].num[j - 1])
                k++;

        }
        if (k > sum) sum = k;
    }
    printf("%d\n", sum);
    if (l <= 200000) {
        sta = 0;
        end = 0;
        while (end < l) {
            for (i = 0; i < n; ++i) {
                for (j = p[i].count; j <= p[i].cnt; ++j) {
                    if (j != p[i].count && p[i].num[j] < p[i].num[j - 1]) {
                        p[i].count = j;
                        break;

                    }
                    ans[end].id = i;
                    ans[end++].num = p[i].num[j];

                }
                if (j > p[i].cnt)//all ascending
                    p[i].count = j;

            }
            mergesort(sta, end - 1);
            sta = end;

        }
        for (i = 0; i < l; ++i) printf("%lld %d\n", ans[i].num, ans[i].id + 1);

    }
    return 0;
}
/*
������ѵ����������֯��ÿ����ѧ�Ҹ��������˳�� ��Ϊ�����и���ʺ���趨 ÿ����ѧ�ҵ�����˳���ǹ̶��� �����������
���м���Դ���������ѧ�ҵ����� ��Ȼ����趨��bitch ��Ҳ�������Ĺ��� ��Ϊÿ����ѧ�ҵ�����˳��̶� ���������ǻ�������Ĺ̶�
���������Ŀ ���ٵĻ������Ϊ���п�ѧ���л���������� ���ܻ�е����� ������ ���������Ľ�����ǳ����� ���Ǳ����� �кü�����ѧ��
������� ��������˳�򲻵� �ᵥ�����Ļ�Ҫ�� ����ֻҪ�ҵ��������� Ȼ�����Ե�������Ϊ��׼ �������������ѧ�ҵ����� ���ӭ�ж���
���ʹ�ò������ ��
����ͼ������ʾ ����һ���ṹ��洢ÿ����ѧ�ҵ��������� ��count����������֯˳��ʱ�ؼ�����(��ʱ�޷����� ֻ�����)
����һ���ṹ��洢ʵ�����ֵ��������ѧ��id (��������)
�Ƚ����� ���� 
�ٿ�ʼ������������Ҫ����Ľṹ������
������� �����ϱ���ÿһ����ѧ�ҵ�ÿһ������ �洢���ṹ������
��ע�� ����ǰ���ǻ��� ���ݲ��������� ֱ��������ǰѭ�� ��ʼ��һ����ѧ�ҵ�������� �������Ҳ����
һ��ѭ����� ��ʼ����(ΪʲôҪ������ ��Ϊ ���㲻������������Ļ� ���Ա�֤ ÿ����ѧ�����������˳��Ĺ̶��� ��Ϊ������� ǰһ�����ں�һ��)
����ÿ����ѧ�������count��һ�δ�ѭ�����¼���ǻ����λ�� �ӻ����λ�ü����������� ���ٴ��������� ��Ȼ���� �������ʱ�� �Ǵ���һ��ѭ������Ľ����ط�����һ����ʼ��(ÿ��ѭ��������ǰ�󲻴�� ��Ȼֱ���ҵ�
��Ҳ�Ǵ���Ĺؼ�����)

���� �˿̵��һ����Ϳ��� �� 
*/
