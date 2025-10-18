#include "bits/stdc++.h"
using namespace std;

struct Obj {
    int w, c, p;
    // p: count, 0 for inf

    Obj(int w = 0, int c = 0, int p = 0) : w(w), c(c), p(p) {}
};

int solve(int m, const vector<Obj> &objs) {
    int n = objs.size() - 1;
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        if (objs[i].p == 0) {
            for (int j = objs[i].w; j <= m; j++) {
                dp[j] = max(dp[j], objs[i].c + dp[j - objs[i].w]);
            }
        } else {
            for (int j = m; j >= objs[i].w; j--) {
                dp[j] = max(dp[j], objs[i].c + dp[j - objs[i].w]);
            }
        }
    }
    return dp[m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("in");

    int m, n;
    cin >> m >> n;
    vector<Obj> objs(1);

    int w, c, p;
    for (int i = 1; i <= n; i++) {
        cin >> w >> c >> p;
        if (p > 1) {
            int t = 1;  // 2^t
            while (t < p) {
                objs.push_back(Obj(w * t, c * t, 1));
                p -= t;
                t <<= 1;
            }
            if (p > 0) {
                objs.push_back(Obj(w * p, c * p, 1));
            }
        } else {
            objs.push_back(Obj(w, c, p));
        }
    }
    cout << solve(m, objs) << "\n";
    return 0;
}