#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;

struct Time
{
    int come;
    int go;
};

Time cn[maxn];
Time abroad[maxn];

bool canIn(int n, int plainNum, Time plains[])
/*
n: 廊桥数（此地）
plainNum：飞机序号
plains：此地飞机数组
 */
{
    for (int i = 0; i < plainNum; i++)
    {
        if (n > 0)
        {
            n -= 1;
            if (plains[i].go < plains[plainNum].come)
            {
                n += 1;
            }
        }
    }
    if (n > 0)
    {
        return true;
    }
    return false;
}

int tryCome(int cnN, int m1, int m2)
// 按照此方法进入的飞机数量
/*
cnN: 国内廊桥数
m: 飞机数量(国内、国际)
 */
{
    // 国内停机数
    for (int i = 0; i < m1; i++)
    {
        if (canIn(m1, i, cn))
        {
        }
    }
}

int main()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    for (int i = 0; i < m1; i++)
    {
        cin >> cn[i].come >> cn[i].go;
    }
    for (int i = 0; i < m2; i++)
    {
        cin >> abroad[i].come >> abroad[i].go;
    }
    return 0;
}
