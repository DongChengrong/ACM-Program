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
    int n,m;
    while(cin >> n >> m)
    {
        int i;
        if(n > m)
        {
            printf("0\n");
            continue;
        }
        for(i = 1; ; i++)
        {
            n = 3 * n; m = 2 * m;
            if(n > m) break;
        }
        printf("%d\n",i);
    }
    return 0;
}
