#include "bits/stdc++.h"
using namespace std;

int getMaxPlace(vector<int> &a) {
    int maxPlace = -1, maxValue = -1;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > maxValue) {
            maxValue = a[i];
            maxPlace = i;
        }
    }
    return maxPlace;
}

int solveMax(vector<int> a) {
    int sum = 0;
    while (a.size() > 1) {
        int maxPlace = getMaxPlace(a);
        int nearPlace =
            (maxPlace - 1 >= 0 && a[maxPlace - 1] > a[maxPlace + 1]) ? maxPlace - 1 : maxPlace + 1;
        a[min(nearPlace, maxPlace)] += a[max(maxPlace, nearPlace)];
        sum += a[min(nearPlace, maxPlace)];
        a.erase(a.begin() + max(maxPlace, nearPlace));
        // a.resize(a.size() - 1);
    }
    sum += a[0];
    return sum;
}

int getMinPlace(vector<int> &a) {
    int minPlace = -1, minValue = INT_MAX;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < minValue) {
            minValue = a[i];
            minPlace = i;
        }
    }
    return minPlace;
}

int solveMin(vector<int> a) {
    int sum = 0;
    while (a.size() > 1) {
        int minPlace = getMinPlace(a);
        int nearPlace =
            (minPlace - 1 >= 0 && a[minPlace - 1] < a[minPlace + 1]) ? minPlace - 1 : minPlace + 1;
        a[min(nearPlace, minPlace)] += a[max(minPlace, nearPlace)];
        sum += a[min(nearPlace, minPlace)];
        a.erase(a.begin() + max(minPlace, nearPlace));
        // a.resize(a.size() - 1);
    }
    sum += a[0];
    return sum;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("in");

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    cout << solveMin(a) << "\n" << solveMax(a) << "\n";

    return 0;
}