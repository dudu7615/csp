#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;

int locks[maxn][5]; // lock组合号 数字
int nums[maxn][5];  // lock号 数字
int result = 0;

void getLocks(int n)
{
    int lockNum = 0;
    for (int a = 0; a < 10; a++)
    {
        for (int b = 0; b < 10; b++)
        {
            for (int c = 0; c < 10; c++)
            {
                for (int d = 0; d < 10; d++)
                {
                    for (int e = 0; e < 10; e++)
                    {

                        locks[lockNum][0] = a;
                        locks[lockNum][1] = b;
                        locks[lockNum][2] = c;
                        locks[lockNum][3] = d;
                        locks[lockNum][4] = e;
                        lockNum += 1;
                    }
                }
            }
        }
    }
}

bool canChangeTo(int k, int n)
{
    int sum = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        // 一位
        for (int j = 0; j < 5; j++)
        {
            for (int m = 0; m < 10; m += 1)
            {
                if (((locks[k][j] + m) % 10 == nums[i][j]) &&
                    ((locks[k][(j + 1) % 5]) == nums[i][(j + 1) % 5]) &&
                    ((locks[k][(j + 2) % 5]) == nums[i][(j + 2) % 5]) &&
                    ((locks[k][(j + 3) % 5]) == nums[i][(j + 3) % 5]) &&
                    ((locks[k][(j + 4) % 5]) == nums[i][(j + 4) % 5]))
                {
                    sum += 1;

                }
            }
        }

        // 二位
        for (int j = 0; j < 5; j++)
        {
            for (int m = 0; m < 10; m += 1)
            {
                if (((locks[k][j] + m) % 10 == nums[i][j]) &&
                    ((locks[k][(j + 1)] + m) % 10 == nums[i][(j + 1)]) &&
                    ((locks[k][(j + 2) % 5]) == nums[i][(j + 2) % 5]) &&
                    ((locks[k][(j + 3) % 5]) == nums[i][(j + 3) % 5]) &&
                    ((locks[k][(j + 4) % 5]) == nums[i][(j + 4) % 5]) &&
                    j + 1 < 5)
                {
                    sum2 += 1;

                }
            }
        }
    }
    if ((sum+sum2) == n)
    {
        return true;
    }
    return false;
}

void getResults(int n)
{
    for (int k = 0; k < maxn; k++) // nums序号
    {
        if (canChangeTo(k, n))
        {
            result += 1;
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