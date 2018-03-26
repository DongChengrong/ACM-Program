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
    int a,b,c;
    while(cin >> a >> b >> c)
    {
        int MIN = min(a,b); MIN = min(MIN,c);
        int ans = MIN;
        a -= MIN; b -= MIN; c -= MIN;

    }
    return 0;
}
