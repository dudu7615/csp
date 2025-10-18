#include "bits/stdc++.h"
using namespace std;

struct Obj {
    int price, weight;

    Obj(int price = 0, int weight = 0) : price(price), weight(weight) {}
};

int solve(int M, int N, vector<Obj> &objs) {
    vector<int> dp(M + 1, 0);
    for (int i = 1; i <= N; i++) {
        for (int j = M; j >= objs[i].weight; j--) {
            dp[j] = max(dp[j], objs[i].price + dp[j - objs[i].weight]);
        }
    }
    return dp[M];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ifstream cin("in");

    int M, N;
    cin >> M >> N;
    vector<Obj> objs(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> objs[i].weight >> objs[i].price;
    }
    cout << solve(M, N, objs) << "\n";
    return 0;
}