#include <bits/stdc++.h>
using namespace std;

int getMin(vector<int> &nums)
{
    int min = INT_MAX;
    for (int num : nums)
        if (num < min)
            min = num;
    return min;
}

int getMax(vector<int> &nums)
{
    int max = INT_MIN;
    for (int num : nums)
        if (num > max)
            max = num;
    return max;
}

vector<int> getNums(string str, int m)
{
    vector<int> nums(m, 0);
    for (int i = 0; i < m; i++)
    {
        nums[i] = str[i] - 'a';
    }
    return nums;
}

vector<int> getResult(vector<string> &words, int n, int m)
{
    vector<int> result(n, 0);
    vector<int> maxs(n, 0);
    vector<int> mins(n, 0);
    vector<vector<int>> nums(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        nums[i] = getNums(words[i], m);
    }
    for (int i = 0; i < n; i++)
    {
        maxs[i] = getMax(nums[i]);
        mins[i] = getMin(nums[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && mins[i] >= maxs[j])
            {
                goto next;
            }
        }
        result[i] = 1;
    next:
        continue;
    }

    return result;
}

int main()
{
    freopen("in", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<string> words(n, string(m, ' '));
    for (string &word : words)
        cin >> word;

    vector<int> result = getResult(words, n, m);
    for (int r : result)
        cout << r;
    cout << endl;

    return 0;
}