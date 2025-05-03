#include <bits/stdc++.h>
#define mian main

using namespace std;

vector<int> getS(int n)
{
    vector<int> result;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j < n; j++)
        {
            if (i % j == 0 && i != j)
            {
                break;
            }
            if (j == i)
            {
                result.push_back(i);
            }
        }
    }
    return result;
}

vector<int> getSums(vector<int> nums, int k)
{
    vector<int> sums,result;
    vector<vector<int>> usedNums_((pow(nums.size(), 3)), vector<int>(3));
    vector<vector<int>> usedNums;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (i == 0)
            {
                usedNums_[j][i] = nums[j];
            }
            else
            {
                if ((usedNums_[j][0] == nums[j]) || (usedNums_[j][1] == nums[j]))
                {
                    continue;
                }
                else
                {
                    usedNums_[j][i] = nums[j];
                }
            }
        }
    }
    for (vector<int> &num : usedNums_)
    {
        if(num[0]!=num[1]!=num[2]){
            usedNums.push_back(num);
        }
    }
    for (vector<int> num:usedNums)
    {
        sums.push_back(num[0] + num[1] + num[2]);
    }
    int maxSum = 0;
    for(int sum:sums)
    {
        if(sum>maxSum)
        {
            maxSum = sum;
        }
    }
    vector<int> s = getS(maxSum);
    sort(sums.begin(), sums.end());
    sort(s.begin(), s.end());
    for(int sum:sums)
    {
        for(int si:s)
        {
            if(si==sum)
            {
                result.push_back(sum);
            }
        }
    }
    return result;
}

int mian()
{
    int n, k;
    vector<int> nums;
    scanf("%d%d", &n, &k);
    int ni;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ni);
        nums.push_back(ni);
    }
    printf("%d",getSums(nums, k).size());
    return 0;
}