#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;
int map[100][100];
int result[100];
int r, c;
int a[100];

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int maxValue = -999999999;
        scanf("%d%d", &r, &c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        /*��Ҫ˼· ��άתһά Ȼ���൱����������Ӵ��� ��ôת ��Ҫ������*/
        for (int i = 0; i < r; i++) {
            /*��i�мӵ�j�� ÿ��iѭ��һ�� ��ζ���Ǹ��µ���� Ҫ����result����*/
            memset(result, 0, sizeof(result));
            for (int j = i; j < r; j++) {
                /*ÿ��jѭ��һ�� ��ζ��Ҫ����һ�����ݺϲ�  sum����result[i]��һά���� ÿ��������i�����ֵ �����´��� ÿ�����һ��result[i] ��Ҫ����������result[i]ʱ�����ֵ �ٽ�sum�����������ֵ���Ƚ�
                ���ھ��滻maxֵ С�ھ�����
                 */
                int sum = 0;
                for (int k = 0; k < c; k++) {
                    result[k] += map[j][k];
                    if (sum > 0) sum += result[k];
                    else sum = result[k];
                    maxValue = max(sum, maxValue);
                }

            }
        }

        printf("%d\n", maxValue);
    }
}
/*������ʵ����ͻ��һ��ת��˼�� ͬʱ��dpʱ�Ĳ���Ҳ�������ڶ���������Ӵ����㷨 
���յĻ����ϳ�����
��Щ��Ŀ����Ҫ�ú���Ⱑ ���� 
*/
