#include "bits/stdc++.h"
using namespace std;

struct Obj {
    int price, weight;

    Obj(int price = 0, int weight = 0) : price(price), weight(weight) {}
};

int solve(int M, int N, vector<Obj> &objs) {
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (objs[i].weight <= j) {
                dp[i][j] = max(dp[i - 1][j],
                               objs[i].price + dp[i][j - objs[i].weight]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[N][M];
}

int solve1(int M, int N, vector<Obj> &objs) {
    vector<int> dp(M+1, 0);
    for (int i = 1; i <= N; i++) {
        for (int j = objs[i].weight; j<=M; j++) {
            dp[j] = max(dp[j], objs[i].price + dp[j - objs[i].weight]);
        }
    }
    return dp[M];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("in");

    int M, N;
    cin >> M >> N;

    vector<Obj> objs(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> objs[i].weight >> objs[i].price;
    }
    cout << "max=" << solve1(M, N, objs) << "\n";
    return 0;
}