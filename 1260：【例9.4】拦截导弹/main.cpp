#include "bits/stdc++.h"
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

struct Result {
    int a, b;
    Result(int a, int b) : a(a), b(b) {}
};

struct Point {
    int n;
    vi used;
    Point(int n, vi used) : n(n), used(used) {}
    bool operator<(const Point& other) const { return n < other.n; }
};

int solve(const vi& in, int& needed) {
    needed++;
    int n = in.size();
    // vi dp(n, 1);
    // vvi usedNums(n);
    vector<Point> points(n, Point(1, {}));
    for (int i = 0; i < n; ++i) {
        // usedNums[i].push_back(i);
        points[i].used.push_back(i);
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i - 1; j >= 0; --j) {
            if (in[i] < in[j]) {
                if (points[j].n < points[i].n + 1) {
                    points[j].n = points[i].n + 1;
                    points[j].used = points[i].used;
                    points[j].used.push_back(j);
                }
            }
        }
    }
    Point maxPoint = *max_element(points.begin(), points.end());
    vi wastedPoints;

    // not in maxPoint.used
    for (int i = 0; i < n; ++i) {
        if (find(maxPoint.used.begin(), maxPoint.used.end(), i) ==
            maxPoint.used.end()) {
            wastedPoints.push_back(in[i]);
        }
    }

    if (!wastedPoints.empty()) {
        solve(wastedPoints, needed);
    }

    return maxPoint.n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ifstream fin("in");
    // cin.rdbuf(fin.rdbuf());

    vi in;
    int x;
    while (cin >> x) {
        in.push_back(x);
    }
    int needed = 0;
    int result = solve(in, needed);
    cout << result << '\n' << needed << '\n';
    return 0;
}