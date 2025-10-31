#include "bits/stdc++.h"
using namespace std;

#define DEBUG
#ifdef DEBUG
#define dbg(x) cout << __LINE__ << ": " << #x << "=" << (x) << "\n"
#else
#define dbg(x)
#endif

struct Point {
    int scrol, sum, step;

    Point(int sc = 0, int su = 0, int st = 0) : scrol(sc), sum(su), step(st) {}
};

int dfs0(int cur, int n, const vector<int>& scrol,
         const vector<vector<int>>& links, vector<bool>& visited, int sum,
         int step) {
    if (step == 5) {
        if (links[cur][1] | links[1][cur]) {
            return sum;
        } else {
            return 0;
        }
    }

    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (!visited[i] && (links[cur][i] | links[i][cur])) {
            visited[i] = true;
            ans = max(ans, dfs0(i, n, scrol, links, visited, sum + scrol[i],
                               step + 1));
            visited[i] = false;
        }
    }
    return ans;
}

int dfs(int cur, int n, const vector<int>& scrol,
        const vector<vector<int>>& links, vector<bool>& visited, int sum,
        int step) {
    queue<Point> q;
    q.push(Point(cur, sum, step));
    int ans = 0;
    while()


    return 0;
}

int solve(int n, int m, int k, const vector<int>& scrol,
          const vector<vector<int>>& links) {
    vector<bool> visited(n + 1);
    int lsum=0, step=0;
    return dfs(1, n, scrol, links, visited, lsum, step);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifstream cin("in2");
    // ofstream cout("out");

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> scrol(n + 1);
    vector<vector<int>> links(n + 1, vector<int>(n + 1, 0));
    for (int i = 2; i <= n; i++) {
        cin >> scrol[i];
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        links[x][y] = 1;
    }
    cout << solve(n, m, k, scrol, links) << "\n";
    return 0;
}