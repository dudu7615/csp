#include <bits/stdc++.h>
using namespace std;

int fx[4] = {1, 0, -1, 0};
int fy[4] = {0, 1, 0, -1};

void getRes(int x, int y, int nx, int ny, int n, vector<vector<int>> &map, bool &can)
{
    if (map[x][y] == 1 || map[nx][ny] == 1)
        return;
    map[nx][ny] = 1;

    for (int i = 0; i < 4; i++)
    {
        nx += fx[i];
        ny += fy[i];
        if (nx == x && ny == y)
        {
            can = true;
            return;
        }
        else
        {
            if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1 || can)
            {
                return;
            }
            else
            {
                getRes(x, y, nx, ny, n, map, can);
            }
        }
    }
}

int main()
{
    int n, ha, la, hb, lb;
    cin >> n;
    vector<vector<int>> inputs(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> inputs[i][j];
    }
    cin >> ha >> la >> hb >> lb;
    bool can = false;

    getRes((hb - 1), (lb - 1), (ha - 1), (la - 1), n, inputs, can);
    if (can)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}