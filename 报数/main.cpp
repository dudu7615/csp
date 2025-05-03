#include <bits/stdc++.h>

using namespace std;

void get7(int maxn, vector<int> &has7)
{

    for (int i = 1; i <= maxn; i++)
    {
        // 7的倍数
        if (i % 7 == 0)
        {
            has7.push_back(i);
            continue;
        }

        // 含有7
        int in7 = i;
        while(in7){
            if(in7%10==7){
                has7.push_back(i);
            }
            in7/=10;
        }
        // string str = to_string(i);
        // for (int j = 0; j < 7; j++)
        // {
        //     if (str[j] == '7')
        //     {
        //         has7.push_back(i);
        //         break;
        //     }
        // }
    }

    
    sort(has7.begin(),has7.end());
}

bool in7(int x, vector<int> &has7)
{
    for (int &i : has7)
    {
        if (i > x)
        {
            return false;
        }
        if ((i!=0)&&(x % i == 0))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int T;
    int maxn = 0;
    scanf("%d", &T);
    vector<int> x(T);
    vector<int> has7(T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &x[i]);
        if (x[i] > maxn)
        {
            maxn = x[i];
        }
    }
    get7(maxn, has7);

    for (int i = 0; i < T; i++)
    {
        if (in7(x[i], has7))
        {
            printf("-1\n");
        }
        else
        {
            for (int j = x[i]+1; j < 1e8; j++)
            {
                if (in7(j, has7))
                {
                    continue;
                }
                else
                {
                    printf("%d\n", j);
                    break;
                }
            }
        }
    }
}