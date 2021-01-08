#include "iostream"
#include "set"
#include "string"

using namespace std;
int len;
string str;
set<string> s;
bool visited[10] = {false};

void generate(int index, string ans) {
    if (index == len) {
        s.insert(ans);
        return;
    }

    for (int i = 0; i < str.length(); ++i) {
        if (!visited[i]) {
            visited[i] = true;
            string target = ans;
            target.append(1, str[i]);
            generate(index + 1, target);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> str;
    len = str.length();
    generate(0, "");
    auto ite = s.begin();
    while (ite != s.end()) {
        cout << *ite << endl;
        ++ite;
    }
    cout << s.size();
}