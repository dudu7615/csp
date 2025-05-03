#include "bits/stdc++.h"
using namespace std;

vector<pair<int, int>> directions = {
    {0, 1},
    {1, 0},
    {1, 1},
    {1, -1},
    {0, -1},
    {-1, 0},
    {-1, -1},
    {-1, 1}
};
//192.168.1.32
int x,y,nx,ny;

int main() {
    ios::sync_with_stdio(false);
    ifstream fin("in");
    cin.rdbuf(fin.rdbuf());
    cin.tie(nullptr);
    

    int N, M;
    cin >> N >> M;
    vector<vector<char>> area(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> area[i][j];
    }

    int ans = 0;
    for (int i; i < N; i++) {
        for (int j; j < M; j++) {
            if(area[i][j] == 'W') {
                for(auto dir : directions) {
                    nx = i + dir.first;
                    ny = j + dir.second;
                    if(nx >= 0 && nx < N && ny >= 0 && ny < M && area[nx][ny] == 'W') {
                        break;
                    }
                    ans++;
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}