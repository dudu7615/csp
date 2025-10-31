#include "bits/stdc++.h"
using namespace std;

#define DEBUG
#ifdef DEBUG
#define dbg(x) cout << __LINE__ << ": " << #x << "=" << (x) << "\n"
#else
#define dbg(x)
#endif

struct Obj {
    int W, C, P;

    Obj(int W = 0, int C = 0, int P = 0) : W(W), C(C), P(P) {}
};

int solve(int V, int N, int T, const vector<vector<Obj>>& groups) {
    vector<int> dp(V + 1, 0);

    for (int i = 1; i <= T; i++) {
        for (int j = V; j >= groups[i].size(); j--) {
            for(int k=1; k<groups[i].size(); k++) {
                if (j >= groups[i][k].W) {
                    dp[j] = max(dp[j], dp[j-groups[i][k].W] + groups[i][k].C);
                }
            }
        }
    }
    return dp[V];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("in");

    int V, N, T;
    cin >> V >> N >> T;
    vector<Obj> objs(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> objs[i].W >> objs[i].C >> objs[i].P;
    }

    int maxGroup = 0;
    for (auto& x : objs) {
        maxGroup = max(maxGroup, x.P);
    }

    vector<vector<Obj>> groups(maxGroup+1, vector<Obj>(1));
    for (int i = 1; i <= N; i++) {
        groups[objs[i].P].push_back(objs[i]);
    }

    int asw = solve(V, N, T, groups);
    cout << asw << "\n";
    return 0;

}