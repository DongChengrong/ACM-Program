#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

struct Node
{
    int x,y;
}a[maxn];

int cmp(Node x, Node y)
{
    return x.x < y.x;
}

int main()
{
    int s,n;
    while(scanf("%d%d",&s,&n) == 2)
    {
        for(int i = 0; i < n; i++)
            scanf("%d%d",&a[i].x,&a[i].y);

        int i;
        sort(a,a+n,cmp);
        for(i = 0; i < n; i++)
        {
            if(a[i].x >= s) break;
            else s += a[i].y;
        }
        if(i < n) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
