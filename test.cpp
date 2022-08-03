#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "stack"

using namespace std;


class Solution {
public:
    string decodeString(string s) {
        stack<int> sInt;
        stack<string> sChar;

        string ans;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                string tmp;

                int end = i + 1;
                while (end < s.length() && s[end] != '[') ++end;
                sInt.push(atoi(s.substr(i, end - i).c_str()));
                int start;
                if (s[end + 1] >= '0' && s[end + 1] <= '9') {
                    sChar.push("");
                    start = end + 1;
                } else {
                    sChar.push(string(1, s[end + 1]));
                    start = end + 2;
                }


                while (!sChar.empty() && start < s.length()) {
                    while (start < s.length() && s[start] != ']') {
                        if (s[start] >= '0' && s[start] <= '9') {
                            end = start + 1;
                            while (end < s.length() && s[end] != '[') ++end;
                            sInt.push(atoi(s.substr(start, end - start).c_str()));
                            if (s[end + 1] >= '0' && s[end + 1] <= '9') {
                                sChar.push("");
                                start = end + 1;
                            } else {
                                sChar.push(string(1, s[end + 1]));
                                start = end + 2;
                            }

                        } else {
                            sChar.top().append(1, s[start]);
                            ++start;
                        }
                    }


                    int k = sInt.top();
                    sInt.pop();
                    string str = sChar.top();
                    sChar.pop();

                    string tmpStr;
                    while (k--) {
                        tmpStr += str;
                    }

                    tmp = tmpStr;

                    if (!sChar.empty()) sChar.top().append(tmp);
                    ++start;
                }
                i = start - 1;
                ans.append(tmp);

            } else {
                ans.append(1, s[i]);
            }
        }


        return ans;
    }
};

int main() {
    Solution solution;

    cout << solution.decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef");
}
