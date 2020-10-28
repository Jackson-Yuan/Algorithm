/**
 * background:
 * A new semester comes , and the HDU also meets its 50th birthday. No matter what's your major,
 * the only thing I want to tell you is:"Treasure the college life and seize the time."
 * Most people thought that the college life should be colorful, less presure.But in actual,
 * the college life is also busy and rough. If you want to master the knowledge learned from the book,
 * a great deal of leisure time should be spend on individual study and practise, especially on the latter one.
 * I think the every one of you should take the learning attitude just as you have in senior school.
 * "No pain, No Gain", HDU also has scholarship, who can win it?
 * That's mainly rely on the GPA(grade-point average) of the student had got.
 * Now, I gonna tell you the rule, and your task is to program to caculate the GPA.
 * If there are K(K > 0) courses, the i-th course has the credit Ci, your score Si, then the result GPA is
 * GPA = (C1 * S1 + C2 * S2 +……+Ci * Si……) / (C1 + C2 + ……+ Ci……) (1 <= i <= K, Ci != 0)
 * If there is a 0 <= Si < 60, The GPA is always not existed.
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int k;
        cin >> k;
        vector<double> credits;
        vector<double> scores;
        string courseName;
        bool token = true;
        for (int i = 0; i < k; ++i) {
            double tmpCredits, tmpScores;
            cin >> courseName >> tmpCredits >> tmpScores;
            credits.push_back(tmpCredits);
            scores.push_back(tmpScores);
            if (tmpScores < 60) token = false;
        }


        if (token) {
            double sum = 0;
            double sumCredits = 0;
            for (int i = 0; i < k; ++i) {
                sum += credits[i] * scores[i];
                sumCredits += credits[i];
            }

            printf("%.2lf\n", sum / sumCredits);
        } else cout << "Sorry!" << endl;


        if (n != 0) cout << endl;/** 注意格式，两个例子间有空行，但最后一个例子不要有*/
    }

    return 0;
}