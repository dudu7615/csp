#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool cmp(string a, string b)
{
    return a > b;
}

void getStrs(ll &n, vector<string> &strs)
{
    vector<string> res; // 左，又
    ll beginN = n;
    if (n > 1)
    {
        for (int i = 0; i < strs.size(); i++)
        {
            res.push_back("0" + strs[i]);
            res.push_back("1" + strs[i]);
        }
        n -= 1;
    }
    if (beginN > 1)
    {
        strs.clear();
    }
    for (string &str : res)
    {
        strs.push_back(str);
    }

    if (n > 1)
    {
        getStrs(n, strs);
    }
    // result = lf+ri;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<string> strs = {"0", "1"}; // 一位
    vector<string> result;
    // string str = "0 1";
    getStrs(n, strs);

    auto mid = strs.begin() + strs.size() / 2;
    sort(strs.begin(), strs.end());
    sort(mid, strs.end(), cmp);
    
    cout << strs[k] << endl;
    return 0;
}