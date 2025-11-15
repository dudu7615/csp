#include <vector>

#include "bits/stdc++.h"
using namespace std;

#define DEBUG
#ifdef DEBUG
#define dbg(x) cout << __LINE__ << ": " << #x << " = " << (x) << "\n"
#else
#define dbg(x)
#endif

struct Road {
    int x, y, l;
    bool operator<(const Road &other) const { return l < other.l; }
    Road(int x, int y, int l) : x(x), y(y), l(l) {}
};

struct Point {
    int parent;
    vector<Point> children;
    Point(int parent) : parent(parent) {}
};

int find(int x, vector<Point> &points) {
    if(points[x].parent == x) {
        return x;
    }
    return find(points[x].parent, points);
}

void merge(int x, int y, vector<Point> &points) {
    int px = find(x, points);
    int py = find(y, points);
    if(px != py) {
        points[py].parent = px;
        points[px].children.push_back(points[py]);
    }
}

int solve(int n, vector<Road> &roads) {
    vector<Point> points;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        points.push_back(Point(i));
    }
    for (auto &x : roads) {
        int px = find(x.x, points);
        int py = find(x.y, points);
        if (px != py) {
            merge(px, py, points);
            sum += x.l;
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // ifstream cin("in");

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<Road> roads;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i][j] != 0) {
                roads.push_back(Road(i, j, a[i][j]));
            }
        }
    }
    sort(roads.begin(), roads.end());
    cout << solve(n, roads) << "\n";
    return 0;
}