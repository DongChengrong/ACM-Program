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
            int p,q;
            cin >> p >> q;
            if(q - p >= 2) num++;
        }
        cout << num << endl;
    }
    return 0;
}
