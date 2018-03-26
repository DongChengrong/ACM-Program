#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

int a[maxn];

int main()
{
    int n;
    while(cin >> n)
    {
        memset(a,0,sizeof(a));
        for(int i = 0; i < 2; i++)
        {
            int x;
            cin >> x;
            while(x--)
            {
                int y;
                cin >> y;
                a[y] = 1;
            }
        }

        int ok = 1;
        for(int i = 1; i <= n; i++)
            if(!a[i])
            {
                ok = 0; break;
            }

        if(ok) printf("I become the guy.\n");
        else printf("Oh, my keyboard!\n");

    }
    return 0;
}
