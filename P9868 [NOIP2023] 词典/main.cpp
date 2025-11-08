#include "bits/stdc++.h"
using namespace std;

// #define DEBUG
#ifdef DEBUG
#define dbg(x) cout << __LINE__ << ": " << #x << " = " << (x) << "\n";
#else
#define dbg(x)
#endif

string getMx(string x) {
    sort(x.begin(), x.end());
    reverse(x.begin(), x.end());
    return x;
}

string getMn(string x) {
    sort(x.begin(), x.end());
    return x;
}

vector<int> solve(int n, int m, const vector<string>& dict) {
    vector<int> ans(n + 1,1);
    vector<string> mxDict(n + 1), mnDict(n + 1);
    for (int i = 1; i <= n; i++) {
        mxDict[i] = getMx(dict[i]);
        mnDict[i] = getMn(dict[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (mnDict[i] > mxDict[j]) {
                ans[i] = 0;
                dbg(i);
                for (int k = 0; k < m; k++) {
                    dbg(mnDict[i][k]);
                }
                dbg(j);
                for (int k = 0; k < m; k++) {
                    dbg(mxDict[j][k]);
                }
                break;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream cin("in");

    int n, m;
    cin >> n >> m;

    vector<string> dict(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> dict[i];
    }
    vector<int> ans = solve(n, m, dict);
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}