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
    int k,l,m,n,d;
    while(scanf("%d%d%d%d%d",&k,&l,&m,&n,&d) ==  5)
    {
        memset(a,0,sizeof(a));
        for(int i = 1; i <= d; i++)
        {
            if(i % k == 0) a[i] = 1;
            if(i % l == 0) a[i] = 1;
            if(i % m == 0) a[i] = 1;
            if(i % n == 0) a[i] = 1;
        }
        int num = 0;
        for(int i = 1; i <= d; i++)
            if(a[i]) num++;
        printf("%d\n",num);
    }
    return 0;
}
