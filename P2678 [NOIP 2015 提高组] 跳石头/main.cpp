#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll getMinLengthPos(const vector<ll> &d) {
    ll res = -1;
    ll minD = LLONG_MAX;
    for (ll i = 1; i < d.size(); i++) {
        if (d[i] - d[i - 1] < minD) {
            res = i;
            minD = d[i] - d[i - 1];
        }
    }
    return res;
}

void solve(ll M, vector<ll> &d) {
    while (M--) {
        ll pos = getMinLengthPos(d);
        d.erase(d.begin() + pos);
        // d.resize(d.size() - 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ifstream cin("in");

    ll L, N, M;
    cin >> L >> N >> M;
    vector<ll> d(N + 1);
    d[0] = 0;
    for (ll i = 1; i < N + 1; i++) {
        cin >> d[i];
    }
    d.push_back(L);
    sort(d.begin(), d.end());
    solve(M, d);
    ll minPos = getMinLengthPos(d);
    cout << d[minPos] - d[minPos - 1] << '\n';
    return 0;
}