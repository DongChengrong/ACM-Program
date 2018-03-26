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
    int x,n,c = 0,m = 0 ;
    for(int i = 0; i < 3; i++)
    {
        scanf("%d",&x);
        c += x;
    }
    for(int i = 0; i < 3; i++)
    {
        scanf("%d",&x);
        m += x;
    }
    scanf("%d",&n);
    x = (c + 4) / 5;
    x += (m + 9) / 10;
    if(x <= n) printf("YES\n");
    else printf("NO\n");
    return 0;
}
