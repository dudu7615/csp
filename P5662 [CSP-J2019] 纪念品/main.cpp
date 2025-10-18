#include "bits/stdc++.h"
using namespace std;


#define DEBUG
#ifdef DEBUG
#define debugger(x) cout << __LINE__ << ": " << #x << " = " << x << "\n";
#else
#define debugger(x)
#endif


int solve(int T, int M, int N, const vector<vector<int>>& prices) {
    vector<int> w(N + 1);
    vector<int> c(N + 1);
    for (int i = 1; i < T; i++) {
        int cap = M; // current available coins as capacity
        vector<int> dp(cap + 1, 0);
        for (int j = 1; j <= N; j++) {
            w[j] = prices[i][j];
            c[j] = prices[i + 1][j] - prices[i][j];
        }
        for (int j = 1; j <= N; j++) {
            if (w[j] <= 0) continue;
            if (c[j] <= 0) continue; // no profit, skip
            for (int k = w[j]; k <= cap; k++) {
                dp[k] = max(dp[k], dp[k - w[j]] + c[j]);
            }
        }
        M += dp[cap];
    }
    return M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("in");

    // N M TMTMTMTMTMTMTMTM 写反了!!!!!!!!!!
    int T, N, M;
    cin >> T >> N >> M;
    vector<vector<int>> prices(T + 1, vector<int>(N + 1));
    for (int i = 1; i <= T; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> prices[i][j];
        }
    }

    int res = solve(T, M, N, prices);
    cout << res;
    return 0;
}