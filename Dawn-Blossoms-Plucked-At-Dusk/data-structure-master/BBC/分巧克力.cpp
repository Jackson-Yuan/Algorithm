/**
��������
������ͯ��������KλС���ѵ�С�������͡�С���ó�����ص��ɿ����д�С�����ǡ�
����С��һ����N���ɿ��������е�i����Hi x Wi�ķ�����ɵĳ����Ρ�


����Ϊ�˹�ƽ�����С����Ҫ���� N ���ɿ������г�K���ɿ����ָ�С�����ǡ��г����ɿ�����Ҫ���㣺


����1. ��״�������Σ��߳�������
����2. ��С��ͬ


��������һ��6x5���ɿ��������г�6��2x2���ɿ�������2��3x3���ɿ�����


������ȻС�����Ƕ�ϣ���õ����ɿ��������ܴ����ܰ�СHi��������ı߳��Ƕ���ô��
�����ʽ
������һ�а�����������N��K��(1 <= N, K <= 100000)
��������N��ÿ�а�����������Hi��Wi��(1 <= Hi, Wi <= 100000)
�������뱣֤ÿλС���������ܻ��һ��1x1���ɿ�����
�����ʽ
��������г����������ɿ��������ܵı߳���
��������
2 10
6 5
5 6
�������
2
*/
#include<iostream>

using namespace std;
struct chocolate {
    int x;
    int y;
};
int n;
struct chocolate ch[100000];

int getSum(int length) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a = ch[i].x / length;
        int b = ch[i].y / length;
        sum += a * b;
    }

    return sum;
}

int main() {
    int k;
    cin >> n >> k;
    int limit = -1;
    for (int i = 0; i < n; i++) {
        cin >> ch[i].x >> ch[i].y;
        if (ch[i].x > limit) limit = ch[i].x;
        if (ch[i].y > limit) limit = ch[i].y;
    }


    int max = -1;
    for (int i = 1; i <= limit; i++) {
        int sum = getSum(i);
        if (sum >= k) {
            if (i > max) max = i;
        }
    }

    cout << max << endl;
    return 0;
}
/**
int left = 1;
	int right = limit;
	int max = -1;
	while(left <= right){
		int mid = (left + right)/ 2;
		int sum = getSum(mid);
	    if(sum >= k){
	    	if(mid > max) max = mid;
	    	left = mid + 1;
	    }else{
	    	right = mid - 1;
	    }
	}
	
	cout << max << endl;
	return 0;
*/

/**
���ֲ������Ч�� 
*/
