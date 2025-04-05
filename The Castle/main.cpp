#include <iostream>

#include "bits/stdc++.h"
using namespace std;
using ll = long long;

// const int w = 1, n = 2, e = 4, s = 8;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};

bool canGo(int direction, int a) { return !(a & direction); }

void dfs(int x, int y, int& roomSize, vector<vector<int>>& a,
         vector<vector<bool>>& visited) {
    visited[x][y] = true;
    roomSize++;

    for (int i = 0; i < 4; i++) {
        if (canGo(1 << i, a[x][y])) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= a.size() || ny < 0 || ny >= a[0].size())
                continue;
            if (visited[nx][ny]) continue;

            dfs(nx, ny, roomSize, a, visited);
        }
    }
    // maxRoom = max(maxRoom, roomSize);
}

int main() {
    ios::sync_with_stdio(false);
    // ifstream fin("in");
    // cin.rdbuf(fin.rdbuf());
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));

    for (auto& x : a) {
        for (auto& y : x) {
            cin >> y;
        }
    }

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int rooms = 0, maxRoom = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;
            int roomSize = 0;
            dfs(i, j, roomSize, a, visited);
            rooms++;
            maxRoom = max(maxRoom, roomSize);
            // cout << roomSize << "\n";
        }
    }
    cout << rooms << "\n";
    cout << maxRoom << "\n";
    return 0;
}