#include <climits>

#include "bits/stdc++.h"
using namespace std;

using vvi = vector<vector<int>>;

struct Result {
    int cost;
    vector<int> path;
};

struct Point {
    int cost, id;
    vector<Point*> nexts;
    vector<Point*> prevs;
    Point(int c, int i, vector<Point*> n, vector<Point*> p)
        : cost(c), id(i), nexts(n), prevs(p) {}
};

void getCost(Point* point, const vvi& area) {
    for (auto prev : point->prevs) {
        if (point->cost + area[prev->id][point->id] < prev->cost) {
            prev->cost = point->cost + area[prev->id][point->id];
            getCost(prev, area);
        }
    }
}

Result slove(int N, const vvi& area) {
    vector<Point*> points(N, new Point(INT_MAX, -1, {}, {}));
    for (int i = 0; i < N; ++i) {
        points[i]->id = i;
    }
    points[N - 1]->cost = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            if (area[i][j] == 0) continue;
            points[i]->nexts.push_back(points[j]);
            points[j]->prevs.push_back(points[i]);
        }
    }

    getCost(points[N - 1], area);
    Result result;
    result.cost = points[0]->cost;
    for (auto p : points[0]->nexts) {
        result.path.push_back(p->cost);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifstream fin("in");
    cin.rdbuf(fin.rdbuf());

    int N;
    cin >> N;

    vvi area(N, vector<int>(N));
    for (auto& row : area) {
        for (auto& cell : row) {
            cin >> cell;
        }
    }

    Result result = slove(N, area);
    cout << "minlong=" << result.cost << '\n';
    for (int i = result.path.size() - 1; i >= 0; --i) {
        cout << result.path[i] + 1 << ' ';
    }
    cout << '\n';
    return 0;
}