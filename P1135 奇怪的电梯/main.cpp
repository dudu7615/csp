#include "bits/stdc++.h"
using namespace std;
using vi = vector<int>;

void dfs(int x, vi K, int step, vi& steps) {
    if (x <= 0 || x >= steps.size()) return;

    if (steps[x] <= step) {
        step = steps[x];
    } else {
        steps[x] = step;
    }

    dfs(x - K[x], K, step + 1, steps);
    dfs(x + K[x], K, step + 1, steps);
}

int slove(int N, int A, int B, vi K) {
    int minStep = INT_MAX;
    vi steps(N, INT_MAX);

    steps[A] = 0;
    int a = A;

    dfs(A, K, 0, steps);

    return steps[B];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifstream fin("in");
    cin.rdbuf(fin.rdbuf());

    int N, A, B;
    cin >> N >> A >> B;

    vi K(N);
    for (int& ki : K) {
        cin >> ki;
    }

    int result = slove(N, A, B, K);
    cout << result << endl;
    return 0;
}