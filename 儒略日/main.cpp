// The mountain of SHIT

#include <bits/stdc++.h>
using namespace std;

int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date
{
    int year, month, day;
};

bool isR(int year)
{
    // 润年
    if (year % 100 == 0)
    {
        if (year % 400 == 0)
        {
            return true;
        }
    }
    else
    {
        if (year % 4 == 0)
        {
            return true;
        }
    }
    return false;
}

Date get(int afterDays)
{
    // int year = 4713;
    Date today = {4713, 1, 1};
    if (afterDays > 0)
    {

        // 年
        while (true)
        {
            if (isR(today.year))
            {
                if (afterDays >= 366)
                {
                    afterDays -= 366;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (afterDays >= 365)
                {
                    afterDays -= 365;
                }
                else
                {
                    break;
                }
            }
            today.year += 1;
        }

        // 月

        for (int i = 0; i < 12; i++)
        {
            if (i == 1)
            {
                if (isR(today.year))
                {
                    if (afterDays >= 29)
                    {
                        afterDays -= 29;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if (afterDays >= 28)
                    {
                        afterDays -= 28;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                if (afterDays >= months[i])
                {
                    afterDays -= months[i];
                }
                else
                {
                    break;
                }
            }
            today.month += 1;
        }

        // 日
        today.day += afterDays;
    }

    // 1743以前
    else if (afterDays < 0)
    {
        Date today = {4712, 12, 31}; // 反向记年
        // 年
        while (true)
        {
            if (isR(today.year))
            {
                if (afterDays <= -366)
                {
                    afterDays += 366;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (afterDays <= -365)
                {
                    afterDays += 365;
                }
                else
                {
                    break;
                }
            }
            today.year -= 1;
        }

        // 月
        for (int i = 0; i < 12; i++)
        {
            if (i == 1)
            {
                if (isR(today.year))
                {
                    if (afterDays <= -29)
                    {
                        afterDays += 29;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if (afterDays >= -28)
                    {
                        afterDays += 28;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                if (afterDays >= -months[i])
                {
                    afterDays += months[i];
                }
                else
                {
                    break;
                }
            }
            today.month -= 1;
        }

        // 日
        today.day = -afterDays;
    }
    return today;
}

int main()
{
    int Q;

    scanf("%d", &Q);
    vector<int> r(Q);
    
    for (int i = 0; i < Q; i++)
    {
        int ri;
        scanf("%d", &ri);
        r[i] = (ri);
    }
    for (int &afterDays : r)
    {
        Date date = get(afterDays);
        if (date.year >= 4713)
        {
            printf("%d %d %d\n", date.day, date.month, date.year);
        }
        else
        {
            printf("%d %d %d BC\n", date.day, date.month, date.year);
        }
    }
}