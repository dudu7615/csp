/*
                       _oo0oo_
                      o8888888o
                      88" . "88
                      (| -_- |)
                      0\  =  /0
                    ___/`---'\___
                  .' \|     |// '.
                 / \|||  :  |||// \
               |   | \\  - /// |   |
               | \_|  ''\---/''  |_/ |
               \  .-\__  '-'  ___/-. /
             ___'. .'  /--.--\  `. .'___
          ."" '<  `.___\_<|>_/___.' >' "".
         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
         \  \ `_.   \_ __\ /__ _/   .-` /  /
     =====`-.____`.___ \_____/___.-`___.-'=====
                       `=---='


     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

           佛祖保佑     永不宕机     永无BUG
*/

#include <bits/stdc++.h>
#define ci cin >>
#define co cout <<
using namespace std;

int fx[4] = {0, 1, 0, -1};
int fy[4] = {1, 0, -1, 0};

bool canMove(int &x, int &y, int &m, int &n, int d, vector<vector<char>> &map)
{
    if (0 <= x + fx[d] <= m && 0 <= y + fy[d] <= n && map[x + fx[d]][y + fy[d]] == '.')
    {
        return true;
    }
    return false;
}

void getRes(int m, int n, int &x, int &y, int &k, int d, int &res, vector<vector<char>> &map)
{
    if (map[x][y] == 'x')
    {
        return;
    }
    map[x][y] = 'x';

    for (int i = 0; i < 4; i++)
    {
        if (k > 0 && canMove(x, y, m, n, (d+i)%4, map))
        {
            x += fx[(d+i)%4];
            y += fy[(d+i)%4];
            k -= 1;
            res += 1;
            getRes(m, n, x, y, k, (d+i)%4, res, map);
        }
    }
}

int main()
{
    freopen("in", "r", stdin);
    int T;
    ci T;
    for (int t = 0; t < T; t++)
    {
        int n, m, k, x0, y0, d0;
        ci n >> m >> k >> x0 >> y0 >> d0;
        x0 = x0 - 1;
        y0 = y0 - 1;
        vector<vector<char>> map(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ci map[i][j];
            }
        }

        int res, d = 0;
        getRes(m, n, x0, y0, k, d, res, map);
        co res;
    }
    return 0;
}
