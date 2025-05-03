#include <bits/stdc++.h>
using namespace std;

struct Time
{
    int come, go;
    bool operator<(const Time &other) const
    {
        return come < other.come;
    }
};

int getCanIns(int n, vector<Time> &plains)
{
    vector<int> bridges(n, 0); // 每个廊桥的离开时间
    int inNum = 0;
    for (Time &plain : plains)
    {
        for (int i = 0; i < n; i++)
        {
            if (bridges[i] <= plain.come)
            {
                bridges[i] = plain.go;
                inNum++;
                break;
            }
        }
    }
    return inNum;
}

int main()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<Time> cn(m1), abroad(m2);
    for (int i = 0; i < m1; i++)
    {
        cin >> cn[i].come >> cn[i].go;
    }
    for (int i = 0; i < m2; i++)
    {
        cin >> abroad[i].come >> abroad[i].go;
    }

    sort(cn.begin(), cn.end());
    sort(abroad.begin(), abroad.end());

    int maxNum = 0;
    for (int i = 0; i <= n; i++)
    { // i: 国内廊桥数
        int cnCount = getCanIns(i, cn);
        int abrCount = getCanIns(n - i, abroad);
        maxNum = max(maxNum, cnCount + abrCount);
    }

    cout << maxNum << endl;
    return 0;
}