#include<stdio.h>
/**
�ַ���ɢ�б� 
*/

/**
���޴�д�ַ�
A~Z ����0~25 ����26���� ���ݽ���ת������ ��ͬ�ַ��� ���Ψһ
����ϴ�Сд��ĸ ����Կ���52 ���� 
*/
int stringHash(char *str, int length) {
    int id = 0;
    int temp = 1;
    for (int i = length - 1; i >= 0; i--) {
        id += (str[i] - 'A') * temp;
        temp *= 26;
    }

    return id;
}

int stringHash2(char *str, int length) {
    int id = 0;
    for (int i = 0; i < length; i++) {
        id = id * 26 + (str[i] - 'A');
    }

    return id;
}

/**
��Сд���
����ټ�������0~9 ������62���� 
*/
int stringHash3(char *str, int length) {
    int id = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            id = id * 52 + (str[i] - 'A');
        } else {
            id = id * 52 + (str[i] - 'A') + 26;
        }
    }

    return id;
}

int main() {
    char *str = "ABDx";
    printf("%d\n", stringHash3(str, 8));
}
