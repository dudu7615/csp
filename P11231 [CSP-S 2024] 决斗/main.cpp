#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen("in", "r", stdin);

    int n;
    cin >> n;
    vector<int> input(n);

    for (int& s : input) {
        cin >> s;
    }

    sort(input.begin(), input.end());

    int notUsed = n;
    int i = 0, j = 1;
    while (j < n) {
        if (input[i] < input[j]) {
            notUsed--;
            i++;
        }
        j++;
    }

    cout << notUsed << endl;
}