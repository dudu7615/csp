#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(ll n, ll d, vector<ll>& s, vector<ll>& price) {
    ll minP = LLONG_MAX;
    ll sumS = 0;
    ll S1 = 0;
    ll sumOil = 0;
    ll sumCost = 0;
    for (ll i = 0; i < n; i++) {
        minP = min(minP, price[i]);
        sumOil += ceil(float(s[i] + S1 - sumS) / d);
        sumS += d * ceil(float(s[i] + S1 - sumS) / d);
        S1 += s[i];
        sumCost += minP * ceil(float(s[i] + S1 - sumS) / d);
    }
    return sumCost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifstream fin("in");
    cin.rdbuf(fin.rdbuf());

    ll n, d;
    cin >> n >> d;
    vector<ll> s(n);
    vector<ll> price(n);
    for (ll i = 0; i < n - 1; i++) {
        cin >> s[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> price[i];
    }
    ll result = solve(n, d, s, price);
    cout << result << endl;

    return 0;
}