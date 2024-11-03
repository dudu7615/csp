#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;

bool hasSame(vector<int> &a)
{
    for (int i = 0; i <= a.size(); i++)
    {
        for (int j = i; j < a.size(); j++)
        {
            if (a[i] == a[j])
            {
                return true;
            }
        }
    }
    return false;
}

vector<int> cut(vector<vector<int>> cuts)
{
    if(hasSame(cuts[0])){

    }
}

string make(int n, vector<int> &a)
{
    // 4531221354
    vector<vector<int>> cuts;
    cuts = {a, {}};
    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        int cut = a[i];
        int cutNum;
        // 切分点
        for (int j = a.size() - 1; j >= 0; j--)
        {
            if (a[j] == cut)
            {
                cutNum = j;
                break;
            }
        }
        // 切分
        for (int j = 0; j < cutNum; j++)
        {
            cuts[0].push_back(a[j]);
        }
        for (int j = cutNum; j < a.size() - 1; j++)
        {
            cuts[0].push_back(a[j]);
        }
    }
}

int main()
{
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    int n, T;
    scanf("%d", &T);
    vector<vector<int>> a(T);

    for (int i; i < T; i++)
    {
        scanf("%d", &n);
        for (int j = 0; j < 2 * n; j++)
        {
            int ai;
            scanf("%d", &ai);
            a[i].push_back(ai);
        }
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}