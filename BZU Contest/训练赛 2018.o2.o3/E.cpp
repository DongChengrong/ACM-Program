#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef unsigned long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

int main()
{
    LL k,n,w;
    while(cin >> k >> n >> w)
    {
        LL cost = 0;
        for(int i = 1; i <= w; i++)
            cost += i * k;
        int bro = cost - n;
        printf("%d\n", bro <= 0 ? 0 : bro);
    }
    return 0;
}
