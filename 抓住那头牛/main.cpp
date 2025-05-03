#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int maxn = 100001;

void dfs(int x, int K, int step, vector<int>& steps) {
    if (x <= 0 || x >= maxn) return;
    
    if (steps[x] <= step && steps[x] != 0) return;
    if (x > K+3) return;
    steps[x] = step;
    

    dfs(x - 1, K, step + 1, steps);
    dfs(x + 1, K, step + 1, steps);
    dfs(x * 2, K, step + 1, steps);
}

int main() {
    ios::sync_with_stdio(false);
    // ifstream fin("in");
    // cin.rdbuf(fin.rdbuf());
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> steps(maxn, INT_MAX);
    steps[N] = 0;

    dfs(N, K, 0, steps);

    cout << steps[K] << "\n";
    return 0;
}