#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef unsigned long long LL;

const int maxn = 12 + 10;
int a[maxn],A[maxn];

const LL one[] = {0,1,11,111,1111,11111,111111,1111111,11111111,111111111,1111111111,11111111111,111111111111,1111111111111};
LL f[30];

void init()
{
    f[0] = f[1] = 1;
    for(int i = 2; i <= 13; i++)
        f[i] = f[i - 1] * i;
}

int main()
{
    int n;
    init();
    ios::sync_with_stdio(false);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while(cin >> n && n)
    {
        int x,m = 0;
        LL sum = 0;
        memset(a,0,sizeof(a));
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            a[x]++;
            sum += x;
        }

        LL ans = sum * f[n - 1];
        for(int i = 0; i <= 9; i++)
            ans /= f[a[i]];
        ans *= one[n];

        cout << ans << endl;
    }
    return 0;
}
