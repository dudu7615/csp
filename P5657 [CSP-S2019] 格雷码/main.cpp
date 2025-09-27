#include "bits/stdc++.h"
using namespace std;
using ull = unsigned long long;

void getCode(ull n, ull k, vector<ull>& code, int type) {
    if (n == 0) {
        return;
    } else if (type == 0) {
        if (k < (1ull << (n - 1))) {
            code.push_back(0);
            getCode(n - 1, k, code, 0);
        } else {
            code.push_back(1);
            getCode(n - 1, k - (1ull << (n - 1)), code, 1);
        }
    } else {
        if (k < (1ull << (n - 1))) {
            code.push_back(1);
            getCode(n - 1, k, code, 0);
        } else {
            code.push_back(0);
            getCode(n - 1, k - (1ull << (n - 1)), code, 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // ifstream cin("in3");

    ull n, k;
    cin >> n >> k;
    vector<ull> code;
    getCode(n, k, code, 0);
    for (auto c : code) {
        cout << c;
    }

    return 0;
}