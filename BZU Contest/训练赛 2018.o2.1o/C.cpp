#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

int main()
{
    int n;
    while(cin >> n)
    {
        int a1 = 0,a2 = 0,b1,b2;
        for(int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if(x & 1) { a1++; b1 = i;}
            else { a2++; b2 = i; }
        }

        if(a1 == 1) cout << b1 << endl;
        else cout << b2 << endl;
    }
    return 0;
}
