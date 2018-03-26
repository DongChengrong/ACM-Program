#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

int main()
{
    int n;
    while(cin >> n)
    {
        int num = 0;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            num += x;
        }
        double ans = (double)(num) / (1.00 * n);
        printf("%.12lf\n",ans);
    }
    return 0;
}
