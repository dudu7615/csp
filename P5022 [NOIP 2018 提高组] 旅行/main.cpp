#include <vector>

#include "bits/stdc++.h"
using namespace std;

// #define DEBUG
#ifdef DEBUG
#define dbg(x) cout << __LINE__ << ": " << #x << " = " << (x) << "\n";
#else
#define dbg(x)
#endif

struct Rode {
    int u, v;
    bool operator<(const Rode& other) const {
        if (u != other.u) {
            return u < other.u;
        }
        return v < other.v;
    }
    Rode(int _u = 0, int _v = 0) : u(_u), v(_v) {}
};

const int maxn = 6000;

void dfs(int u, int m, const vector<Rode>& rodes, vector<bool>& visited,
         vector<vector<int>>& path) {
    for (int i = 1; i <= m; i++) {
        if (rodes[i].u == u && !visited[rodes[i].v]) {
            visited[rodes[i].v] = true;

            vector<int> newPath = path.back();
            path.back().push_back(rodes[i].v);

            dfs(rodes[i].v, m, rodes, visited, path);
            visited[rodes[i].v] = false;
            if (i != m) {
                path.push_back(newPath);
            }
        }
    }
}

bool existIn(int x, const vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == x) {
            return true;
        }
    }
    return false;
}

void mergePath(vector<vector<int>>& path) {
    for(int i=1;i<path.size();i++) {
        for(int j=0;j<min(path[0].size(), path[i].size());j++) {
            if(!existIn(path[i][j], path[0])) {
                path[0].push_back(path[i][j]);
            }
        }
    }
}

bool cmpVec(const vector<int>& a, const vector<int>& b) {
    int len = min(a.size(), b.size());
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return a.size() < b.size();
}

vector<int> solve(int n, int m, const vector<Rode>& rodes) {
    vector<bool> visited(maxn, false);
    vector<vector<int>> path;
    path.push_back(vector<int>());
    path[0].push_back(1);
    visited[1] = true;
    dfs(1, m, rodes, visited, path);

#ifdef DEBUG
    for(int i = 0; i < path.size(); i++) {
        cout << "path " << i << ": ";
        for (int j = 0; j < path[i].size(); j++) {
            cout << path[i][j] << " ";
        }
        cout << "\n";
    }
#endif

    mergePath(path);

    return path[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef DEBUG
    ifstream cin("in1");
    // ofstream cout("out");
#endif

    int n, m;
    cin >> n >> m;

    vector<Rode> rodes(maxn);
    for (int i = 1; i <= m; i++) {
        cin >> rodes[i].u >> rodes[i].v;
    }
    for (int i = 1; i <= m; i++) {
        rodes[m + i] = Rode(rodes[i].v, rodes[i].u);
    }
    m *= 2;

    sort(rodes.begin() + 1, rodes.begin() + m + 1);

    vector<int> ans = solve(n, m, rodes);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}