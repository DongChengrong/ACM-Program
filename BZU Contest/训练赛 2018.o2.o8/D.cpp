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
    LL k2,k3,k5,k6;
    while(cin >> k2 >> k3 >> k5 >> k6)
    {
        LL sum = 0;
        LL MIN = min(k2,k5); MIN = min(MIN,k6);
        k2 -= MIN;
        sum = MIN * 256;
        MIN = min(k3, k2);
        sum += 32 * MIN;
        cout << sum << endl;
    }
    return 0;
}
