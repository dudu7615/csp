#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3;

int locks[maxn][maxn][5]; // muns组合号 lock组合号 数字
int nums[maxn][5];        // lock号 数字
int result = 0;

void getLocks(int n)
{
    int newLockNum;
    for (int i = 0; i < n; i++) // i: 组合号
    {
        newLockNum = 0;
        // 初始化新锁=原锁
        for (int k = 0; k < maxn; k++)
        {
            for (int j = 0; j < 5; j++)
            {
                locks[i][k][j] = (nums[i][j]);
            }
        }
        // 只转一个
        for (int j = 0; j < 5; j++) // j: 数字号
        {
            for (int k = 0; k < 9; k++) // 增量
            {
                locks[i][newLockNum][j] = (nums[i][j] + k) % 10;
                // cout<<locks[i][newLockNum][j];
                newLockNum += 1;
                // for (int a = 0; a < 5; a++)
                // {
                //     cout << locks[i][newLockNum][a];
                // }
                // cout << endl;
            }
        }
        // 转两个
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 9; k++)
            {
                locks[i][newLockNum][j] = (nums[i][j] + k) % 10;
                locks[i][newLockNum][j + 1] = (nums[i][j + 1] + k) % 10;
                newLockNum += 1;
                // for (int a = 0; a < 5; a++)
                // {
                //     cout << locks[i][newLockNum][a];
                // }
                // cout << endl;
            }
        }
    }
}

bool is(int a[], int b[])
{
    for (int i = 0; i < 5; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}
bool isUsed(int a[])
{
    for (int i = 0; i < 5; i++)
    {
        if (a[i] != 0)
        {
            return true;
        }
    }
    return false;
}
void getResults(int n)
{
    if (n == 1)
    {
        result = 81;
    }
    else
    {
        for (int i1 = 0; i1 < maxn; i1++)
        {
            for (int i2 = i1 + 1; i2 < maxn; i2++)
            {
                for (int j = 0; j < maxn; j++)
                {
                    if (isUsed(locks[i1][j]) && isUsed(locks[i2][j]))
                    {
                        if (is(locks[i1][j], locks[i2][j]))
                        {
                            result += 1;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> nums[i][j];
        }
    }

    getLocks(n);
    getResults(n);
    cout << result << endl;
    return 0;
}