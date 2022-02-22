/**
 * ����n ��ʵ��x1, x2 ,..., xn������n ������ʵ��������2����֮�������ֵ��
 * ������κ�ʵ������ȡ��������O(1)����ƽ�����϶���������ʱ���㷨��
 * */
#include "iostream"
#include "vector"

using namespace std;

int findMaxIndex(vector<double> array) {
    int ans = 0;
    double tmp = array[0];
    for (int i = 0; i < array.size(); ++i) {
        if (array[i] > tmp) {
            ans = i;
            tmp = array[i];
        }
    }

    return ans;
}

int findMinIndex(vector<double> array) {
    int ans = 0;
    double tmp = array[0];
    for (int i = 0; i < array.size(); ++i) {
        if (array[i] < tmp) {
            ans = i;
            tmp = array[i];
        }
    }

    return ans;
}

/**
 * Ѱ������϶
 * */
double maxGap(vector<double> array) {
    double minVal = array[findMinIndex(array)];
    double maxVal = array[findMaxIndex(array)];

    vector<int> buckets(array.size() - 1);
    vector<double> low(array.size() - 1);
    vector<double> high(array.size() - 1);

    for (int i = 0; i < buckets.size(); ++i) {
        buckets[i] = 0;
        low[i] = maxVal;
        high[i] = minVal;
    }

    int n = array.size();

    for (int i = 0; i < n; ++i) {
        int bucketId = int((n - 1) * (array[i] - minVal) / (maxVal - minVal));
        if (bucketId == n - 1) bucketId = n - 2;
        ++buckets[bucketId];
        if (array[i] < low[bucketId]) low[bucketId] = array[i];
        if (array[i] > high[bucketId]) high[bucketId] = array[i];
    }

    double ans = 0;
    double left = high[0];

    for (int i = 1; i < buckets.size(); ++i) {
        if (buckets[i]) {
            double gap = low[i] - left;
            if (gap > ans) ans = gap;
            left = high[i];
        }
    }

    return ans;
}

int main() {
    vector<double> array = {2.3, 3.1, 7.5, 1.5, 6.3};
    cout << maxGap(array);
}