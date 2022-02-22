#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

struct ability {
    int start;

    int end;
};

bool cmp(ability a, ability b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;
    vector<ability> abilities(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < abilities.size(); ++i) {
        cin >> abilities[i].start >> abilities[i].end;
    }

    int count = 0;
    sort(abilities.begin(), abilities.end(), cmp);
    for (int i = 0; i < abilities.size(); ++i) {
        if (visited[i]) continue;
        ++count;
        int end = abilities[i].end;
        for (int j = i + 1; j < abilities.size(); ++j) {
            if (abilities[j].start >= end) {
                visited[j] = true;
                end = abilities[j].end;
            }
        }
    }

    cout << count << endl;


}