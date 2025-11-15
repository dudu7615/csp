#include "bits/stdc++.h"
using namespace std;

#define DEBUG
#ifdef DEBUG
#define dbg(x) cout << __LINE__ << ": " << #x << " = " << (x) << "\n"
#else
#define dbg(x)
#endif


int solve(int n, vector<int>& a) {
    vector<bool> dp(26000, 0);
    int need = 0;
    dp[0] = true;
    for(int i=1; i<=n; i++) {
        if (dp[a[i]]) {
            continue;
        }
        need++;
        for(int j=a[i]; j<=a[a.size()-1]; j++) {
            if(dp[j-a[i]]) {
                dp[j] = true;
            }
        }
    }
    return need;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ifstream cin("in");

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a.begin() + 1, a.end());
        cout << solve(n, a) << "\n";
    }
    return 0;
}