#include "bits/stdc++.h"
using namespace std;

struct Obj {
    int v, w, s;
    Obj(int v = 0, int w = 0, int s = 0) : v(v), w(w), s(s) {}
};

int solve(int m, vector<Obj*> objs) {
    int n = objs.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (objs[i]->v <= j) {
                dp[i][j] =
                    max(dp[i - 1][j], objs[i]->w + dp[i - 1][j - objs[i]->v]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("in");

    int n, m;
    cin >> n >> m;
    vector<Obj> objs0(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> objs0[i].v >> objs0[i].w >> objs0[i].s;
    }

    vector<Obj*> objs(1);

    for (int i = 1; i <= n; i++) {
        int t = 1;  // 2^t
        while (t <= objs0[i].s) {
            objs.push_back(new Obj(objs0[i].v * t, objs0[i].w * t));
            objs0[i].s -= t;
            t <<= 1;
        }
        if (objs0[i].s > 0) {
            objs.push_back(
                new Obj(objs0[i].v * objs0[i].s, objs0[i].w * objs0[i].s));
        }
    }
    cout << solve(m, objs) << "\n";

    return 0;
}