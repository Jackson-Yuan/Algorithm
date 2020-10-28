/**
 * 是文件操作和结构体对象数组的处理问题，
 * 处理一个文件 student.txt，文件当中包括一组学生的信息，包括名字、学号、英语成绩、语文成绩、数学成绩、科学成绩，
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <fstream>

using namespace std;
struct student {
    string name;
    string id;
    int english;
    int chinese;
    int math;
    int science;
};

int strToInt(string val) {
    int res = 0;
    reverse(val.begin(), val.end());
    int base = 1;
    for (int i = 0; i < val.length(); ++i) {
        res += (val[i] - '0') * base;
        base *= 10;
    }

    return res;
}

bool cmp(struct student a, struct student b) {
    int sumA = a.science + a.math + a.chinese + a.english;
    int sumB = b.science + b.math + b.chinese + b.english;

    return sumA > sumB;
}

int main() {
    fstream in;
    string buffer;
    in.open("../student.txt", ios::in);
    int line = 1;
    vector<struct student> students;
    while (!in.eof()) {
        getline(in, buffer);
        if (line > 1) {
            struct student current;
            int index = buffer.find_first_of(' ');
            current.name = buffer.substr(0, index);

            buffer = buffer.substr(index + 1);
            index = buffer.find_first_of(' ');
            current.id = buffer.substr(0, index);

            buffer = buffer.substr(index + 1);
            index = buffer.find_first_of(' ');
            current.english = strToInt(buffer.substr(0, index));

            buffer = buffer.substr(index + 1);
            index = buffer.find_first_of(' ');
            current.chinese = strToInt(buffer.substr(0, index));

            buffer = buffer.substr(index + 1);
            index = buffer.find_first_of(' ');
            current.math = strToInt(buffer.substr(0, index));

            buffer = buffer.substr(index + 1);
            current.science = strToInt(buffer);

            students.push_back(current);
        }

        ++line;
    }

    sort(students.begin(), students.end(), cmp);

    for (int i = 0; i < students.size(); ++i) {
        cout << students[i].name << " "
             << students[i].id << " "
             << students[i].english << " "
             << students[i].chinese << " "
             << students[i].math << " "
             << students[i].science << endl;

    }
    return 0;
}
/**
 * 文件的读取操作，注意getline,文件与程序的相对位置
 * */