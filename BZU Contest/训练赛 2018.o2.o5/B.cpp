#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

double a[maxn];

int main()
{
    int n,l;
    while(cin >> n >> l)
    {
        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a,a+n);
        double MIN = max(a[0],l - a[n - 1]);
        for(int i = 1; i < n ; i++)
            MIN = max(MIN,(a[i] - a[i - 1]) / 2 );
        printf("%.10lf\n",MIN);
    }
    return 0;
}
