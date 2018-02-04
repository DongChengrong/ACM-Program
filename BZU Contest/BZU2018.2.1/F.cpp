#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<sstream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

int a[maxn];

int main()
{
    string s;
    while(cin >> s)
    {
        int n = 0;
        stringstream ss(s);
        while(ss >> a[n]) n++;
        sort(a,a+ n);
        for(int i = 0; i < n - 1; i++)
            printf("%d+",a[i]);
        printf("%d\n",a[n - 1]);
    }
    return 0;
}
