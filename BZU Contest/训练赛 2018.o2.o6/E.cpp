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
        n = min(n,m);
        if(n & 1) printf("Akshat\n");
        else printf("Malvika\n");
    }
    return 0;
}
