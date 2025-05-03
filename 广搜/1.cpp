#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> a(20, vector<int>(20, 0));
vector<vector<int>> q(400, vector<int>(4, 0));
vector<vector<int>> step(20, vector<int>(20, 0));

vector<int> fx = {0, 1, 0, -1};
vector<int> fy = {1, 0, -1, 0};

int tx, ty,n,m,head = 0, tail = 2;

int main() {
    cin >> n >> m;
    a[0][0] = 1;
    q[0][0] = 0;
    q[0][1] = 0;

    while (head <= tail) {
        for (int i = 0; i < 4; i++) {
            tx = q[head][0] + fx[i];
            ty = q[head][1] + fy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && a[tx][ty] == 0) {
                step[tx][ty] = step[q[head][0]][q[head][1]] + 1;
                a[tx][ty] = tail++;

                q[tail][0] = tx;
                q[tail][1] = ty;
                q[tail][2] = q[head][2] + 1;
                q[tail][3] = head + 1;

            }
        }
        head++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << setw(3) << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << setw(3) << step[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    cout << q[tail][2] << endl;

    vector<vector<int>> path;
    // 输出最短路径
    while (tail > 0) {
        path.push_back({q[tail][0], q[tail][1]});
        tail = q[tail][3];
    }
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i][0] << " " << path[i][1] << "->";
    }
    cout << endl;
    
    return 0;
}