/**
 * hdoj 2093
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
struct person {
    string name;
    int accepted;
    int time;
};
struct data {
    int base;
    int extra;
};

struct data stringToVal(string str) {
    int index = str.find_first_of('(');
    string base, extra;
    bool token = true;
    if (index == string::npos) {
        token = false;
        base = str;
    } else {
        extra = str.substr(index + 1, str.length() - index - 2);
        base = str.substr(0, index);
    }

    reverse(base.begin(), base.end());
    struct data target;
    int tmpValue = 0;
    int baseValue = 1;
    for (int i = 0; i < base.length(); ++i) {
        if (str[i] == '-') {
            tmpValue = -tmpValue;
        } else {
            tmpValue += (base[i] - '0') * baseValue;
        }
        baseValue *= 10;
    }
    target.base = tmpValue;

    if (token) {
        reverse(extra.begin(), extra.end());
        tmpValue = 0;
        baseValue = 1;
        for (int i = 0; i < extra.length(); ++i) {

            tmpValue += (extra[i] - '0') * baseValue;
            baseValue *= 10;
        }
        target.extra = tmpValue;
    } else target.extra = 0;

    return target;

}

bool cmp(struct person a, struct person b) {
    if (a.accepted == b.accepted) {
        if (a.time == b.time) {
            return a.name < b.name;
        } else return a.time < b.time;
    } else return a.accepted > b.accepted;
}

int main() {
    int n, punish;
    string name;
    cin >> n >> punish;
    vector<struct person> persons;
    while (cin >> name) {
        struct person current;
        current.name = name;
        current.time = 0;
        current.accepted = 0;
        for (int j = 0; j < n; ++j) {
            string grade;
            cin >> grade;
            struct data target = stringToVal(grade);
            if (target.base > 0) {
                ++current.accepted;
                current.time += target.base;
            }

            if (target.extra > 0) current.time += target.extra * punish;
        }

        persons.push_back(current);

    }
    sort(persons.begin(), persons.end(), cmp);

    for (int i = 0; i < persons.size(); ++i) {
        printf("%-10s ", persons[i].name.data());/**占10个字符宽度，左对齐*/
        printf("%2d ", persons[i].accepted);/**占2个字符宽度，右对齐*/
        printf("%4d", persons[i].time);
        cout << endl;
    }

    return 0;
}