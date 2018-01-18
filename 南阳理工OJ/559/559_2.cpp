#include<iostream>
using namespace std;

typedef long long LL;

int main()
{
    int T;
    cin >>  T;
    while(T--)
    {
        LL h,day;
        cin >> h;
        if(h <= 10) day = 1;
        else
        {
            day = (h - 5) / 5;
            if(h % 5 != 0) day += 1;
        }
        cout << day << endl;
    }
    return 0;
}
