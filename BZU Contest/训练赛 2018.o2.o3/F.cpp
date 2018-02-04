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
    while(scanf("%d",&n) == 1)
    {
        int x, y, z;
        x = y = z = 0;
        while(n--)
        {
            int x1,y1,z1;
            scanf("%d %d %d",&x1,&y1,&z1);
            x += x1; y += y1; z += z1;
        }
        printf("%s\n",x == y && y == z && z == 0 ? "YES" : "NO");
    }
    return 0;
}
