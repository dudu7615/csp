#include "bits/stdc++.h"
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    ios::sync_with_stdio(false);
    ifstream fin("in");
    cin.rdbuf(fin.rdbuf());
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> area0(n, vector<int>(m, 0));
    vector<vector<int>> area(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> area[i][j];
    }
    vector<Point> points;

    
}