#include "bits/stdc++.h"
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

struct Result {
    int length;
    vi sequence;

    Result(int len, const vi &seq) : length(len), sequence(seq) {}

};

Result solve(vi &b) {
    int n = b.size();
    vi dp(n, 1);
    vvi nums(n);
    for(int i = 0; i < n; ++i) {
        nums[i].push_back(b[i]);
    }

    for(int i=n-1; i >= 0; --i) {
        for(int j=i+1; j < n; ++j) {
            if(b[i] < b[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                if(dp[i] == dp[j] + 1) {
                    nums[i] = nums[j];
                    nums[i].push_back(b[i]);
                }
            }
        }
    }
    int maxLength = *max_element(dp.begin(), dp.end());
    vi longestSequence;
    for(int i = 0; i < n; ++i) {
        if(dp[i] == maxLength) {
            longestSequence = nums[i];
            break;
        }
    }
    return Result(maxLength, longestSequence);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("in");
    cin.rdbuf(fin.rdbuf());

    int n;
    cin >> n;
    vi b(n);
    for(auto &x : b) {
        cin >> x;
    }
    Result result = solve(b);
    cout << "max=" << result.length << '\n';
    for(int i=result.sequence.size()-1; i >= 0; --i) {
        cout << result.sequence[i] << ' ';
    }
    return 0;
}