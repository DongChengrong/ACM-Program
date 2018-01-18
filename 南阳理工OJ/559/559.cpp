#include<stdio.h>
#include<iostream>
using namespace std;

typedef long long LL;

LL slove(LL h)
{
    int day = 1, m = 10;
    while(m < h)
    {
        day += 1;
        m += 5;
    }
    return day;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        LL h,day;
        cin >> h;
        day = slove(h);
        cout << day << endl;
    }
    return 0;
}
