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
        int num = 0;
        while(n--)
        {
            int x, cnt = 0;
            for(int i = 0; i < 3; i++)
            {
                scanf("%d",&x);
                if(x) cnt++;
            }
            if(cnt >= 2) num++;
        }
        printf("%d\n",num);
    }
    return 0;
}