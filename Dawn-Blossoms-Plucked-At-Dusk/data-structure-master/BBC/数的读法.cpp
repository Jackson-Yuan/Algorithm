#include<stdio.h>

char *str[100];
char *num[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
char *wei[5] = {"shi", "bai", "qian", "wan", "yi"};

int main() {
    int target;
    scanf("%d", &target);
    int value;
    int index = 0;//λ��
    int j = 0;//��������±�
    int wanFlag = 0;
    int yiFlag = 0;
    while (target) {
        value = target % 10;
        target /= 10;
        if (value > 0) {
            if (index > 0) {//indexΪ0ʱ�Ǹ�λ ����Ҫ�����δ�
                if (index >= 4 && index < 8 && !wanFlag) {//�� wan
                    wanFlag = 1;
                    str[j] = "wan";
                    j++;
                }
                if (index >= 8 && !yiFlag) {//�� yi
                    yiFlag = 1;
                    str[j] = "yi";
                    j++;
                }
                if (index % 4 != 0) {//����λ����λ�� �� ��λʱ ����Ҫ�ٶ������
                    str[j] = wei[index % 4 - 1];
                    j++;
                }
            }
            str[j] = num[value];
            j++;
        } else {
            if (j > 0 && str[j - 1] != num[0]) {//�ж�ǰ���Ƿ��ж���� ������10000 1000֮�����
                str[j] = num[0];
                j++;
            }
        }
        index++;
    }

    if (!(str[j - 1] == "yi" && j > 1 && str[j - 2] == "shi")) printf("%s ", str[j - 1]);
    for (int i = j - 2; i >= 0; i--) {
        printf("%s ", str[i]);
    }
    printf("\n");
    return 0;
}
/*����ѡ��� �������ض� ����*/
	
