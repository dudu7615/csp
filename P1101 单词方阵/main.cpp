#include "bits/stdc++.h"
using namespace std;

using vvi = vector<vector<int>>;
using vvs = vector<vector<char>>;
const int dx[] = {0, 1, 0, -1,1,1,-1,-1};
const int dy[] = {1, 0, -1, 0,1,-1,-1,1};
const char str[] = {'y', 'i', 'z', 'h', 'o', 'n', 'g'};

void slove(vvs& in, vvs& result) {
    int n = in.size();
    vvi visited(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == 0 && in[i][j] == str[0]) {
                for (int k = 0; k < 8; k++) {
                    int x = i, y = j;
                    for (int wd = 1; wd < 7; wd++) {
                        
                        x += dx[k];
                        y += dy[k];
                        // 方向上是否不是相同的字母
                        if (x < 0 || x >= n || y < 0 || y >= n ||
                            in[x][y] != str[wd]) {
                            goto hasBreak;
                        }
                        // 仅在成功时填写结果
                    }
                    for (int a = 0; a < 7; a++) {
                        result[i + dx[k] * a][j + dy[k] * a] = str[a];
                        visited[i + dx[k] * a][j + dy[k] * a] = 1;
                    }
                // 存在break，直接结束
                hasBreak:
                    continue;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // ifstream fin("in2");
    // cin.rdbuf(fin.rdbuf());

    int n;
    cin >> n;
    vvs in(n, vector<char>(n));
    vvs result(n, vector<char>(n, '*'));
    for (auto& i : in) {
        for (auto& j : i) {
            cin >> j;
        }
    }
    slove(in, result);
    for (const auto& i : result) {
        for (const auto& j : i) {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}