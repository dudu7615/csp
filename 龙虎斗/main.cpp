#include <bits/stdc++.h>
#define ci cin >>
#define co cout <<
using namespace std;
using ll = long long;

struct Gread
{
    ll l, r;
};

Gread getGread(vector<ll> &c, ll m)
{
    ll sumL = 0, sumR = 0;
    for (ll i = 0; i < m; i++)
    {
        sumL += c[i] * (m - i);
    }
    for (ll i = m + 1; i < c.size(); i++)
    {
        sumR += c[i] * (i -m );
    }
    return {sumL, sumR};
}

ll tryP2(vector<ll> &c, Gread &g, int m, ll s2)
{
    ll diff = g.l - g.r;
    ll p2=m, add = abs(diff);
    if (diff == 0)
        return m;
    if (diff > 0) // 左边大
    {
        for (ll i = m; i < c.size(); i++)
        {
            ll add_ = s2 * (i - m);
            if (abs(diff - add_) < add)
            {
                add = abs(diff - add_);
                p2 = i;
            }
        }
    }
    else // 右边大
    {
        for (ll i = 0; i < m; i++)
        {
            ll add_ = s2 * (m - i);
            if (abs(diff + add_) < add)
            {
                add = abs(diff + add_);
                p2 = i;
            }
        }
    }
    return p2;
}

int main() {
    iostream::sync_with_stdio(false);
    freopen("in", "r", stdin);
    ll n;
    ll m, p1, s1, s2;
    ci n;
    vector<ll> c(n);
    for (ll &i : c)
        ci i;
    ci m >> p1 >> s1 >> s2;
    m--;// 0-based
    c[p1 - 1] += s1;
    Gread g = getGread(c, m);
    ll p2 = tryP2(c, g, m, s2);
    co p2+1 << endl;

    return 0;
}
