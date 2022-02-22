#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> persons(n);

    for (int i = 0; i < persons.size(); ++i) {
        cin >> persons[i];
    }

    sort(persons.begin(), persons.end());

    int wait = 0, sum = 0;
    /**服务时间也得算进去*/
    for (int i = 0; i < persons.size(); ++i) {
        sum += wait + persons[i];
        wait += persons[i];
    }

    cout << (double) sum / n << endl;

}