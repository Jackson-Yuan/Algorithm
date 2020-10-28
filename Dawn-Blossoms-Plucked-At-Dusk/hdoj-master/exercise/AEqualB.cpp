/**
 * Give you two numbers A and B, if A is equal to B, you should print "YES", or print "NO".
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

string removeZeroByTop(string str) {
    int index = -1;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != '0') {
            index = i;
            break;
        }
    }

    if (index != -1) return str.substr(index);
    else return "";
}

string removeZeroByBottom(string str) {
    int index = -1;
    for (int i = str.length() - 1; i >= 0; --i) {
        if (str[i] != '0') {
            index = i;
            break;
        }
    }

    if (index != -1) return str.substr(0, index + 1);
    else return "";
}

int main() {
    string a, b;
    while (cin >> a >> b) {
        int splitA, splitB;
        splitA = a.find('.');
        splitB = b.find('.');
        if (splitA == string::npos) {
            splitA = a.length();
        }
        if (splitB == string::npos) {
            splitB = b.length();
        }
        string leftA = a.substr(0, splitA - 0);
        string leftB = b.substr(0, splitB - 0);
        leftA = removeZeroByTop(leftA);
        leftB = removeZeroByTop(leftB);

        if (leftA != leftB) {
            cout << "NO" << endl;
            continue;
        }

        string rightA, rightB;
        if (splitA == a.length()) rightA = a.substr(splitA);
        else rightA = a.substr(splitA + 1);
        if (splitB == b.length()) rightB = b.substr(splitB);
        else rightB = b.substr(splitB + 1);
        rightA = removeZeroByBottom(rightA);
        rightB = removeZeroByBottom(rightB);

        if (rightA != rightB) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }
    return 0;
}