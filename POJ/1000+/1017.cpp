#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

int a[10];
const int b[] = {0,5,3,1};

int main()
{
    while(1)
    {
        int flag = 0;
        for(int i = 1; i <= 6; i++)
        {
            scanf("%d",&a[i]);
            flag += a[i];
        }

        if(!flag) break;

        int total = 0;
        for(int i = 6; i >= 4; i--)
            total += a[i];

        total += (a[3] + 3) / 4;
        int c2 = a[4] * 5;
        c2 += b[a[3] % 4];

        if(a[2] > c2) total += (a[2] - c2 + 8) / 9;
        int c1 = total * 36;
        for(int i = 6; i >= 2; i--)
            c1 -= (i * i) * a[i];
        if(a[1] > c1) total += (a[1] - c1 + 35) / 36;

        printf("%d\n",total);
    }
    return 0;
}
