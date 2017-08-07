#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string Haab_Month[] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet" };
string Holly_Month[] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };
int main()
{
    int n, day, year;
    string month;
    cin >> n;
    cout << n << endl;
    while (n--)
    {
        scanf("%d.", &day);
        cin >> month >> year;
        int i, sum = 0;
        for (i = 0; i < 19; i++)
        {
            if (Haab_Month[i] == month)
                break;
        }
        sum = (year * 365) + (i * 20) + day;
        year = sum / 260;
        month = Holly_Month[sum% 20];
        day = sum % 13 + 1;
        cout << day << " " << month << " " << year << endl;
    }
    return 0;
}
