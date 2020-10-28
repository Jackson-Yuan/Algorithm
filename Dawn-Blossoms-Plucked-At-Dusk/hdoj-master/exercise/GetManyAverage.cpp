/**
 * 假设一个班有n(n<=50)个学生，每人考m(m<=5)门课，求每个学生的平均成绩和每门课的平均成绩，并输出各科成绩均大于等于平均成绩的学生数量。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;
struct student {
    vector<double> grades;
};

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<struct student> students;
        vector<double> averageGrades;
        for (int i = 0; i < n; ++i) {
            struct student tmp;
            for (int j = 0; j < m; ++j) {
                int grade;
                cin >> grade;
                tmp.grades.push_back(grade);
            }
            students.push_back(tmp);
        }

        for (int k = 0; k < students.size(); ++k) {
            vector<double> tmp = students[k].grades;

            double sum = 0;
            for (int i = 0; i < tmp.size(); ++i) {
                sum += tmp[i];
            }
            printf("%.2f", sum / tmp.size());
            if (k != students.size() - 1) cout << " ";
        }
        cout << endl;


        for (int i = 0; i < m; ++i) {
            double sum = 0;
            for (int j = 0; j < n; ++j) {
                sum += students[j].grades[i];
            }

            averageGrades.push_back(sum / n);
            printf("%.2f", sum / n);
            if (i != m - 1) cout << " ";
        }
        cout << endl;

        int count = 0;
        for (int i = 0; i < students.size(); ++i) {
            vector<double> tmp = students[i].grades;
            bool token = true;
            for (int j = 0; j < tmp.size(); ++j) {
                if (tmp[j] < averageGrades[j]) {
                    token = false;
                    break;
                }
            }

            if (token) ++count;
        }

        cout << count << endl;
        cout << endl;

    }

    return 0;
}