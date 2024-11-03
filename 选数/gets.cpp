#include <bits/stdc++.h>
#define mian main

using namespace std;

vector<int> getS(int n)
{
    // vector<int> nums;
    vector<int> result;
    for (int i = 2; i <= n;i++)
    {
        for (int j = 2;j<n;j++)
        {
            if (i % j == 0 && i != j)
            {
                break;
            }
            if(j==i)
            {
                result.push_back(i);
            }
        }
    }
        return result;
}
int main()
{
    cout << getS(100).size();
    for (int s : getS(100))
    {
        cout << s <<" ";
    }
    return 0;
}