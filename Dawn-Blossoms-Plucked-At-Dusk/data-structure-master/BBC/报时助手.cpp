#include<stdio.h>

char *value[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven",
                   "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char *wei[4] = {"twenty", "thirty", "forty", "fifty"};

int main() {
    int hour, minute;
    scanf("%d%d", &hour, &minute);
    if (minute == 0) {
        printf("%s o'clock\n", value[hour]);
        return 0;
    }

    if (hour / 10 < 2) {
        printf("%s ", value[hour]);
    } else {
        if (hour % 10 == 0) {
            printf("%s ", wei[(hour / 10) - 2]);
        } else {
            printf("%s %s ", wei[(hour / 10) - 2], value[hour % 10]);
        }
    }

    if (minute < 10) {
        printf("%s %s", value[minute]);
    } else if (minute >= 10 && minute < 20) {
        printf("%s", value[minute]);
    } else {
        if (minute % 10 == 0) {
            printf("%s ", wei[(minute / 10) - 2]);
        } else {
            printf("%s %s", wei[(minute / 10) - 2], value[minute % 10]);
        }
    }
}
