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
    int k,r;
    while(cin >> k >> r)
    {
        int i, cost =  k;
        for(i = 1; ; i++)
        {
            if(cost % 10 == r || cost % 10 == 0) break;
            cost += k;
        }
        cout << i << endl;
    }
    return 0;
}
